// -- essential_libraries_and_namespace

#include <iostream>
using namespace std;

// -- additional_libraries
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
// -- additional_libraries -- azur3
// #include "TimerClock.h"

// Classes

struct node
{
    int data;
    node *prev;
    node *next;
};

#if 0
class node
{

public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        next = NULL;
    }

    // create a fucntion to a first node
    void addNode_atlast(node *head, int d)
    {
        node *newNode = new node(d);
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // create a traversal funciton for linked list traversal
   
    void LinkedList_traversal(node *head)
    {

        while (head != NULL)
        {
            cout << head->data << endl;
            head = head->next;
        }
    }
};
#endif
// Functions

// Traversal funtion for ll
void ViewLL(struct node *ptr)
{
    int counter = 0;
    while (ptr != NULL)
    {
        cout << "At node "<<counter << ". " << ptr->data << endl;
        ptr = ptr->next;
        counter++;
    }
}
int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // -- Main Function code --

    //  Creating Node
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;

    // allocating memomry
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));

    // Forward Linking
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;

    // backward Linking
    forth->prev = third;
    third->prev = second;
    head->prev = second;

    // Data entry
    head->data = 1;
    second->data = 2;
    third->data = 3;
    forth->data = 4;

    ViewLL(head);

    return 0;
}