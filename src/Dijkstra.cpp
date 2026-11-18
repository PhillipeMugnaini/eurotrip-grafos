#include "Dijkstra.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <stdexcept>
#include <string>
#include <utility>

namespace {
constexpr double INFINITO = std::numeric_limits<double>::infinity();
constexpr double EPSILON = 1e-12;

void validarIndice(const Grafo& grafo, int indice, const char* papel) {
    if (indice < 0 || indice >= grafo.quantidadeCidades()) {
        throw std::out_of_range(std::string("Indice de ") + papel + " invalido.");
    }
}

// Procura a aresta direta entre dois vertices. O grafo do projeto e nao direcionado.
const Aresta* encontrarAresta(const Grafo& grafo, int origem, int destino) {
    for (const Aresta& aresta : grafo.vizinhos(origem)) {
        if (aresta.destino == destino) return &aresta;
    }
    return nullptr;
}
}

ResultadoCaminho dijkstra(const Grafo& grafo, int origem, int destino, Criterio criterio) {
    validarIndice(grafo, origem, "origem");
    validarIndice(grafo, destino, "destino");

    const int quantidade = grafo.quantidadeCidades();
    std::vector<double> distancias(quantidade, INFINITO);
    std::vector<int> predecessores(quantidade, -1);
    std::vector<bool> visitados(quantidade, false);

    // Fila de prioridade: sempre processa primeiro o vertice de menor distancia.
    using Estado = std::pair<double, int>;
    std::priority_queue<Estado, std::vector<Estado>, std::greater<Estado>> fila;

    distancias[origem] = 0.0;
    fila.push({0.0, origem});

    while (!fila.empty()) {
        const auto [distanciaAtual, atual] = fila.top();
        fila.pop();

        if (visitados[atual]) continue;
        if (distanciaAtual > distancias[atual] + EPSILON) continue;
        visitados[atual] = true;

        if (atual == destino) break;

        for (const Aresta& aresta : grafo.vizinhos(atual)) {
            const int proximo = aresta.destino;
            const double peso = pesoDaAresta(aresta, criterio);

            // Dijkstra exige pesos nao negativos. O Grafo atual ja exige pesos positivos,
            // mas a verificacao protege o algoritmo caso a implementacao do Grafo mude.
            if (peso < 0.0) {
                throw std::domain_error("Dijkstra nao aceita pesos negativos.");
            }

            const double novaDistancia = distancias[atual] + peso;
            if (novaDistancia + EPSILON < distancias[proximo]) {
                distancias[proximo] = novaDistancia;
                predecessores[proximo] = atual;
                fila.push({novaDistancia, proximo});
            }
        }
    }

    ResultadoCaminho resultado;
    if (!std::isfinite(distancias[destino])) return resultado;

    // Reconstrucao do destino ate a origem usando o vetor de predecessores.
    for (int atual = destino; atual != -1; atual = predecessores[atual]) {
        resultado.caminho.push_back(atual);
        if (atual == origem) break;
    }
    if (resultado.caminho.empty() || resultado.caminho.back() != origem) {
        resultado.caminho.clear();
        return resultado;
    }
    std::reverse(resultado.caminho.begin(), resultado.caminho.end());

    // Recalcula os tres totais reais do caminho, independentemente do criterio escolhido.
    resultado.encontrado = true;
    resultado.peso = distancias[destino];
    for (std::size_t i = 1; i < resultado.caminho.size(); ++i) {
        const Aresta* aresta = encontrarAresta(grafo, resultado.caminho[i - 1], resultado.caminho[i]);
        if (!aresta) {
            // Protecao para grafos alterados de forma inconsistente durante a execucao.
            resultado = ResultadoCaminho{};
            return resultado;
        }
        resultado.custo += aresta->custo;
        resultado.distancia += aresta->distancia;
        resultado.tempo += aresta->tempo;
    }
    return resultado;
}

ResultadoCaminho avaliarRoteiro(const Grafo& grafo, const std::vector<int>& roteiro) {
    ResultadoCaminho resultado;
    if (roteiro.empty()) return resultado;

    for (int indice : roteiro) validarIndice(grafo, indice, "cidade do roteiro");

    resultado.encontrado = true;
    resultado.caminho = roteiro;

    for (std::size_t i = 1; i < roteiro.size(); ++i) {
        const Aresta* aresta = encontrarAresta(grafo, roteiro[i - 1], roteiro[i]);
        if (!aresta) {
            // O roteiro nao representa uma sequencia de rotas existentes.
            return ResultadoCaminho{};
        }
        resultado.custo += aresta->custo;
        resultado.distancia += aresta->distancia;
        resultado.tempo += aresta->tempo;
    }
    // Na avaliacao de um roteiro fixo nao ha criterio otimizado; peso fica como custo.
    resultado.peso = resultado.custo;
    return resultado;
}

void imprimirCaminho(const Grafo& grafo, const ResultadoCaminho& resultado) {
    if (!resultado.encontrado || resultado.caminho.empty()) {
        std::cout << "Nenhum caminho encontrado entre as cidades informadas.\n";
        return;
    }

    std::cout << "Caminho encontrado:\n";
    for (std::size_t i = 0; i < resultado.caminho.size(); ++i) {
        const Cidade& cidade = grafo.cidade(resultado.caminho[i]);
        std::cout << "  " << cidade.nome << " (" << cidade.pais << ")";
        if (i + 1 < resultado.caminho.size()) std::cout << " ->\n";
        else std::cout << '\n';
    }

    const std::ios::fmtflags flagsAnteriores = std::cout.flags();
    const std::streamsize precisaoAnterior = std::cout.precision();
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Totais do caminho:\n"
              << "  Custo: R$ " << resultado.custo << '\n'
              << "  Distancia: " << resultado.distancia << " km\n"
              << "  Tempo: " << resultado.tempo << " h\n";
    std::cout.flags(flagsAnteriores);
    std::cout.precision(precisaoAnterior);
}
