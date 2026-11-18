
#include "Prim.hpp"
#include <iostream>
#include <iomanip>
#include <queue>
#include <stdexcept>
#include <vector>

// Encontra a Arvore Geradora Minima pelo custo financeiro.
ResultadoAGM prim(const Grafo& grafo, int origem) {
    ResultadoAGM resultado;

    int quantidade = grafo.quantidadeCidades();

    // Grafo vazio.
    if (quantidade == 0) {
        return resultado;
    }

    // Verifica se a origem existe.
    if (origem < 0 || origem >= quantidade) {
        throw std::out_of_range("Indice de origem invalido");
    }

    // Controla as cidades que ja entraram na AGM.
    std::vector<bool> visitado(quantidade, false);

    // A fila de prioridade coloca o menor custo no topo.
    auto comparar = [](const RotaAGM& a, const RotaAGM& b) {
        return a.custo > b.custo;
    };

    std::priority_queue<
        RotaAGM,
        std::vector<RotaAGM>,
        decltype(comparar)
    > fila(comparar);

    // Adiciona as rotas candidatas de uma cidade.
    auto adicionarRotas = [&](int cidadeAtual) {
        for (const Aresta& aresta : grafo.vizinhos(cidadeAtual)) {
            if (!visitado[aresta.destino]) {
                fila.push({
                    cidadeAtual,
                    aresta.destino,
                    aresta.custo,
                    aresta.distancia,
                    aresta.tempo
                });
            }
        }
    };

    // Inicializa a AGM pela cidade de origem.
    visitado[origem] = true;
    int totalVisitados = 1;

    adicionarRotas(origem);

    // Expande a AGM escolhendo sempre o menor custo.
    while (!fila.empty() && totalVisitados < quantidade) {
        RotaAGM rota = fila.top();
        fila.pop();

        // Evita ciclos.
        if (visitado[rota.destino]) {
            continue;
        }

        // Adiciona a nova cidade a AGM.
        visitado[rota.destino] = true;
        totalVisitados++;

        // Registra a rota selecionada.
        resultado.rotas.push_back(rota);

        // Acumula os tres pesos.
        resultado.custoTotal += rota.custo;
        resultado.distanciaTotal += rota.distancia;
        resultado.tempoTotal += rota.tempo;

        // Explora as conexoes da nova cidade.
        adicionarRotas(rota.destino);
    }

    // A AGM so esta completa se alcancou todas as cidades.
    resultado.completa = (totalVisitados == quantidade);

    return resultado;
}


void imprimirAGM(const Grafo& grafo, const ResultadoAGM& resultado) {
    std::cout << "\n========== ARVORE GERADORA MINIMA ==========\n";

    std::cout << "Criterio: Menor custo financeiro\n";

    if (grafo.quantidadeCidades() == 0) {
        std::cout << "O grafo nao possui cidades.\n";
        return;
    }

    if (resultado.rotas.empty()) {
        std::cout << "\nNenhuma conexao selecionada.\n";
    } else {
        std::cout << "\nConexoes selecionadas:\n";

        int numeroRota = 1;

        for (const RotaAGM& rota : resultado.rotas) {

            const Cidade& origem = grafo.cidade(rota.origem);
            const Cidade& destino = grafo.cidade(rota.destino);

            std::cout << "\n" << numeroRota << ". "
                      << origem.nome << " -> "
                      << destino.nome << "\n";

            std::cout << std::fixed << std::setprecision(2);

            std::cout << "   Custo: R$ "
                      << rota.custo << "\n";

            std::cout << "   Distancia: "
                      << rota.distancia << " km\n";

            std::cout << "   Tempo: "
                      << rota.tempo << " horas\n";

            numeroRota++;
        }
    }

    std::cout << "\n========== TOTAIS ==========\n";

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Custo total: R$ "
              << resultado.custoTotal << "\n";

    std::cout << "Distancia total: "
              << resultado.distanciaTotal << " km\n";

    std::cout << "Tempo total: "
              << resultado.tempoTotal << " horas\n";

    std::cout << "\nAGM completa: "
              << (resultado.completa ? "Sim" : "Nao")
              << "\n";

    if (!resultado.completa) {
        std::cout << "Aviso: Nem todas as cidades foram conectadas.\n";
    }
}
