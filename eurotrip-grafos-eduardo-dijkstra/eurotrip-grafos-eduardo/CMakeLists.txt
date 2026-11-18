cmake_minimum_required(VERSION 3.16)
project(eurotrip_grafos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(eurotrip_lib
    src/Grafo.cpp
    src/Dijkstra.cpp
    src/Prim.cpp
)
target_include_directories(eurotrip_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(eurotrip src/main.cpp)
target_link_libraries(eurotrip PRIVATE eurotrip_lib)
target_compile_definitions(eurotrip PRIVATE EUROTRIP_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data")

enable_testing()
add_executable(teste_base tests/teste_base.cpp)
target_link_libraries(teste_base PRIVATE eurotrip_lib)
add_test(NAME estrutura_base COMMAND teste_base)

add_executable(teste_dijkstra tests/teste_dijkstra.cpp)
target_link_libraries(teste_dijkstra PRIVATE eurotrip_lib)
add_test(NAME algoritmo_dijkstra COMMAND teste_dijkstra)
