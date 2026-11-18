#include "Grafo.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

int main() {
    Grafo grafo;
    grafo.adicionarCidade({"A", "Brasil", "Curitiba", "Jardim Botanico"});
    grafo.adicionarCidade({"B", "Irlanda", "Dublin", "Trinity College"});
    grafo.adicionarCidade({"C", "Suica", "Zurique", "Lago de Zurique"});
    grafo.adicionarCidade({"D", "Grecia", "Atenas", "Acropole"});

    // Grafo de teste completo: todos os 4 vertices tem grau 3.
    grafo.adicionarRota("A", "B", 10, 100, 2, "teste");
    grafo.adicionarRota("A", "C", 15, 120, 3, "teste");
    grafo.adicionarRota("A", "D", 50, 200, 4, "teste");
    grafo.adicionarRota("B", "C", 8, 80, 1, "teste");
    grafo.adicionarRota("B", "D", 25, 130, 3, "teste");
    grafo.adicionarRota("C", "D", 10, 90, 1.5, "teste");

    assert(grafo.quantidadeCidades() == 4);
    assert(grafo.indice("C") == 2);
    for (int i = 0; i < 4; ++i) assert(grafo.vizinhos(i).size() == 3);
    assert(std::abs(pesoDaAresta(grafo.vizinhos(0)[0], Criterio::Custo) - 10) < 1e-9);
    assert(std::abs(pesoDaAresta(grafo.vizinhos(0)[0], Criterio::Distancia) - 100) < 1e-9);

    bool duplicada = false;
    try { grafo.adicionarRota("A", "B", 10, 100, 2, "teste"); }
    catch (const std::runtime_error&) { duplicada = true; }
    assert(duplicada);

    std::cout << "OK: contrato basico do grafo funcionando\n";
    return 0;
}
