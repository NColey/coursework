#include <iostream>
using namespace std;

struct nodeType {
    int info;
    nodeType *link;
};

void showList();
nodeType* insertNumAndReturnListHead();
bool alreadyInList(int num, nodeType *head);

int main() {
    showList();
    return 0;
}

void showList() {
    nodeType *current, *head;
    head = insertNumAndReturnListHead();
    current = head;

    cout << "List: ";
    while(current != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

nodeType* insertNumAndReturnListHead() {
    nodeType *head, *last, *current, *previous;
    int num;

    head = NULL;
    last = NULL;
    current = NULL;
    previous = NULL;

    cout << "Enter a list of integers ending with -999." << endl;
    cin >> num;

    while(num != -999) {

        while(!alreadyInList(num, head)) {
            if (head == NULL) { /* first element in list */
                head = new nodeType;
                head->info = num;
                head->link = NULL;
                last = head;
            }

            else {

                nodeType *newNode;
                newNode = new nodeType;
                newNode->info = num;

                /*
                 * conditions: you insert at top, if you insert between nodes, if you insert at end
                 *
                 * start with list head. if num is greater than head->info it should go after.
                 * if greater than all numbers it goes at end.
                 * if smaller than head->info it should go at start of list
                 *
                 *
                 *
                 * */

                if (head->info > num) { /* insert at start of the list */
                    newNode->link = head;
                    head = newNode;
                }
                else {
                    if (last->info < num) { /* insert at end of list */
                        newNode->link = NULL;
                        last->link = newNode;
                        last = newNode;
                    }
                    else {
                        current = head;

                        while(current->info < num) { /* insert in between list */
                            previous = current;
                            current = current->link;
                        }
                        newNode->link = current;
                        previous->link = newNode;
                    }
                }
            }
        }

        cin >> num;
    }

    return head;
}

bool alreadyInList(int num, nodeType *head) {
    nodeType *current;
    bool inList;

    inList = 0;

    current = head;

    while(current != NULL && !inList) {
        if ( num == current->info) { inList = 1; }
        else { current = current->link; }
    }

    return inList;
}