#include "Dijkstra.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

static bool proximo(double a, double b) { return std::abs(a - b) < 1e-9; }

int main() {
    Grafo g;
    g.adicionarCidade({"A", "Brasil", "Curitiba", "Jardim Botanico"});
    g.adicionarCidade({"B", "Irlanda", "Dublin", "Trinity College"});
    g.adicionarCidade({"C", "Noruega", "Oslo", "Opera"});
    g.adicionarCidade({"D", "Italia", "Roma", "Coliseu"});
    g.adicionarCidade({"E", "Grecia", "Atenas", "Acropole"});

    // Caminho mais barato A-B-D custa 60; A-C-D custa 45.
    // O menor caminho por custo deve ser A-C-D.
    g.adicionarRota("A", "B", 30, 100, 2, "aviao");
    g.adicionarRota("B", "D", 30, 100, 2, "trem");
    g.adicionarRota("A", "C", 20, 300, 5, "aviao");
    g.adicionarRota("C", "D", 25, 200, 3, "trem");
    g.adicionarRota("A", "D", 80, 50, 10, "aviao");

    auto custo = dijkstra(g, g.indice("A"), g.indice("D"), Criterio::Custo);
    assert(custo.encontrado);
    assert((custo.caminho == std::vector<int>{g.indice("A"), g.indice("C"), g.indice("D")}));
    assert(proximo(custo.peso, 45));
    assert(proximo(custo.custo, 45));
    assert(proximo(custo.distancia, 500));
    assert(proximo(custo.tempo, 8));

    auto distancia = dijkstra(g, g.indice("A"), g.indice("D"), Criterio::Distancia);
    assert(distancia.encontrado && proximo(distancia.peso, 50));
    assert((distancia.caminho == std::vector<int>{g.indice("A"), g.indice("D")}));

    auto tempo = dijkstra(g, g.indice("A"), g.indice("D"), Criterio::Tempo);
    assert(tempo.encontrado && proximo(tempo.peso, 4));
    assert((tempo.caminho == std::vector<int>{g.indice("A"), g.indice("B"), g.indice("D")}));

    // Origem igual ao destino: caminho de um unico vertice e totais zerados.
    auto mesmaCidade = dijkstra(g, g.indice("A"), g.indice("A"), Criterio::Custo);
    assert(mesmaCidade.encontrado && mesmaCidade.caminho.size() == 1);
    assert(proximo(mesmaCidade.peso, 0));

    // Cidade E esta isolada: nao deve existir caminho.
    auto semCaminho = dijkstra(g, g.indice("A"), g.indice("E"), Criterio::Custo);
    assert(!semCaminho.encontrado && semCaminho.caminho.empty());

    // Avaliacao de um roteiro existente soma os tres pesos.
    auto roteiro = avaliarRoteiro(g, {g.indice("A"), g.indice("C"), g.indice("D")});
    assert(roteiro.encontrado);
    assert(proximo(roteiro.custo, 45));
    assert(proximo(roteiro.distancia, 500));
    assert(proximo(roteiro.tempo, 8));

    // Roteiro com trecho inexistente deve ser recusado.
    auto roteiroInvalido = avaliarRoteiro(g, {g.indice("A"), g.indice("E")});
    assert(!roteiroInvalido.encontrado);

    bool indiceInvalido = false;
    try { (void)dijkstra(g, -1, 0, Criterio::Custo); }
    catch (const std::out_of_range&) { indiceInvalido = true; }
    assert(indiceInvalido);

    std::cout << "OK: testes de Dijkstra passaram\n";
    return 0;
}
