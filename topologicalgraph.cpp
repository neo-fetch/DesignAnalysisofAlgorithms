#include <iostream>
using namespace std;
// struct Node
// {
//     int indegree;
//     int data;
//     struct Node *next;
// };

struct Node
{
    int indegree;
    int data;
    struct Node *next;
};

typedef struct Node nde;

int priority[100];
nde *adjacency[20];
struct Node *head = NULL;


void insert(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    new_node->indegree = 0;
    head = new_node;
}


void append(int new_data)
{
    struct Node *ptr;
    ptr = head;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    while (ptr != NULL)
    {
        ptr = ptr->next;
    }
    new_node->data = new_data;
    new_node->next = NULL;
    ptr->next = new_node;
}

void display()
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " indeg: ";
        cout << ptr->indegree << ", ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void appendDegree(int node)
{
    struct Node *ptr;
    ptr = head;
    int i = 1;
    while (i < node)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
        i = i + 1;
    }
    ptr->indegree = ptr->indegree+1;
    display();
}

int main()
{
    int nodes;
    cout << "enter the number of nodes: " << endl;
    cin >> nodes;
    int j = 1, data;
    while (j <= nodes)
    {
        cout << "node: " << (j) << endl;
        cout << "enter data: " << endl;
        cin >> data;
        insert(data);
        j = j + 1;
    }
    cout << "nodes: " << endl;
    display();
    int i = 1;
    while (i <= nodes)
    {
        cout << "node: " << i << endl;
        int ch, node;
        int j = 0;
        while (j < 20)
        {
            cout << "Enter choice: " << endl;
            cout << "1 if there exists a link to node " << i << endl;
            cout << "2 if there is no link anymore" << endl;
            cin >> ch;
            if (ch==1)
            {
                cout << "enter the node that it is linked to:" << endl;
                cin >> node;
                appendDegree(node);                
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

    display();

    return 0;
}
