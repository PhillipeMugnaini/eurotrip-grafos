
#include "Grafo.hpp"
#include "Prim.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

int main() {
    Grafo grafo;

    // Cria quatro cidades ficticias.
    grafo.adicionarCidade({"A", "Teste", "Cidade A", "Ponto A"});
    grafo.adicionarCidade({"B", "Teste", "Cidade B", "Ponto B"});
    grafo.adicionarCidade({"C", "Teste", "Cidade C", "Ponto C"});
    grafo.adicionarCidade({"D", "Teste", "Cidade D", "Ponto D"});

    // Todas as cidades possuem pelo menos 3 conexoes.
    grafo.adicionarRota("A", "B", 10, 100, 1, "Carro");
    grafo.adicionarRota("A", "C", 30, 300, 3, "Carro");
    grafo.adicionarRota("B", "D", 20, 200, 2, "Carro");
    grafo.adicionarRota("C", "D", 5, 50, 0.5, "Carro");
    grafo.adicionarRota("A", "D", 40, 400, 4, "Carro");
    grafo.adicionarRota("B", "C", 50, 500, 5, "Carro");

    // Executa Prim iniciando pela cidade A.
    ResultadoAGM resultado = prim(grafo, grafo.indice("A"));

    // Mostra o resultado.
    imprimirAGM(grafo, resultado);

    bool passou =
        resultado.completa &&
        resultado.rotas.size() == 3 &&
        std::abs(resultado.custoTotal - 35.0) < 1e-9 &&
        std::abs(resultado.distanciaTotal - 350.0) < 1e-9 &&
        std::abs(resultado.tempoTotal - 3.5) < 1e-9;

    if (!passou) {
        std::cerr << "\nFALHA: AGM incorreta!\n";
        return 1;
    }

    // Testa a validacao da origem.
    bool origemInvalidaRejeitada = false;

    try {
        prim(grafo, -1);
    } catch (const std::out_of_range&) {
        origemInvalidaRejeitada = true;
    }

    if (!origemInvalidaRejeitada) {
        std::cerr << "\nFALHA: origem invalida aceita!\n";
        return 1;
    }

    std::cout << "\nTODOS OS TESTES DO PRIM PASSARAM!\n";
    return 0;
}
