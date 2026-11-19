# Eurotrip | Parte 2 - Dijkstra e avaliação de roteiros

Parte do Eduardo na APS2 de Estrutura de Dados Não Lineares. Este módulo usa o grafo de cidades e conexões do Eurotrip para calcular caminhos mínimos e avaliar roteiros informados pelo usuário.

## 1. Objetivo

Encontrar o melhor caminho entre duas cidades por custo, distância ou tempo. O módulo também calcula os totais de um roteiro quando o usuário já definiu a ordem das cidades.

## 2. Algoritmo de Dijkstra

O grafo tem três pesos por conexão. Cada busca usa um peso de cada vez, conforme a opção escolhida no menu.

| Critério | Peso minimizado |
| --- | --- |
| Custo | Valor total em reais |
| Distância | Distância total em quilômetros |
| Tempo | Duração total em horas |

Dijkstra parte da cidade de origem e prioriza, a cada passo, o menor total acumulado conhecido. Ao encontrar uma alternativa melhor para uma cidade vizinha, atualiza o peso acumulado e registra de onde veio. Esses registros permitem reconstruir o caminho até o destino. O algoritmo requer pesos não negativos no critério selecionado.

## 3. Busca de caminho e avaliação de roteiro

Na busca por Dijkstra, o usuário informa a origem e o destino e o programa determina a sequência de cidades. Depois de selecionar o caminho pelo critério escolhido, a saída mostra os totais de custo, distância e tempo desse mesmo caminho.

Na avaliação de roteiro, o usuário informa toda a sequência. O programa verifica se cada par consecutivo tem uma conexão direta e soma os pesos dos trechos. Exemplo de sequência para avaliar no menu: `CWB → DUB → PRG`.

## 4. Arquivos da parte do Eduardo

| Arquivo | Papel no projeto |
| --- | --- |
| [`include/Dijkstra.hpp`](include/Dijkstra.hpp) | Declara as operações do módulo de Dijkstra. |
| [`src/Dijkstra.cpp`](src/Dijkstra.cpp) | Implementa a busca de caminhos mínimos. |
| [`tests/teste_dijkstra.cpp`](tests/teste_dijkstra.cpp) | Reúne os testes automatizados do algoritmo. |
| [`data/cidades.csv`](data/cidades.csv) e [`data/rotas.csv`](data/rotas.csv) | Fornecem as cidades, as conexões e os pesos usados nos cálculos. |

A contribuição do Eduardo inclui o algoritmo de Dijkstra, a avaliação de roteiros, a exibição dos caminhos e os testes do algoritmo.

## 5. Como executar no projeto integrado

Com um compilador C++17 e CMake, execute os comandos a partir da raiz do repositório. O último comando é para Linux.

```bash
cmake -S . -B build
cmake --build build
./build/eurotrip
```

| Opção do menu | O que faz |
| --- | --- |
| `4` | Calcula o menor caminho por custo. |
| `5` | Calcula o menor caminho por distância. |
| `6` | Calcula o menor caminho por tempo. |
| `8` | Avalia um roteiro informado pelo usuário. |

## 6. Testes do algoritmo

Depois da compilação, execute:

```bash
ctest --test-dir build -R '^algoritmo_dijkstra$' --output-on-failure
```

Para uma conferência manual, rode as opções `4`, `5` e `6` de Curitiba (`CWB`) até Praga (`PRG`). Com os pesos descritos no README do projeto integrado, os resultados de referência são os seguintes.

| Critério | Caminho | Custo | Distância | Tempo |
| --- | --- | ---: | ---: | ---: |
| Custo | CWB → DUB → PRG | R$ 2.444,85 | 11.723 km | 20,83 h |
| Distância | CWB → ROM → PRG | R$ 3.309,90 | 11.004 km | 29,00 h |
| Tempo | CWB → DUB → PRG | R$ 2.444,85 | 11.723 km | 20,83 h |

Ao avaliar a sequência `CWB → DUB → PRG` pela opção `8`, os totais esperados são R$ 2.444,85, 11.723 km e 20,83 h.

## 7. Dados e fontes

Os caminhos e totais dependem dos pesos cadastrados nos CSVs. As tarifas servem como referências acadêmicas. A [documentação dos dados](docs/fontes-dados-eurotrip.md) registra as fontes, as conversões monetárias e as limitações da coleta.

A descrição do apoio de ferramentas de inteligência artificial está no [registro de uso de IA](docs/uso-de-ia.md).
