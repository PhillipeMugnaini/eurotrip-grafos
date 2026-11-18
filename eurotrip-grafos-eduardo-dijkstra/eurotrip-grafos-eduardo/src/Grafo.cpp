#include "Grafo.hpp"

#include <cmath>
#include <stdexcept>

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
// Primeiro: entender a base acima. Depois substituir cada TODO por codigo.

void Grafo::carregarCidades(const std::string& caminho) {
    (void)caminho;
    throw std::logic_error("TODO Lucas: ler data/cidades.csv e chamar adicionarCidade");
}

void Grafo::carregarRotas(const std::string& caminho) {
    (void)caminho;
    throw std::logic_error("TODO Lucas: ler data/rotas.csv e chamar adicionarRota");
}

bool Grafo::validar(std::string& mensagem) const {
    (void)mensagem;
    throw std::logic_error("TODO Lucas: validar grau >= 3 e conectividade");
}

void Grafo::imprimirCidades() const {
    throw std::logic_error("TODO Lucas: listar vertices e graus");
}

void Grafo::imprimirRotas() const {
    throw std::logic_error("TODO Lucas: listar arestas sem duplicacoes");
}

void Grafo::imprimirMatriz(Criterio criterio) const {
    (void)criterio;
    throw std::logic_error("TODO Lucas: construir matriz do peso escolhido");
}
