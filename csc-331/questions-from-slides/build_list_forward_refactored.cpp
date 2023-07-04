#include <iostream>
using namespace std;

struct nodeType {
    int info;
    nodeType *link;
};

nodeType* buildListForward();
void showList();
nodeType* insertNumAndReturnListHead();

int main() {
    showList();
    return 0;
}

nodeType* buildListForward() {
    return insertNumAndReturnListHead();
}

void showList() {
    nodeType *current, *head;
    head = buildListForward();
    current = head;

    cout << "List: ";
    while(current != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

nodeType* insertNumAndReturnListHead() {
    nodeType *first, *last, *newNode;
    int num;

    first = NULL;
    last = NULL;

    cout << "Enter a list of integers ending with -999." << endl;
    cin >> num;

    while(num != -999) {
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = NULL;

        if (first == NULL) {
            first = newNode;
            last = newNode;
        }

        else {
            last->link = newNode;
            last = newNode;
        }

        cin >> num;
    }

    return first;
}