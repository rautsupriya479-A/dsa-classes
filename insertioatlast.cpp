#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* start = NULL;
struct node* ptr;
int val;


void createnode() {
    cout << "Input value to insert: ";
    cin >> val;

    struct node* newnode =
        (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        cout << "Memory allocation failed\n";
        return;
    }

    newnode->data = val;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        ptr = start;

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }
}

void display() {
    ptr = start;

    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }

    cout << "NULL\n";
}

int main() {
    int n;

    cout << "Number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        createnode();
    }

    cout << "Existing linked list is: ";
    display();

    cout << "\nNow inserting a new value at last\n";
    createnode();

    cout << "After insertion at last: ";
    display();

    cout << "Freeing memory...\n";

    ptr = start;

    while (ptr != NULL) {
        struct node* nextnode = ptr->next;
        free(ptr);
        ptr = nextnode;
    }

    start = NULL;

    return 0;
}
