
# Eurotrip | APS2 - Estrutura de Dados Não Lineares

Projeto acadêmico desenvolvido em C++ para modelar uma viagem internacional utilizando grafos ponderados e algoritmos de otimização.

## 1. Objetivo

Representar uma Eurotrip partindo de Curitiba, Brasil, e envolvendo seis países europeus:

- Suíça: Zurique
- Noruega: Oslo
- Itália: Roma
- Grécia: Atenas
- Irlanda: Dublin
- República Tcheca: Praga

O sistema utiliza grafos para representar cidades e conexões de transporte, considerando três pesos: custo financeiro, distância e tempo.

## 2. Algoritmos implementados

### Dijkstra

Calcula o menor caminho entre duas cidades considerando separadamente:

- Menor custo financeiro
- Menor distância
- Menor tempo

### Prim

Constrói uma Árvore Geradora Mínima (AGM), minimizando o custo total das conexões necessárias para interligar todos os vértices do grafo.

A AGM não representa obrigatoriamente um roteiro sequencial de viagem.

### Avaliação de roteiro

Permite informar uma sequência de cidades e calcular o custo, a distância e o tempo acumulados das conexões selecionadas.

## 3. Tecnologias

- C++
- CMake
- Git e GitHub
- Arquivos CSV
- Biblioteca padrão do C++

Não são utilizadas bibliotecas externas de algoritmos de grafos.

## 4. Estrutura do projeto

    eurotrip-grafos/
    ├── include/
    │   ├── Grafo.hpp
    │   ├── Dijkstra.hpp
    │   └── Prim.hpp
    ├── src/
    │   ├── Grafo.cpp
    │   ├── Dijkstra.cpp
    │   ├── Prim.cpp
    │   └── main.cpp
    ├── data/
    │   ├── cidades.csv
    │   └── rotas.csv
    ├── tests/
    │   ├── teste_base.cpp
    │   ├── teste_dijkstra.cpp
    │   └── teste_prim.cpp
    ├── docs/
    │   ├── fontes-dados-eurotrip.md
    │   └── uso-de-ia.md
    ├── CMakeLists.txt
    └── README.md

## 5. Compilação e execução

Pré-requisitos:

- Compilador C++ com suporte a C++17
- CMake
- Git, para clonar o repositório

Clonar:

    git clone https://github.com/PhillipeMugnaini/eurotrip-grafos.git
    cd eurotrip-grafos

Configurar e compilar:

    cmake -S . -B build
    cmake --build build

Executar no Linux:

    ./build/eurotrip

O programa deve ser executado a partir da raiz do projeto, para localizar os arquivos CSV.

## 6. Funcionalidades do menu

1. Listar cidades
2. Listar rotas
3. Exibir matrizes de custo, distância e tempo
4. Calcular menor caminho por custo
5. Calcular menor caminho por distância
6. Calcular menor caminho por tempo
7. Calcular Árvore Geradora Mínima
8. Avaliar roteiro informado pelo usuário
0. Sair

Os identificadores das cidades são:

CWB, ZRH, OSL, ROM, ATH, DUB e PRG.

## 7. Resultados obtidos

Caminhos mínimos de Curitiba (CWB) até Praga (PRG):

| Critério | Caminho | Custo | Distância | Tempo |
|---|---|---:|---:|---:|
| Custo | CWB-DUB-PRG | R$ 2.444,85 | 11.723 km | 20,83 h |
| Distância | CWB-ROM-PRG | R$ 3.309,90 | 11.004 km | 29,00 h |
| Tempo | CWB-DUB-PRG | R$ 2.444,85 | 11.723 km | 20,83 h |

Árvore Geradora Mínima pelo custo:

- 7 vértices conectados
- 6 arestas selecionadas
- Custo total: R$ 3.430,53
- Distância acumulada: 17.027 km
- Tempo acumulado: 30,58 h

Os resultados dependem dos pesos cadastrados nos arquivos CSV.

## 8. Testes automatizados

Executar:

    ctest --test-dir build --output-on-failure

Testes implementados:

- estrutura_base
- algoritmo_prim
- algoritmo_dijkstra

O projeto também foi testado manualmente com entradas inválidas, cidades inexistentes e roteiros sem conexão direta.

## 9. Dados e fontes

Os arquivos CSV representam um grafo não direcionado com sete cidades e 18 conexões.

Os preços, distâncias, durações, referências, critérios de conversão monetária e limitações dos dados estão descritos em:

    docs/fontes-dados-eurotrip.md

As tarifas foram pesquisadas para datas distintas e são utilizadas como referências acadêmicas. Não constituem uma cotação atualizada ou um itinerário reservável.

## 10. Divisão de responsabilidades

Lucas:
- Estrutura do grafo
- Leitura dos CSVs
- Validação de conectividade
- Exibição das matrizes
- Documentação dos dados

Eduardo:
- Algoritmo de Dijkstra
- Avaliação de roteiro
- Exibição dos caminhos
- Testes do algoritmo

Phillipe:
- Algoritmo de Prim
- Exibição da AGM
- Integração dos módulos
- Menu principal
- Testes e validação da aplicação integrada

## 11. Uso de inteligência artificial

Ferramentas de IA foram utilizadas como apoio durante o desenvolvimento.

A descrição das ferramentas utilizadas e de suas aplicações está no arquivo:

    docs/uso-de-ia.md

O grupo é responsável por compreender, validar e explicar o código apresentado.

## 12. Considerações finais

O projeto demonstra a utilização de grafos ponderados, listas de adjacência, filas de prioridade, caminhos mínimos e Árvores Geradoras Mínimas.

Os resultados mostram que a rota de menor distância não é necessariamente a de menor custo ou menor tempo.

O algoritmo de Dijkstra determina caminhos mínimos entre cidades, enquanto o algoritmo de Prim encontra uma rede de conexões de custo mínimo para interligar todos os destinos.
