#include "Grafo.hpp"
#include "Dijkstra.hpp"
#include "Prim.hpp"

#include <iostream>

// Etapa 0: o executavel compila e prova que os contratos sao compativeis.
// Phillipe vai substituir este exemplo por um menu depois.
int main() {
    Grafo grafo;
    grafo.adicionarCidade({"CWB", "Brasil", "Curitiba", "Jardim Botanico"});
    grafo.adicionarCidade({"DUB", "Irlanda", "Dublin", "Trinity College"});
    grafo.adicionarRota("CWB", "DUB", 4100.0, 9900.0, 16.0, "aviao com conexao");

    std::cout << "=== EUROTRIP - ETAPA 0 ===\n";
    std::cout << "Base compilada! Cidades do teste: " << grafo.quantidadeCidades() << "\n";
    std::cout << "Primeira rota: " << grafo.cidade(0).nome << " <-> "
              << grafo.cidade(grafo.vizinhos(0).at(0).destino).nome << "\n";
    std::cout << "Lucas: CSV, validacao e matrizes [PENDENTE]\n";
    std::cout << "Eduardo: Dijkstra [PENDENTE]\n";
    std::cout << "Phillipe: Prim e menu [PENDENTE]\n";
    return 0;
}
