# Divisao oficial do trio

| Integrante | Parte | Branch | Arquivos principais |
|---|---|---|---|
| **Lucas** | 1 - Grafo e dados | `feature/grafo` | `src/Grafo.cpp`, `data/*.csv` |
| **Eduardo** | 2 - Caminhos minimos | `feature/dijkstra` | `src/Dijkstra.cpp` |
| **Phillipe** | 3 - AGM e integracao | `feature/prim` | `src/Prim.cpp`, `src/main.cpp` |

Os headers `include/*.hpp` ficam compartilhados. Qualquer mudanca deve ser
combinada previamente. O conteudo inicial de `src/Grafo.cpp` oferece as
funcoes basicas para que os tres possam trabalhar ao mesmo tempo.

## Entregaveis de cada pessoa

### Lucas
1. Carregar `cidades.csv` e `rotas.csv` (separador `;`).
2. Validar: grafo nao vazio, todas as cidades com grau >= 3 e conexidade.
3. Exibir vertices, rotas e as 3 matrizes (custo, distancia, tempo).
4. Conferir se os pesos e transportes sao coerentes e anotar fontes/datas.

### Eduardo
1. Implementar Dijkstra com pesos nao negativos.
2. Calcular menor custo, distancia e tempo entre Curitiba e Atenas.
3. Reconstruir caminho e calcular os tres totais do trajeto escolhido.
4. Testar grafo pequeno com resultado conhecido e origem = destino.

### Phillipe
1. Implementar Prim considerando custo como peso da AGM.
2. Somar os tres pesos das arestas da arvore.
3. Criar `main.cpp` com menu para carregar CSV, validar, mostrar matrizes,
   executar Dijkstra e Prim.
4. Testar arvore com N-1 arestas, grafo desconexo e exibicao do resultado.

## Ordem sugerida de integracao

1. Etapa 0: scaffold e interfaces comuns na `main` (este ZIP).
2. Etapa 1: cada um implementa seus proprios arquivos em uma branch.
3. Etapa 2: Pull Requests separados, revisados pelos colegas.
4. Etapa 3: teste de ponta a ponta, fontes e apresentacao.

A avaliacao exige que todos consigam explicar o proprio codigo e que o uso
de IA na geracao de codigo seja declarado.
