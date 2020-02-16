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
    struct Node *link[20];
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
void appendDegree(int node)
{
    struct Node *ptr;
    ptr = head;
    int i = 1;
    while (i != node + 1)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
        i = i + 1;
    }
}
void display()
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
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
        int ch;
        int j = 0;
        do
        {
            cout << "Enter choice: " << endl;
            cout << "1 if there exists a link to node " << i << endl;
            cout << "2 if there is no link anymore" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                cout << "enter the node that it is linked to:" << endl;
                cin >> node;
                appendDegree(node);
            }

            case 2:
            {
                cout << "moving to the next node..." << endl;
                break;
            }
            }
            j = j + 1;
        } while (j < 20);

        i = i + 1;
    }

    return 0;
}