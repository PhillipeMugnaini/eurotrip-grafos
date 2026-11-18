
#include "Grafo.hpp"
#include "Dijkstra.hpp"
#include "Prim.hpp"
#include <limits>
#include <iostream>
#include <string>
#include <exception>


void exibirMenu() {
    std::cout << "\n====================================\n";
    std::cout << "          MENU EUROTRIP             \n";
    std::cout << "====================================\n\n";

    std::cout << "1. Listar cidades\n";
    std::cout << "2. Listar rotas\n";
    std::cout << "3. Exibir matrizes\n";
    std::cout << "4. Menor caminho por custo\n";
    std::cout << "5. Menor caminho por distancia\n";
    std::cout << "6. Menor caminho por tempo\n";
    std::cout << "7. Arvore Geradora Minima (Prim)\n";
    std::cout << "8. Avaliar roteiro\n";
    std::cout << "0. Sair\n";

    std::cout << "\n====================================\n";
}


void executarDijkstra(const Grafo& grafo, Criterio criterio) {
    std::string idOrigem;
    std::string idDestino;

    std::cout << "\n========== DIJKSTRA ==========\n";

    // Mostra as cidades disponiveis.
    grafo.imprimirCidades();

    // Solicita a origem e o destino.
    std::cout << "\nDigite o ID da cidade de origem: ";
    if (!(std::cin >> idOrigem)) {
        return;
    }

    std::cout << "Digite o ID da cidade de destino: ";
    if (!(std::cin >> idDestino)) {
        return;
    }

    try {
        // Converte os IDs para indices numericos.
        int origem = grafo.indice(idOrigem);
        int destino = grafo.indice(idDestino);

        if (origem < 0 || destino < 0) {
            std::cout << "Cidade de origem ou destino invalida.\n";
            return;
        }

        // Executa o Dijkstra conforme o criterio escolhido.
        ResultadoCaminho resultado =
            dijkstra(grafo, origem, destino, criterio);

        std::cout << "\nCriterio: "
                  << nomeCriterio(criterio) << "\n\n";

        // Exibe o caminho encontrado e seus totais.
        imprimirCaminho(grafo, resultado);

    } catch (const std::exception& erro) {
        std::cout << "Erro ao calcular caminho: "
                  << erro.what() << "\n";
    }
}


void executarAvaliacaoRoteiro(const Grafo& grafo) {
    std::cout << "\n========== AVALIAR ROTEIRO ==========\n";

    grafo.imprimirCidades();

    int quantidade;

    std::cout << "\nQuantidade de cidades do roteiro: ";

    if (!(std::cin >> quantidade)) {
        if (!std::cin.eof()) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
            std::cout << "Quantidade invalida.\n";
        }
        return;
    }

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n'
    );

    if (quantidade < 2 || quantidade > grafo.quantidadeCidades()) {
        std::cout << "Informe entre 2 e "
                  << grafo.quantidadeCidades()
                  << " cidades.\n";
        return;
    }

    std::vector<int> roteiro;

    for (int i = 0; i < quantidade; i++) {
        std::string id;

        std::cout << "ID da cidade " << i + 1 << ": ";

        if (!std::getline(std::cin, id)) {
            return;
        }

        int indice = grafo.indice(id);

        if (indice < 0) {
            std::cout << "Cidade nao encontrada: "
                      << id << "\n";
            return;
        }

        roteiro.push_back(indice);
    }

    ResultadoCaminho resultado = avaliarRoteiro(grafo, roteiro);

    if (!resultado.encontrado) {
        std::cout << "Roteiro invalido: existe um trecho "
                  << "sem conexao direta.\n";
        return;
    }

    std::cout << "\n========== RESULTADO DO ROTEIRO ==========\n";
    imprimirCaminho(grafo, resultado);
}




int main() {
    std::cout << "====================================\n";
    std::cout << "          EUROTRIP GRAFOS           \n";
    std::cout << "====================================\n\n";

    try {
        // 1. Cria o grafo da viagem.
        Grafo grafo;

        // 2. Carrega os dados dos arquivos CSV.
        grafo.carregarCidades("data/cidades.csv");
        grafo.carregarRotas("data/rotas.csv");

        std::cout << "Dados carregados com sucesso!\n";

        // 3. Informa quantas cidades foram carregadas.
        std::cout << "Total de cidades: "
                  << grafo.quantidadeCidades()
                  << "\n\n";

        // 4. Valida a estrutura do grafo.
        std::string mensagem;

        if (!grafo.validar(mensagem)) {
            std::cerr << "Erro na validacao: "
                      << mensagem << "\n";
            return 1;
        }

        std::cout << "Validacao: "
                  << mensagem << "\n\n";

        // 5. Exibe as cidades cadastradas.

std::cout << "Grafo carregado e validado!\n";

int opcao;

while (true) {
    exibirMenu();

    std::cout << "\nEscolha uma opcao: ";

    if (!(std::cin >> opcao)) {
        if (std::cin.eof()) {
            std::cout << "\nEntrada encerrada.\n";
            break;
        }

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );

        std::cout << "Entrada invalida. Digite um numero.\n";
        continue;
    }

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n'
    );

    switch (opcao) {
        case 1:
            grafo.imprimirCidades();
            break;

        case 2:
            grafo.imprimirRotas();
            break;

        case 3:
            std::cout << "\n========== MATRIZ DE CUSTOS ==========\n";
            grafo.imprimirMatriz(Criterio::Custo);

            std::cout << "\n========== MATRIZ DE DISTANCIAS ==========\n";
            grafo.imprimirMatriz(Criterio::Distancia);

            std::cout << "\n========== MATRIZ DE TEMPOS ==========\n";
            grafo.imprimirMatriz(Criterio::Tempo);
            break;

        case 4:
            executarDijkstra(grafo, Criterio::Custo);
            break;

        case 5:
            executarDijkstra(grafo, Criterio::Distancia);
            break;

        case 6:
            executarDijkstra(grafo, Criterio::Tempo);
            break;


        case 7: {
            std::cout << "\n========== EXECUTANDO PRIM ==========\n";

            // Define Curitiba como vertice inicial.
            int origemPrim = grafo.indice("CWB");

            if (origemPrim < 0) {
                std::cout << "Curitiba nao encontrada no grafo.\n";
                break;
            }

            // Calcula a Arvore Geradora Minima.
            ResultadoAGM resultado = prim(grafo, origemPrim);

            // Exibe as conexoes e os totais.
            imprimirAGM(grafo, resultado);

            break;
        }

        case 8:
            executarAvaliacaoRoteiro(grafo);
            break;

        case 0:
            std::cout << "Encerrando Eurotrip...\n";
            break;

        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
    }

    if (opcao == 0) {
        break;
    }
}


    } catch (const std::exception& erro) {
        std::cerr << "Erro ao iniciar o programa: "
                  << erro.what() << "\n";
        return 1;
    }

    return 0;
}
