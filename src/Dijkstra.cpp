#include "Dijkstra.hpp"

#include <stdexcept>

// ==== TAREFAS DO EDUARDO ====
// Implementar o caminho minimo para Custo, Distancia ou Tempo.
// A entrada e um Grafo ja construido; nao depende do CSV do Lucas.

ResultadoCaminho dijkstra(const Grafo& grafo, int origem, int destino, Criterio criterio) {
    (void)grafo; (void)origem; (void)destino; (void)criterio;
    throw std::logic_error("TODO Eduardo: algoritmo de Dijkstra");
}

ResultadoCaminho avaliarRoteiro(const Grafo& grafo, const std::vector<int>& roteiro) {
    (void)grafo; (void)roteiro;
    throw std::logic_error("TODO Eduardo: somar os pesos das rotas de um roteiro");
}

void imprimirCaminho(const Grafo& grafo, const ResultadoCaminho& resultado) {
    (void)grafo; (void)resultado;
    throw std::logic_error("TODO Eduardo: exibir o caminho e os tres totais");
}
