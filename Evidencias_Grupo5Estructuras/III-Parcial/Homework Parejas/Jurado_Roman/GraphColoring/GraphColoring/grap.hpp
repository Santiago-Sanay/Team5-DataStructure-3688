#include <list>
#include <vector>


class Graph
{
    int size;
    std::list<int> *adj;

public:
    Graph(int size)
    {
        this->size = size;
        adj = new  std::list<int>[size];
    }
    ~Graph() { delete[] adj; }
    void addEdge(int, int);
    void greedyColoring();
};

void Graph::addEdge(int element, int weight)
{
    adj[element].push_back(weight);
    adj[weight].push_back(element);
}

void Graph::greedyColoring()
{
    std::vector<int> result(size);
    result.at(0) = 0;

    for (int vertex = 1; vertex < size; vertex++)
    {
        result.at(vertex) = -1;
    }

    std::vector<bool> available(size);
    for (int color = 0; color < size; color++)
    {
        available.at(color) = false;
    }

    for (int vertex = 1; vertex < size; vertex++)
    {
         std::list<int>::iterator i;
        for (i = adj[vertex].begin(); i != adj[vertex].end(); ++i)
        {
            if (result.at(*i) != -1)
            {
                available.at(result.at(*i)) = true;
            }
        }

        int color;
        for (color = 0; color < size; color++)
        {
            if (available.at(color) == false)
            {
                break;
            }
        }

        result.at(vertex) = color;
        for (i = adj[vertex].begin(); i != adj[vertex].end(); ++i)
        {
            if (result.at(*i) != -1)
            {
                available.at(result.at(*i)) = false;
            }
        }
    }

    for (int index = 0; index < size; index++)
    {
        std::cout << "Vertice " << index << " --->  Color "
                  << result.at(index) << std::endl;
    }
}