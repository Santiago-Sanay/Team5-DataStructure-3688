
#include <iostream>
#include "grap.hpp"

int main()
{

    Graph graph(7);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(0, 2);
    graph.addEdge(2, 4);
    graph.addEdge(0, 1);
    graph.addEdge(6, 3);
    graph.addEdge(4, 3);
    graph.addEdge(3, 5);
    std::cout << "\nColoracion del gráfico 1 \n";
    graph.greedyColoring();

    return 0;
}