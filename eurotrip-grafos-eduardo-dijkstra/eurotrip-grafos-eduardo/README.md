# Eurotrip - Estrutura de Dados Nao Lineares (Etapa 0)

Projeto de um trio para modelar uma viagem partindo de **Curitiba, PR, Brasil**
com destinos em **Irlanda (Dublin), Noruega (Oslo), Republica Tcheca (Praga),
Suica (Zurique), Italia (Roma) e Grecia (Atenas)**.

**IMPORTANTE:** este repositorio e o **ponto de partida**, nao a solucao final.
As funcoes dos algoritmos e parte da leitura/validacao do grafo tem
`TODO` e lancam `std::logic_error` ate serem implementadas pelo grupo.
O executavel e o teste inicial compilam e executam normalmente.

## Responsaveis

- Lucas - Grafo, dados CSV, validacao e matrizes (`feature/grafo`).
- Eduardo - Dijkstra e exibicao do caminho (`feature/dijkstra`).
- Phillipe - Prim, AGM e integracao do menu (`feature/prim`).

## Estrutura

```text
eurotrip-grafos/
|-- include/
|   |-- Grafo.hpp          # Contrato do grafo
|   |-- Dijkstra.hpp       # Contrato dos caminhos minimos
|   `-- Prim.hpp           # Contrato da AGM
|-- src/
|   |-- Grafo.cpp          # Base comum + TODOs do Lucas
|   |-- Dijkstra.cpp       # TODOs do Eduardo
|   |-- Prim.cpp           # TODOs do Phillipe
|   `-- main.cpp           # Exemplo compilavel; depois menu do Phillipe
|-- data/
|   |-- cidades.csv
|   `-- rotas.csv
|-- tests/
|   `-- teste_base.cpp
|-- docs/
|   |-- contratos.md
|   |-- divisao.md
|   |-- github-passo-a-passo.md
|   `-- uso-de-ia.md
|-- CMakeLists.txt
`-- .gitignore
```

## Compilar, rodar e testar

Instalar Git, CMake e compilador C++ (GCC/Clang/MSVC). No terminal do VS Code:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Linux/macOS: `./build/eurotrip`
Windows com MinGW: `build\eurotrip.exe`
Windows com MSVC: `build\Debug\eurotrip.exe`

Resultado esperado: `Base compilada! Cidades do teste: 2` e `100% tests passed`.

## Como colaborar

Ver `docs/github-passo-a-passo.md`. Os cabecalhos (`include/*.hpp`) sao
contratos compartilhados: nao alterar unilateralmente. Cada um pode
testar seu codigo com um grafo criado manualmente, sem precisar dos CSVs.

## Sobre os dados

Os numeros em `data/rotas.csv` sao **estimativas academicas de trabalho**,
nao precos ou itinerarios verificados. Uma aresta `aviao com conexao` pode
incluir escalas. Pesquisar fontes e documentar os pesos antes da entrega.

## Requisitos de entrega (conforme enunciado)

- C++ sem bibliotecas externas de grafos.
- Pelo menos seis paises europeus, grafo conexo, grau minimo 3.
- Pesos por custo, distancia e tempo e tres matrizes.
- Menores caminhos por Dijkstra (ou outro algoritmo admissivel).
- AGM por Prim (ou Kruskal), grafo original, resultados e conclusoes.
- Repositorio Git com evolucao, autoria e uso de IA declarado.
- Apresentacao de ate 10 minutos e slides em PDF/PPTX.
