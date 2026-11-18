#pragma once

#include <string>
#include <vector>

enum class Criterio { Custo, Distancia, Tempo };

struct Cidade {
    std::string id;
    std::string pais;
    std::string nome;
    std::string pontoTuristico;
};

struct Aresta {
    int destino;
    double custo;
    double distancia;
    double tempo;
    std::string transporte;
    std::string observacoes;
};

class Grafo {
public:
    void adicionarCidade(const Cidade& cidade);
    void adicionarRota(const std::string& origem, const std::string& destino,
                       double custo, double distancia, double tempo,
                       const std::string& transporte, const std::string& observacoes = "");
    void carregarCidades(const std::string& caminho);
    void carregarRotas(const std::string& caminho);

    int indice(const std::string& id) const;
    const Cidade& cidade(int indice) const;
    const std::vector<Aresta>& vizinhos(int indice) const;
    int quantidadeCidades() const;
    bool validar(std::string& mensagem) const;
    void imprimirCidades() const;
    void imprimirRotas() const;
    void imprimirMatriz(Criterio criterio) const;

private:
    std::vector<Cidade> cidades_;
    std::vector<std::vector<Aresta>> adjacencias_;
};

double pesoDaAresta(const Aresta& aresta, Criterio criterio);
std::string nomeCriterio(Criterio criterio);
