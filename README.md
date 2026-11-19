# Eurotrip | Parte 1 - Estrutura do grafo e dados

Parte do Lucas na APS2 de Estrutura de Dados Não Lineares. Este módulo organiza as cidades e as conexões de transporte que os algoritmos de Dijkstra e Prim usam no projeto integrado.

## 1. Objetivo

Carregar os dados dos arquivos CSV, representar as conexões em um grafo ponderado, verificar a conectividade e disponibilizar a listagem das cidades, das rotas e das matrizes de pesos.

## 2. Modelo do grafo

O grafo é não direcionado e utiliza listas de adjacência. Cada cidade é um vértice. Cada conexão entre duas cidades é uma aresta com três pesos independentes: custo em reais, distância em quilômetros e duração em horas.

| Código | Cidade | País |
| --- | --- | --- |
| `CWB` | Curitiba | Brasil |
| `ZRH` | Zurique | Suíça |
| `OSL` | Oslo | Noruega |
| `ROM` | Roma | Itália |
| `ATH` | Atenas | Grécia |
| `DUB` | Dublin | Irlanda |
| `PRG` | Praga | República Tcheca |

A base do projeto integrado contém sete cidades e 18 conexões. O grafo fornece os mesmos dados a Dijkstra, que encontra caminhos mínimos, e a Prim, que calcula a Árvore Geradora Mínima pelo custo.

## 3. Leitura e validação

1. Carregar as cidades de `data/cidades.csv`. O identificador de cada cidade serve de referência para as rotas.
2. Carregar as conexões de `data/rotas.csv` e associar os três pesos aos respectivos pares de cidades.
3. Verificar a conectividade do grafo. A partir de uma cidade, todas as outras devem ser alcançáveis, inclusive por caminhos com vários trechos.
4. Exibir cidades, rotas e as matrizes de custo, distância e tempo. Cada matriz mostra os pesos das conexões diretas para um critério.

## 4. Arquivos da parte do Lucas

| Arquivo | Papel no projeto |
| --- | --- |
| [`include/Grafo.hpp`](include/Grafo.hpp) | Declara a estrutura do grafo e suas operações. |
| [`src/Grafo.cpp`](src/Grafo.cpp) | Implementa a leitura dos dados, a validação e a exibição. |
| [`data/cidades.csv`](data/cidades.csv) | Armazena as cidades e seus identificadores. |
| [`data/rotas.csv`](data/rotas.csv) | Armazena as conexões e os pesos de custo, distância e tempo. |
| [`tests/teste_base.cpp`](tests/teste_base.cpp) | Testes automatizados da estrutura base do projeto. |
| [`docs/fontes-dados-eurotrip.md`](docs/fontes-dados-eurotrip.md) | Registra as fontes, as conversões monetárias e as limitações dos dados. |

## 5. Como executar no projeto integrado

Com um compilador C++17 e CMake, execute os comandos a partir da raiz do repositório. O último comando é para Linux.

```bash
cmake -S . -B build
cmake --build build
./build/eurotrip
```

| Opção do menu | O que conferir |
| --- | --- |
| `1` | A lista exibe as sete cidades e seus identificadores. |
| `2` | A lista exibe as 18 conexões com custo, distância e tempo. |
| `3` | As matrizes exibem os pesos das conexões diretas para cada critério. |

## 6. Testes da estrutura base

Depois da compilação, execute:

```bash
ctest --test-dir build -R '^estrutura_base$' --output-on-failure
```

Para uma conferência manual, compare uma conexão exibida na opção `2` com a linha correspondente em `data/rotas.csv`. Use o mesmo par de cidades na opção `3` para conferir o peso em cada matriz.

## 7. Dados e fontes

As tarifas foram pesquisadas para datas distintas e são usadas como referências acadêmicas. Os resultados calculados pelo programa dependem dos pesos dos CSVs. As fontes, os critérios de conversão e as limitações estão na [documentação dos dados](docs/fontes-dados-eurotrip.md).

A descrição do apoio de ferramentas de inteligência artificial está no [registro de uso de IA](docs/uso-de-ia.md).
