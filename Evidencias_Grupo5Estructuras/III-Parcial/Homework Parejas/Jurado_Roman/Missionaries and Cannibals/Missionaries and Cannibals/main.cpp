#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NumberOfActions = 15;

class State
{
public:
    int m, c, b;
};

enum treenode
{
    Fail,
    Incomplete,
    Goal
};
treenode idfsTree(State x, int limit, vector<State>* result);
bool validAction(int action, State x);
State move(int action, State x);
void printNode(treenode node, int limit);

int main()
{
    State root;
    root.m = 3;
    root.c = 3;
    root.b = 1;

    vector<State> result;
    treenode node = Incomplete;
    int limit = 1;

    while (node == Incomplete)
    {

        node = idfsTree(root, limit, &result);
        printNode(node, limit);
        limit++;
    }

    cout << "\nEl Arbol final es: " << endl;
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "        LADO 1                    LADO 2" << endl;
        cout << "M: " << 3 - result[i].m << " C: " << 3 - result[i].c << "  Lado del barco: " << result[i].b << "  |  ";
        cout << "M: " << result[i].m << " C: " << result[i].c << " Lado del barco: " << result[i].b << endl;
    }
}

bool validAction(int action, State x)
{
    int m, c;
    if (action < 5)
    {
        if (x.b == 0)
        {
            return false;
        }
        m = x.m;
        c = x.c;
    }
    else
    {
        if (x.b == 1)
        {
            return false;
        }
        m = 3 - x.m;
        c = 3 - x.c;
    }
    action = action % 5;
    return (action == 0 && m >= 1) || (action == 1 && m >= 2) || (action == 2 && c >= 1) || (action == 3 && c >= 2) || (action == 4 && m >= 1 && c >= 1);
}

State move(int action, State x)
{
    int directionBoat;
    if (action < 5)
    {
        directionBoat = -1;
    }
    else
    {
        directionBoat = 1;
    }
    action = action % 5;
    x.b = (x.b + 1) % 2;
    switch (action)
    {
    case 0:
        x.m += directionBoat * 1;
        break;
    case 1:
        x.m += directionBoat * 2;
        break;
    case 2:
        x.c += directionBoat * 1;
        break;
    case 3:
        x.c += directionBoat * 2;
        break;
    case 4:
        x.m += directionBoat * 1;
        x.c += directionBoat * 1;
        break;
    default:
        break;
    }
    return x;
}

treenode idfsTree(State x, int limit, vector<State>* result)
{
    if (!((x.m == 0 || x.m >= x.c) && (3 - x.m == 0 || 3 - x.m >= 3 - x.c)))
    {
        return Fail;
    }
    if (x.m == 0 && x.c == 0 && x.b == 0)
    {
        result->push_back(x);
        return Goal;
    }
    if (limit == 0)
    {
        return Incomplete;
    }
    treenode node = Fail;
    for (int a = 0; a < NumberOfActions; a++)
    {
        if (validAction(a, x))
        {
            treenode st = idfsTree(move(a, x), limit - 1, result);
            if (st == Goal)
            {
                result->push_back(x);
                return Goal;
            }
            else if (st == Incomplete)
            {
                node = Incomplete;
            }
        }
    }
    return node;
}

void printNode(treenode node, int limit)
{
    cout << "Limit: " << limit << endl;
    switch (node)
    {
    case Fail:
        cout << "Fallo .. no se encontró ninguna solución" << endl;
        break;
    case Incomplete:
        cout << "Incompleto... sigue buscando" << endl;
        break;
    case Goal:
        cout << "¡Lo lograste! ¡Los tres misioneros y los caníbales cruzaron el río!" << endl;
        break;
    default:
        break;
    }
}