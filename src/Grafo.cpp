#include "Grafo.hpp"

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <queue>
#include <sstream>
#include <stdexcept>

namespace {

void removerRetornoDeCarro(std::string& linha) {
    if (!linha.empty() && linha.back() == '\r') {
        linha.pop_back();
    }
}

std::ifstream abrirCsv(const std::string& caminho, const std::string& tipo,
                       const std::string& cabecalhoEsperado) {
    std::ifstream arquivo(caminho);
    if (!arquivo) {
        throw std::runtime_error("Nao foi possivel abrir o CSV de " + tipo + ": " + caminho);
    }

    std::string cabecalho;
    if (!std::getline(arquivo, cabecalho)) {
        throw std::runtime_error(caminho + ": cabecalho ausente");
    }
    if (cabecalho.compare(0, 3, "\xEF\xBB\xBF") == 0) {
        cabecalho.erase(0, 3);
    }
    removerRetornoDeCarro(cabecalho);
    if (cabecalho != cabecalhoEsperado) {
        throw std::runtime_error(caminho + ": cabecalho invalido na linha 1");
    }
    return arquivo;
}

double lerPeso(const std::string& texto, const std::string& coluna) {
    std::istringstream entrada(texto);
    entrada.imbue(std::locale::classic());
    double peso;
    if (!(entrada >> peso)) {
        throw std::runtime_error("Valor invalido na coluna " + coluna + ": " + texto);
    }
    entrada >> std::ws;
    if (!entrada.eof()) {
        throw std::runtime_error("Valor invalido na coluna " + coluna + ": " + texto);
    }
    return peso;
}

}  // namespace

// ==== BASE COMPARTILHADA ====
// Essas operacoes minimas ja estao prontas para que Eduardo e Phillipe
// possam testar seus algoritmos sem esperar o carregamento dos CSVs.

void Grafo::adicionarCidade(const Cidade& nova) {
    if (nova.id.empty() || indice(nova.id) != -1) {
        throw std::runtime_error("ID de cidade vazio ou duplicado: " + nova.id);
    }
    cidades_.push_back(nova);
    adjacencias_.emplace_back();
}

void Grafo::adicionarRota(const std::string& origem, const std::string& destino,
                          double custo, double distancia, double tempo,
                          const std::string& transporte, const std::string& observacoes) {
    const int a = indice(origem);
    const int b = indice(destino);
    if (a == -1 || b == -1 || a == b)
        throw std::runtime_error("Cidade inexistente ou rota para a propria cidade.");
    if (!std::isfinite(custo) || !std::isfinite(distancia) || !std::isfinite(tempo) ||
        custo <= 0 || distancia <= 0 || tempo <= 0)
        throw std::runtime_error("Todos os pesos devem ser positivos e finitos.");
    for (const auto& aresta : adjacencias_[a]) {
        if (aresta.destino == b)
            throw std::runtime_error("Rota duplicada entre cidades.");
    }
    // Grafo nao direcionado: adiciona A->B e B->A.
    adjacencias_[a].push_back({b, custo, distancia, tempo, transporte, observacoes});
    adjacencias_[b].push_back({a, custo, distancia, tempo, transporte, observacoes});
}

int Grafo::indice(const std::string& id) const {
    for (int i = 0; i < static_cast<int>(cidades_.size()); ++i) {
        if (cidades_[i].id == id) return i;
    }
    return -1;
}

const Cidade& Grafo::cidade(int i) const { return cidades_.at(i); }
const std::vector<Aresta>& Grafo::vizinhos(int i) const { return adjacencias_.at(i); }
int Grafo::quantidadeCidades() const { return static_cast<int>(cidades_.size()); }

double pesoDaAresta(const Aresta& aresta, Criterio criterio) {
    if (criterio == Criterio::Custo) return aresta.custo;
    if (criterio == Criterio::Distancia) return aresta.distancia;
    return aresta.tempo;
}

std::string nomeCriterio(Criterio criterio) {
    if (criterio == Criterio::Custo) return "custo (R$)";
    if (criterio == Criterio::Distancia) return "distancia (km)";
    return "tempo (h)";
}

// ==== TAREFAS DO LUCAS ====

void Grafo::carregarCidades(const std::string& caminho) {
    std::ifstream arquivo = abrirCsv(caminho, "cidades", "id;pais;cidade;ponto_turistico");
    std::string linha;

    // Aplica as cidades ao grafo somente depois de ler o arquivo inteiro.
    Grafo atualizado = *this;
    int numeroLinha = 1;
    while (std::getline(arquivo, linha)) {
        ++numeroLinha;
        removerRetornoDeCarro(linha);
        if (linha.empty()) {
            continue;
        }

        std::istringstream campos(linha);
        Cidade nova;
        const std::string local = caminho + ": linha " + std::to_string(numeroLinha) + ": ";
        if (!std::getline(campos, nova.id, ';') ||
            !std::getline(campos, nova.pais, ';') ||
            !std::getline(campos, nova.nome, ';') ||
            !std::getline(campos, nova.pontoTuristico) ||
            nova.pais.empty() || nova.nome.empty() ||
            nova.pontoTuristico.find(';') != std::string::npos) {
            throw std::runtime_error(local + "esperados id, pais, cidade e ponto turistico");
        }

        try {
            atualizado.adicionarCidade(nova);
        } catch (const std::runtime_error& erro) {
            throw std::runtime_error(local + erro.what());
        }
    }
    if (!arquivo.eof() || arquivo.bad()) {
        throw std::runtime_error("Erro durante a leitura do CSV de cidades: " + caminho);
    }
    cidades_.swap(atualizado.cidades_);
    adjacencias_.swap(atualizado.adjacencias_);
}

void Grafo::carregarRotas(const std::string& caminho) {
    std::ifstream arquivo = abrirCsv(
        caminho, "rotas", "origem;destino;transporte;custo_brl;distancia_km;tempo_h;observacoes");

    // Se uma linha falhar, as rotas ja cadastradas no grafo ficam intactas.
    Grafo atualizado = *this;
    std::string linha;
    int numeroLinha = 1;
    while (std::getline(arquivo, linha)) {
        ++numeroLinha;
        removerRetornoDeCarro(linha);
        if (linha.empty()) {
            continue;
        }

        std::istringstream campos(linha);
        std::string origem, destino, transporte, custoTexto, distanciaTexto, tempoTexto, observacoes;
        const std::string local = caminho + ": linha " + std::to_string(numeroLinha) + ": ";
        if (!std::getline(campos, origem, ';') ||
            !std::getline(campos, destino, ';') ||
            !std::getline(campos, transporte, ';') ||
            !std::getline(campos, custoTexto, ';') ||
            !std::getline(campos, distanciaTexto, ';') ||
            !std::getline(campos, tempoTexto, ';') ||
            campos.eof() || transporte.empty()) {
            throw std::runtime_error(local + "esperadas as sete colunas com transporte informado");
        }

        std::getline(campos, observacoes);
        if (observacoes.find(';') != std::string::npos) {
            throw std::runtime_error(local + "mais de sete colunas");
        }

        try {
            const double custo = lerPeso(custoTexto, "custo_brl");
            const double distancia = lerPeso(distanciaTexto, "distancia_km");
            const double tempo = lerPeso(tempoTexto, "tempo_h");
            atualizado.adicionarRota(origem, destino, custo, distancia, tempo, transporte, observacoes);
        } catch (const std::runtime_error& erro) {
            throw std::runtime_error(local + erro.what());
        }
    }
    if (!arquivo.eof() || arquivo.bad()) {
        throw std::runtime_error("Erro durante a leitura do CSV de rotas: " + caminho);
    }
    adjacencias_.swap(atualizado.adjacencias_);
}

bool Grafo::validar(std::string& mensagem) const {
    const int total = quantidadeCidades();
    if (total == 0) {
        mensagem = "O grafo nao tem cidades.";
        return false;
    }

    for (int i = 0; i < total; ++i) {
        const auto grau = vizinhos(i).size();
        if (grau < 3) {
            mensagem = "A cidade " + cidade(i).nome + " (" + cidade(i).id + ") tem grau " +
                       std::to_string(grau) + ". O minimo exigido e 3.";
            return false;
        }
    }

    std::vector<bool> visitadas(total, false);
    std::queue<int> fila;
    visitadas[0] = true;
    fila.push(0);
    int alcancadas = 0;

    while (!fila.empty()) {
        const int atual = fila.front();
        fila.pop();
        ++alcancadas;

        for (const Aresta& aresta : vizinhos(atual)) {
            if (!visitadas[aresta.destino]) {
                visitadas[aresta.destino] = true;
                fila.push(aresta.destino);
            }
        }
    }

    if (alcancadas != total) {
        mensagem = "Grafo desconexo: a partir de " + cidade(0).nome + ", foram alcancadas " +
                   std::to_string(alcancadas) + " de " + std::to_string(total) + " cidades.";
        return false;
    }

    mensagem = "Grafo conexo. Todas as cidades tem grau minimo de 3.";
    return true;
}

void Grafo::imprimirCidades() const {
    const int total = quantidadeCidades();
    if (total == 0) {
        std::cout << "Nenhuma cidade cadastrada.\n";
        return;
    }

    std::cout << "Cidades cadastradas (" << total << ")\n";
    for (int i = 0; i < total; ++i) {
        const Cidade& atual = cidade(i);
        std::cout << atual.id << " | " << atual.nome << " (" << atual.pais << ")"
                  << " | Ponto turistico: " << atual.pontoTuristico
                  << " | Grau: " << vizinhos(i).size() << '\n';
    }
}

void Grafo::imprimirRotas() const {
    std::ostringstream saida;
    int totalRotas = 0;
    for (int origem = 0; origem < quantidadeCidades(); ++origem) {
        for (const Aresta& aresta : vizinhos(origem)) {
            // Cada rota aparece nas duas listas de adjacencia.
            if (origem >= aresta.destino) {
                continue;
            }

            const Cidade& partida = cidade(origem);
            const Cidade& chegada = cidade(aresta.destino);
            saida << partida.nome << " (" << partida.id << ") <-> "
                  << chegada.nome << " (" << chegada.id << ")"
                  << " | " << aresta.transporte
                  << " | R$ " << std::fixed << std::setprecision(2) << aresta.custo
                  << std::defaultfloat << std::setprecision(10)
                  << " | " << aresta.distancia << " km"
                  << " | " << aresta.tempo << " h\n";
            ++totalRotas;
        }
    }

    if (totalRotas == 0) {
        std::cout << "Nenhuma rota cadastrada.\n";
        return;
    }
    std::cout << "Rotas cadastradas (" << totalRotas << ")\n" << saida.str();
}

void Grafo::imprimirMatriz(Criterio criterio) const {
    const int total = quantidadeCidades();
    if (total == 0) {
        std::cout << "Nenhuma cidade cadastrada.\n";
        return;
    }

    const double semLigacao = std::numeric_limits<double>::infinity();
    std::vector<std::vector<double>> matriz(total, std::vector<double>(total, semLigacao));
    for (int origem = 0; origem < total; ++origem) {
        matriz[origem][origem] = 0;
        for (const Aresta& aresta : vizinhos(origem)) {
            matriz[origem][aresta.destino] = pesoDaAresta(aresta, criterio);
        }
    }

    constexpr int largura = 11;
    std::ostringstream saida;
    saida << "Matriz de " << nomeCriterio(criterio) << '\n';
    if (criterio == Criterio::Custo) {
        saida << std::fixed << std::setprecision(2);
    } else {
        saida << std::setprecision(10);
    }

    saida << std::setw(largura) << "";
    for (int destino = 0; destino < total; ++destino) {
        saida << ' ' << std::setw(largura) << cidade(destino).id;
    }
    saida << '\n';

    for (int origem = 0; origem < total; ++origem) {
        saida << std::setw(largura) << cidade(origem).id;
        for (double peso : matriz[origem]) {
            saida << ' ' << std::setw(largura);
            if (peso == semLigacao) {
                saida << '-';
            } else {
                saida << peso;
            }
        }
        saida << '\n';
    }
    std::cout << saida.str();
}
