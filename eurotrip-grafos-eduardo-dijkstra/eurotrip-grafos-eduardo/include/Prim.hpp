#pragma once

#include "Grafo.hpp"
#include <vector>

struct RotaAGM {
    int origem;
    int destino;
    double custo;
    double distancia;
    double tempo;
};

struct ResultadoAGM {
    bool completa = false;
    std::vector<RotaAGM> rotas;
    double custoTotal = 0;
    double distanciaTotal = 0;
    double tempoTotal = 0;
};

ResultadoAGM prim(const Grafo& grafo, int origem = 0);
void imprimirAGM(const Grafo& grafo, const ResultadoAGM& resultado);
