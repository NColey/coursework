/*
 * CSC331-1900
 * Natalie Coley
 * csc331-1900_coley_prog2.cpp
 *
 * Assignment #2 - Due 10/9/2019
 *
 * This program should implement a linked list data structure in C++.
 *
 * The full purpose of the assignment is to create, update, and manage
 * an alphabetized linked list of names and ages (using Add, Delete and List transactions).
 */

#include <iostream>
#include <string>
using namespace std;

/*
 * ~~ Person Struct ~~
 *      Representation of objects (people - identified by name and age) that can be added to the list
 */
struct Person {
    string name;
    string age;
    Person() { }
    Person(string n, string a): name(n), age(a) { }
};

/*
 * SortedPersonList class handles building and modifying a linked list of people (represented by the Person struct)
 *     Person elements are added to the list in ascending order, based on a comparison of the ascii values of their names;
 */

class SortedPersonList {
    /*
     * ~~ Node Struct ~~
     *      Representation of each Node in a LinkedList<Person>
     */
    struct Node {
        Person data;
        Node *next;
        Node *previous;
        Node(Node *n = nullptr, Node *p = nullptr): next(n), previous(p) { }
        Node(Person d, Node *n = nullptr, Node *p = nullptr): data(d), next(n), previous(p) { }
    };

    Node* last;
    void insert_ascending(Person input);
    bool is_duplicate(Person input);
    Node* find_element_by_name(string name);
    void delete_node(Node *node);
    void find_and_remove_node_by_name(string name);

public:
    Node *head;
    string transaction_result;
    SortedPersonList();
    ~SortedPersonList();
    void add(Person input);
    void list();
    void remove(string name);
};

/*
 * ~~ SortedPersonList -- Class Constructor & Destructor ~~
 */

SortedPersonList::SortedPersonList() {
    this->head = nullptr;
    this->last = nullptr;
}

SortedPersonList::~SortedPersonList(){
    Node *p;

    while (head != nullptr) {
        p = head;
        head = head->next;
        delete_node(p);
    }
    last = nullptr;
}

/*
 * ~~ SortedPersonList -- Public Methods ~~
 */

void SortedPersonList::add(Person input) {
    if (is_duplicate(input)) {
        transaction_result = "Name Not Added";
    }
    else { insert_ascending(input); transaction_result = "Name Added"; }
}

void SortedPersonList::list() {
    Node *current = head;

    while (current != nullptr) {
        cout << current->data.name << " " << current->data.age << endl;
        current = current->next;
    }
}

void SortedPersonList::remove(string name) {
    find_and_remove_node_by_name(name);
}

/*
 * ~~ SortedPersonList -- Private Methods ~~
 */

void SortedPersonList::insert_ascending(Person input) {

    /* Case 1: Empty List */
    if (head == nullptr) {
        Node *newNode = new Node(input);
        head = newNode;
        last = head;
    }
    /* Case 2: Insert At Start Of List */
    else if (input.name.compare(head->data.name) < 0) {
        Node *newNode = new Node(input, head, nullptr);
        head->previous = newNode;
        head = newNode;
    }
    /* Case 3: Insert At End Of List*/
    else if (input.name.compare(last->data.name) > 0) {
        Node *newNode = new Node(input, nullptr, last);
        last->next = newNode;
        last = newNode;
    }
    /* Case 4: Insert In Middle Of List */
    else {
        Node *current, *previous;
        current = head;

        while (current->data.name.compare(input.name) < 0) {
            previous = current;
            current = current->next;
        }
        Node *newNode = new Node(input, current, previous);
        current->previous = newNode;
        previous->next = newNode;
    }

}

void SortedPersonList::find_and_remove_node_by_name(string name) {
    Node *p, *node_to_remove;

    /* Case 1: Empty List */
    if (head == nullptr) {
        transaction_result = "Name Not Found";
    }
    /* Case 2: Deleting The First Node In List */
    else if (name == head->data.name) {
        node_to_remove = head;
        head = head->next;
        if (head != nullptr) { head->previous = nullptr; }
        else { last = head; }
        delete_node(node_to_remove);
        transaction_result = "Name Deleted";
    }
    /* Case 3: Deleting The Last Node In The List */
    else if (name == last->data.name) {
        node_to_remove = last;
        p = node_to_remove->previous;
        p->next = nullptr;
        last = p;
        delete_node(node_to_remove);
        transaction_result = "Name Deleted";
    }
    /* Case 4: Deleting A Node In The Middle Of The List */
    else {
        node_to_remove = find_element_by_name(name);
        if (node_to_remove == nullptr) {
            transaction_result = "Name Not Found";
        }
        else {
            p = node_to_remove->previous;
            p->next = node_to_remove->next;
            p->next->previous = p;
            delete_node(node_to_remove);
            transaction_result = "Name Deleted";
        }
    }
}

bool SortedPersonList::is_duplicate(Person input) {
    Node *current = head;
    bool inList = 0;

    while (current != nullptr && !inList) {
        if ( input.name == current->data.name) { inList = 1; }
        else { current = current->next; }
    }

    return inList;
}

SortedPersonList::Node* SortedPersonList::find_element_by_name(string name) {
    Node *current = head;
    Node *element = nullptr;
    bool found = 0;

    while (current != nullptr && found != 1) {
        if (current->data.name.compare(name) == 0) {
            element = current;
            found = 1;
        }
        current = current->next;
    }
    return element;
}

void SortedPersonList::delete_node(Node *node) {
    delete node;
    node = nullptr;
}

/*
 * PersonListManager class handles determining what actions to take based on user input
 */
class PersonListManager {
    string input;
    void get_next_input();
    void handle_user_input();

public:
    char transaction;
    string name;
    string age;
    void request_and_handle_user_instruction();
};

/*
 * ~~ PersonListManager - Public Methods ~~
 */

void PersonListManager::request_and_handle_user_instruction() {
    get_next_input();
    handle_user_input();
};

/*
 * ~~ PersonListManager -- Private Methods ~~
 */

void PersonListManager::get_next_input() {
    cout << "Please enter a transaction: " << endl;
    getline(cin, input);
    transaction = input[0];
    if (transaction == 'A') {
        name = input.substr(2, input.find_last_of(" ") - 2);
        age = input.substr(input.find_last_of(" ") + 1, input.length());
    }
    if (transaction == 'D') {
        name = input.substr(2, input.find_last_of(" ") - 2);
    }

}

void PersonListManager::handle_user_input() {
    SortedPersonList *list = new SortedPersonList();

    while(transaction != 'Q') {
        Person *person = new Person(name, age);

        switch(transaction) {
            case 'A':
                (*list).add(*person);
                cout << (*list).transaction_result << endl;
                break;
            case 'L':
                (*list).list();
                break;
            case 'D':
                (*list).remove(name);
                cout << (*list).transaction_result << endl;
                break;
        }

        get_next_input();
    }

    delete list;
}

/*
 * ~~ Main ~~
 */

int main() {
    PersonListManager manager;

    manager.request_and_handle_user_instruction();
}