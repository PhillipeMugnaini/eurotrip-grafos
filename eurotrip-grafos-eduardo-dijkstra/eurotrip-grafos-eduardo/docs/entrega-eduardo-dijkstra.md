# Entrega do integrante 2 — Eduardo (Dijkstra)

## Arquivos desenvolvidos

- `src/Dijkstra.cpp`: implementacao do algoritmo e das funcoes auxiliares ja declaradas no contrato.
- `tests/teste_dijkstra.cpp`: testes automatizados para os tres criterios, reconstrucao do caminho, origem igual ao destino, ausencia de caminho, avaliacao de roteiro e indice invalido.
- `CMakeLists.txt`: registro do novo executavel de teste `teste_dijkstra`.

O cabecalho `include/Dijkstra.hpp` foi mantido sem alteracoes para respeitar o contrato compartilhado pelo grupo.

## Funcionamento

A funcao `dijkstra` recebe o grafo, os indices da origem e do destino e um `Criterio` (`Custo`, `Distancia` ou `Tempo`). Ela utiliza uma fila de prioridade para processar primeiro o vertice com menor peso acumulado. Para cada vizinho, seleciona o peso correto por meio de `pesoDaAresta` e atualiza a distancia e o predecessor quando encontra um caminho melhor.

Ao terminar, reconstrói o caminho percorrendo o vetor de predecessores do destino ate a origem. Depois soma custo, distancia e tempo das arestas desse caminho, permitindo comparar os tres indicadores mesmo quando apenas um deles foi otimizado.

`avaliarRoteiro` calcula os totais de uma sequencia de cidades ja definida. Se algum trecho consecutivo nao possuir uma aresta no grafo, o roteiro e marcado como nao encontrado.

`imprimirCaminho` mostra as cidades em ordem e os totais de custo, distancia e tempo.

## Complexidade

Com lista de adjacencia e fila de prioridade, Dijkstra possui complexidade aproximada de `O((V + E) log V)`, em que `V` e o numero de vertices e `E` o numero de arestas. O algoritmo pressupoe pesos nao negativos; a implementacao atual do projeto valida pesos estritamente positivos ao cadastrar rotas.

## Como testar

Na raiz do projeto:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

O teste `algoritmo_dijkstra` verifica os caminhos minimos por custo, distancia e tempo e os casos especiais descritos acima.

## Observacao para a integracao

A implementacao usa somente as interfaces existentes em `Grafo.hpp` e `Dijkstra.hpp`. Nao altera a estrutura do grafo nem os contratos compartilhados. A funcao `dijkstra` recebe indices de vertices, nao IDs textuais; para usar IDs como `CWB` ou `DUB`, o chamador deve convertê-los com `grafo.indice("CWB")`.
