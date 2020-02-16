/**
 * Topological sort using adjacency lists
 * ~ MASSIVE thanks to murtuza
 * Mayank Deshpande - 18529
 * Koushik N - 
 * 
 * P.S - THIS WAS REALLY TOUGH!!
*/
#include <list>
#include <stack>

#include <iostream>
using namespace std;

class DAG
{
    int vertices;

    list<int> *adj; // list of addresses

    void checkVertex(bool checked[], int nde, stack<int> &Stack);

public:
    DAG(int vertices); 

    void addEdge(int nde, int lnk);

    void tpSort();
};
//to create the asyclic graph.
DAG::DAG(int vertices)
{
    this->vertices = vertices;

    adj = new list<int>[vertices];
}
//adding links 'lnk' to each vertex 'nde'
void DAG::addEdge(int nde, int lnk)
{
    adj[nde].push_back(lnk);
}
//checks if a vertex was initially visited. If it was visited, it means it was already done. 
void DAG::checkVertex(bool checked[], int nde, stack<int> &Stack)
{
    checked[nde] = true;

    list<int>::iterator i; // i use the .begin() and .end() iterator parameter of the vector list.

    for (i = adj[nde].begin(); i != adj[nde].end(); ++i)
    {
        if (!checked[*i])
        {    
            checkVertex(checked, *i, Stack); // i check each row in the adjacency list using 
                                            // the iterator, and recursively the linked vertices so long as they are not checked.
        }
    }

    Stack.push(nde); //after the loop, i push the node to the stack.
}

void DAG::tpSort()
{
    stack<int> Stack;

    bool *checked = new bool[vertices];
    for (int i = 0; i < vertices; i++)
    {
        checked[i] = false; //assign all unvisited.
    }
    for (int i = 0; i < vertices; i++)
    {
        if (checked[i] == false)
        {
            checkVertex(checked, i, Stack); //mark it visited and push it to stack for all vertices
        }
    }
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " "; // Once all vertices are visited, we pop em to give our priorities in order.
        Stack.pop();
        //et voila!
    }
}

int main()
{
    int nodes;
    cout << "enter the number of nodes: " << endl;
    cin >> nodes;
    DAG g(nodes);
    int i = 0, j;
    while (i <= nodes)
    {
        cout << "node: " << i << endl;
        int ch, node;
        j = 0;
        while (j < 20)
        {
            cout << "Enter choice: " << endl;
            cout << "1 if there exists a link to node " << i << endl;
            cout << "2 if there is no link anymore" << endl;
            cin >> ch;
            if (ch == 1)
            {
                cout << "enter the node that it is linked to:" << endl;
                cin >> node;
                g.addEdge(i, node);
            }
            else if (ch == 2)
            {
                std::cout << "moving on..." << std::endl;
                break;
            }
            j = j + 1;
        }

        i = i + 1;
    }

    cout << "sorting... " << endl;
    g.tpSort();

    return 0;
}