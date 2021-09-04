#include "Operation_Prim.h"

int Operation_Prim::minKey(int* key, bool* mstSet, int n)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (*(mstSet+v) == false && *(key+v) < min)
            min = *(key + v), min_index = v;

    return min_index;
}

void Operation_Prim::printMST(int* parent, int** graph, int n)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++)
        cout << *(parent+i) << " - " << i << " \t" << *(*(graph+i)+*(parent+i)) << " \n";
}

void Operation_Prim::primMST(int** graph, int n)
{
    int *parent=new int [n];

    // Key values used to pick minimum weight edge in cut
    int *key = new int[n];

    // To represent set of vertices included in MST
    bool *mstSet = new bool[n];

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++)
        *(key+i) = INT_MAX, *(mstSet+i) = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    *(key+0) = 0;
    *(parent+0) = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet,n);

        // Add the picked vertex to the MST Set
        *(mstSet+u) = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < n; v++)

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (*(*(graph+u)+v) && *(mstSet+v) == false && *(*(graph+u)+v) < *(key+v))
                *(parent+v) = u, *(key+v) = *(*(graph+u)+v);
    }

    // print the constructed MST
    printMST(parent, graph,n);
}
