/*
 * CSC331-1900
 * Natalie Coley
 * csc331-1900_coley_prog4.cpp
 *
 * Assignment #4 - Due 11/25/2019
 *
 * This program should implement a priority queue data structure in C++ via a user-defined class, specifically an array-based heap.
 *
 * The full purpose of the assignment is to create a computer repair scheduling application, that takes in computer repair orders and
 * service commands, following a specific format, schedules them based on priority in a queue, and then services each request in order.
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
 * ############################################
 * ##                                        ##
 * ##  Priority Queue                        ##
 * ##                                        ##
 * ##  Implementation:                       ##
 * ##      array based heap                  ##
 * ##                                        ##
 * ############################################
 */

template <class T>
class QueueADT {
public:
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual T front() const = 0;
    virtual T back() const = 0;
    virtual int size() const = 0;
    virtual void push(const T& element) = 0;
    virtual void pop() = 0;
};

/*
 * PriorityQueue class is an implementation of a priority queue using an array-based heap
 *     The queue has a limit of 10 elements
 */

template <class T>
class PriorityQueue: QueueADT<T> {

    /*
     * ~~ QueueElement Struct ~~
     *      Representation of each element in the PriorityQueue
     *      Struct is private, used only to assist with sorting elements in the queue
     */
    struct QueueElement {
        T element;
        int order_received;
        QueueElement() { }
        QueueElement(const T& e, const int o): element(e), order_received(o) { }
        /*
         * QueueElements are sorted in the queue based on value of the element itself,
         * and if those values are equal, by the order in which they were added to the queue
         * (first-come-first-served).
         */
        bool operator==(QueueElement const& rhs) const {
            return this->element == rhs.element && this->order_received == rhs.order_received;
        }
        bool operator!=(QueueElement const& rhs) const { return !operator==(rhs); }
        bool operator<(QueueElement const& rhs) const {
            if (this->element == rhs.element) { return this->order_received > rhs.order_received; }
            else { return this->element < rhs.element; }
        }
        bool operator>(QueueElement const& rhs) const {
            if (this->element == rhs.element) { return this->order_received < rhs.order_received; }
            else { return this->element > rhs.element; }
        }
        bool operator<=(QueueElement const& rhs) const { return !operator>(rhs); }
        bool operator>=(QueueElement const& rhs) const { return !operator<(rhs); }
    };

    QueueElement *queue;
    int count;
    int order_received;
    void copy(const PriorityQueue<T>& stack_to_copy);
    void heapify();

public:
    const PriorityQueue<T>& operator=(const PriorityQueue<T>& other_queue);
    bool isEmpty() const;
    bool isFull() const;
    T front() const;
    T back() const;
    int size() const;
    void push(const T& element);
    void pop();
    void displayQueue();

    PriorityQueue();
    PriorityQueue(const PriorityQueue<T>& other_queue);
    ~PriorityQueue();
};

/*
 * ~ Constructor and Destructor ~
 */

template <class T>
PriorityQueue<T>::PriorityQueue() {
    count = 0;
    order_received = 0;

    queue = new QueueElement[10];
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& other_queue) {
    copy(other_queue);
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
    queue = nullptr;
    delete [] queue;
}

/*
 * ~ Operator Overloading ~
 */

template <class T>
const PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other_queue) {

    // avoid self copy when assigning, as PriorityQueue class has pointer member values
    if (this != &other_queue) {
        copy(other_queue);
    }
    return *this;
}

/*
 * ~ Public Methods ~
 */

template <class T>
bool PriorityQueue<T>::isEmpty() const {
    return (count == 0);
}

template <class T>
bool PriorityQueue<T>::isFull() const {
    return (count == 10);
}

template <class T>
int PriorityQueue<T>::size() const {
    return count;
}

template <class T>
T PriorityQueue<T>::front() const {
    return queue[0].element;
}

template <class T>
T PriorityQueue<T>::back() const {
    return queue[size() - 1].element;
}

template <class T>
void PriorityQueue<T>::push(const T& newElement) {
    order_received++;
    QueueElement *queueElement = new QueueElement(newElement, order_received);
    // size() is 0 when PriorityQueue is first instantiated, the first element can then be inserted at queue[size()] i.e queue[0]
    queue[size()] = *queueElement;
    count++;

    // resort the array to be a max-heap
    heapify();
}

template <class T>
void PriorityQueue<T>::pop() {
    // move the last element in the heap to the top and decrement count
    queue[0] = queue[size() - 1];
    count--;
    // resort the array to be a max-heap
    heapify();
}

template <class T>
void PriorityQueue<T>::displayQueue() {
    cout << "Contents of queue are (in order): ";

    for (int i = 0; i < size(); i++) {
        cout << queue[i].element << " ";
    }

    cout << endl;
}

/*
 * ~ Private Methods ~
 */

template <class T>
void PriorityQueue<T>::copy(const PriorityQueue<T>& queue_to_copy) {
    queue = nullptr;
    delete [] queue;

    count = queue_to_copy.count;
    order_received = queue_to_copy.order_received;

    queue = new QueueElement[10];

    for (int i = 0; i < queue_to_copy.size() - 1; i++) {
        queue[i] = queue_to_copy[i];
    }
}

template <class T>
void PriorityQueue<T>::heapify() {
    // length / 2 - 1 = the last node in the tree with children (the last swappable node)
    for (int index = size() / 2 - 1; index >= 0; index--) {
        int largest_child_index;
        int last_element_index = size() - 1;

        int root_index = index;
        QueueElement root_of_subtree = queue[root_index];

        // to start, assume left child of root is the largest child
        // this is done to reduce the number of assignments:
            // if there is no right child, the left child must be the largest
            // if there is a right child and it is smaller than the left child, the largest_child_index does not need to be updated
            // if there is a right child and it is larger than the left child, then the largest_child_index can be updated
        largest_child_index = 2 * root_index + 1;

        // while the root has children, at this point in the method,
        // largest_child_index == left_child_index
        // so left_child_index <= size() - 1 requires that
        // the left child be no greater than the last element in the tree/the final leaf in the tree
        while (largest_child_index <= last_element_index) {
            // if there is a right child
            // at this point largest_child_index is left_child_index
            // therefore if it's not the last element in the tree, there is a right child
            if (largest_child_index < last_element_index) {
                // if the right child is higher priority than the left child, update largest_child_index
                // after this point, largest_child_index refers to the actual largest child
                if (queue[largest_child_index] <= queue[largest_child_index + 1]) {
                    largest_child_index = largest_child_index + 1;
                }

                // if the right child is greater than the left child, update largest_child_index
                // after this point, largest_child_index refers to the actual largest child
                if (queue[largest_child_index] < queue[largest_child_index + 1]) {
                    largest_child_index = largest_child_index + 1;
                }
            }

            // if the root is greater than its largest child, the subtree is already a heap
            if (root_of_subtree > queue[largest_child_index]) { break; }

            // replace the root with its largest child
            queue[root_index] = queue[largest_child_index];
            // set the next root to be the largest child of the original root, to check if it's a heap and resort if needed
            root_index = largest_child_index;
            // find the left_child_index of the new root & set it as the largest_child_index (until proven otherwise)
            largest_child_index = 2 * root_index + 1;
        }
        // after all swaps have been made, insert the starting root into its new place as the root of the last sorted subtree
        queue[root_index] = root_of_subtree;
    }
}

/*
 * ############################################
 * ##                                        ##
 * ##  Computer Repair Scheduler             ##
 * ##                                        ##
 * ############################################
 */

/*
 * ~~ RepairOrder struct ~~
 *      Representation of computer repair orders to be scheduled, based on user input
 */
struct RepairOrder {
    string customer_id;
    // 4 digit computer model year
    int model_year;
    // submitted by user as "y" or "n" -- represents if the repair order is for a computer under warranty (1) or not (0)
    bool under_warranty;
    int priority() const {
        if (under_warranty) { return 1;}
        else if (2019 - model_year < 6) { return 2; }
        else { return 3; }
    };

    bool operator==(RepairOrder const& rhs) const { return this->priority() == rhs.priority(); }
    bool operator!=(RepairOrder const& rhs) const { return !operator==(rhs); }
    bool operator<(RepairOrder const& rhs) const { return this->priority() > rhs.priority(); }
    bool operator>(RepairOrder const& rhs) const { return this->priority() < rhs.priority(); }
    bool operator<=(RepairOrder const& rhs) const { return !operator>(rhs); }
    bool operator>=(RepairOrder const& rhs) const { return !operator<(rhs); }

    RepairOrder() { }
    RepairOrder(string c, int m, bool w): customer_id(c), model_year(m), under_warranty(w) { }
};

vector<string> process_user_input(string input) {
    vector<string> transaction;
    // determine what type of transaction the user has requested
    // & store the transaction details
    stringstream string_stream(input);
    while (string_stream.good()) {
        getline(string_stream, input, '-');
        transaction.push_back(input);
    }
    return transaction;
}

int main() {
    string input;
    vector<string> transaction;

    cout << "Please enter a repair request: " << endl;
    /*
     * assumes all transactions entered are either service requests in the format "service" or
     * 3 part, hyphen separated repair order requests in the format "customerId-modelYear-warrantyCode" where
     * modelYear is a 4 digit year and warrantyCode is either "y" or "n" or program termination requests
     * in the format "end-of-file"
     */

    PriorityQueue<RepairOrder> *repair_order_queue = new PriorityQueue<RepairOrder>;

    while(getline(cin, input)) {
        if (!input.compare("end-of-file")) {
            cout << "There are " << repair_order_queue->size() << " remaining repair orders in the queue." << endl;
            break;
        }

        transaction = process_user_input(input);

        if (transaction.size() == 1 && transaction.at(0) == "service") {
            if (repair_order_queue->isEmpty()) { cout << "Error: Queue Is Empty" << endl; }
            else {
                cout << "Servicing customer id: " << repair_order_queue->front().customer_id << endl;
                repair_order_queue->pop();
            }
        }
        if (transaction.size() == 3) {
            if (repair_order_queue->isFull()) { cout << "Error: Queue Is Full" << endl; }
            else {
                RepairOrder *repair_order = new RepairOrder(transaction.at(0), stoi(transaction.at(1)), transaction.at(2) == "y");
                repair_order_queue->push(*repair_order);
            }
        }
    }

    delete repair_order_queue;
}