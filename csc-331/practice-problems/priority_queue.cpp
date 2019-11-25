#include <iostream>
using namespace std;


/*
 * Sample implementation of a priority queue using an array-based heap with a limit of 10 elements
 */
class PriorityQueue {
    int *queue;
    int count;

public:
    bool isEmpty();
    bool isFull();
    int front();
    int back();
    int size();
    void push(int num);
    void pop();
    void displayQueue();

    PriorityQueue();
    ~PriorityQueue();

private:
    void heapify();
};

/*
 * ~ Constructor and Destructor ~
 */

PriorityQueue::PriorityQueue(int size = 10) {
    count = 0;

    queue = new int[size];
}

PriorityQueue::~PriorityQueue() {
    delete [] queue;
}

/*
 * ~ Public Methods ~
 */

bool PriorityQueue::isEmpty() {
    if (count == 0) { return 1; }
    else { return 0; }
}

bool PriorityQueue::isFull() {
    if (count == 10) { return 1; }
    else { return 0; }
}

int PriorityQueue::size() {
    return count;
}

int PriorityQueue::front() {
    return queue[0];
}

int PriorityQueue::back() {
    return queue[size() - 1];
}

void PriorityQueue::push(int num) {
    if (isFull()) { cout << "Error: Queue Is Full" << endl; }

    // size() is 0 when PriorityQueue is first instantiated, the first element can then be inserted at queue[size()] i.e queue[0]
    queue[size()] = num;
    count++;

    // resort the array to be a max-heap
    heapify();
}

void PriorityQueue::pop() {
    if (isEmpty()) { cout << "Error: Queue Is Empty" << endl; return; }

    // move the last element in the heap to the top and decrement count
    queue[0] = queue[size() - 1];
    count--;
    // resort the array to be a max-heap
    heapify();
}

void PriorityQueue::displayQueue() {
    cout << "Contents of queue are (in order): ";

    for (int i = 0; i < size(); i++) {
        cout << queue[i] << " ";
    }

    cout << endl;
}

/*
 * ~ Private Methods ~
 */

void PriorityQueue::heapify() {
    // length / 2 - 1 = the last node in the tree with children (the last swappable node)
    for (int index = size() / 2 - 1; index >= 0; index--) {
        int largest_child_index;
        int last_element_index = size() - 1;

        int root_index = index;
        int root_of_subtree = queue[root_index];

        // to start, assume left child of root is the largest child
            // this is done to reduce the number of assignments:
                // if there is no right child, the left child must be the largest
                // if there is a right child and it is smaller than the left child, the largest_child_index does not need to be updated
                // if there is a right child and it is larger than the left child, then the largest_child_index can be updated
        largest_child_index = 2 * root_index + 1;

        // while the root has children
            // at this point, largest_child_index == left_child_index
            // so left_child_index <= size() - 1 requires that
            // the left child be no greater than the last element in the tree/the final leaf in the tree
        int loops = 0;
        while (largest_child_index <= last_element_index) {
            // if there is a right child
                // at this point largest_child_index is left_child_index
                // therefore if it's not the last element in the tree, there is a right child
            if (largest_child_index < last_element_index) {
                // if the right child is larger than the left child, update largest_child_index
                // after this point, largest_child_index refers to the actual largest child
                if (queue[largest_child_index] < queue[largest_child_index + 1]) { largest_child_index = largest_child_index + 1; }
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

int main() {
    PriorityQueue *queue = new PriorityQueue;

    queue->push(15);
    queue->push(60);
    queue->pop();
    queue->push(60);
    queue->push(72);
    queue->push(70);
    queue->pop();
    queue->push(72);
    queue->push(56);
    queue->pop();
    queue->pop();
    queue->pop();
    queue->push(70);
    queue->push(72);
    queue->push(60);
    queue->push(32);
    queue->push(62);
    queue->push(92);
    queue->pop();
    queue->push(92);
    queue->push(45);
    queue->push(30);

    queue->displayQueue();
}