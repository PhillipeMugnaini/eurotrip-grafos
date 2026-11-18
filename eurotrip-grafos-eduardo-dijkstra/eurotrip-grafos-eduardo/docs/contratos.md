# Contratos compartilhados (congelados para Etapa 1)

**Importante:** nao alterar os arquivos `include/*.hpp` sem avisar o grupo.
Esses cabecalhos sao as interfaces entre as partes.

## Arquivo Grafo.hpp

- `Cidade`: `id`, `pais`, `nome`, `pontoTuristico`.
- `Aresta`: `destino` (indice), `custo` (R$), `distancia` (km), `tempo` (h), `transporte` e `observacoes`.
- `Grafo::adicionarCidade()`: registra um vertice.
- `Grafo::adicionarRota()`: registra uma aresta em ambos os sentidos.
- `Grafo::vizinhos(i)`: devolve as arestas que saem do vertice `i`.
- `Grafo::indice(id)`: converte ID de cidade (ex.: `CWB`) em indice.
- `pesoDaAresta(aresta, criterio)`: escolhe um dos tres pesos.

## Arquivo Dijkstra.hpp

- `dijkstra(const Grafo&, int origem, int destino, Criterio)`: retorna `ResultadoCaminho`.
- `ResultadoCaminho.encontrado`: false se nao existe caminho.
- `ResultadoCaminho.caminho`: lista de indices, incluindo origem e destino.
- `ResultadoCaminho.peso`: soma do criterio otimizado.
- `ResultadoCaminho.custo`, `distancia`, `tempo`: totais reais do caminho encontrado.

## Arquivo Prim.hpp

- `prim(const Grafo&, int origem)`: retorna `ResultadoAGM`.
- `ResultadoAGM.rotas`: arestas da AGM. Para `N` vertices conexos deve ter `N-1` arestas.
- `ResultadoAGM.completa`: true se conseguiu conectar todos.
- `custoTotal`, `distanciaTotal` e `tempoTotal`: soma dos pesos das arestas escolhidas.

## Como testar sem depender do Lucas

`Grafo::adicionarCidade`, `adicionarRota`, `indice`, `cidade`, `vizinhos` e
`quantidadeCidades` ja funcionam. Eduardo e Phillipe podem criar o grafo
manualmente em seus proprios testes e chamar seus algoritmos.

```cpp
Grafo g;
g.adicionarCidade({"A", "Brasil", "Curitiba", "Jardim Botanico"});
g.adicionarCidade({"B", "Irlanda", "Dublin", "Trinity College"});
g.adicionarRota("A", "B", 100, 200, 3, "aviao");
// g.vizinhos(g.indice("A")) agora contem B.
```

Para garantir independencia, comecem criando testes pequenos. O teste-base
ja esta em `tests/teste_base.cpp`.

## Nao confundir

- Dijkstra nao garante passar por todos os paises, apenas minimiza o peso entre dois vertices.
- Prim conecta todos os vertices com o menor custo de arestas, mas a AGM nao e um roteiro linear de viagem.
- Os valores do CSV sao exemplos para estudo, e devem ser pesquisados antes da entrega.
