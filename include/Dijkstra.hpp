#pragma once

#include "Grafo.hpp"
#include <vector>

struct ResultadoCaminho {
    bool encontrado = false;
    std::vector<int> caminho;
    double peso = 0;
    double custo = 0;
    double distancia = 0;
    double tempo = 0;
};

ResultadoCaminho dijkstra(const Grafo& grafo, int origem, int destino, Criterio criterio);
ResultadoCaminho avaliarRoteiro(const Grafo& grafo, const std::vector<int>& roteiro);
void imprimirCaminho(const Grafo& grafo, const ResultadoCaminho& resultado);
