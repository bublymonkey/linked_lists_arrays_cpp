#include "LinkedList.h"
#include <sstream>

LinkedList::LinkedList() : head(nullptr), _size(0) {}

LinkedList::~LinkedList() {
    // Clean up all nodes
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int LinkedList::append(int value) {
    int operations = 0;
    if (head == nullptr)
    {
        head = new Node(value);
        _size +=1;
        return 1;
    }
    else
    {
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
            operations += 1;
        }
        current->next = new Node(value);
        _size +=1;
        operations +=1;
        return operations; 


    }
    /*
     * Add value to the end of the list.
     * Return number of operations (traversals + insertion).
     * 
     * Hint: You need to traverse to the end, then add a new node.
     * Count each node you visit as one operation.
     */
    // TODO: Implement this
    return 0;
}

int LinkedList::prepend(int value) {
    
    Node* node1 = new Node(value);
    node1->next = head;
    head = node1;
    _size +=1;
    return 1;


    /*
     * Add value to the beginning of the list.
     * Return number of operations.
     * 
     * Hint: This should be O(1) - just update the head!
     */
    // TODO: Implement this
}

int LinkedList::insert_at(int index, int value) {
    int currentIndex = 0;
    int operations = 0;
    Node* current = head;
    if (index == 0){
        Node* node1 = new Node(value);
        node1->next = head;
        head = node1;
        _size +=1;
        return 1;
    }
    while(currentIndex != index -1){
        
        operations++;
        if(current->next == nullptr){
             return {-1};
         }
         
        current = current->next;
        currentIndex++;
        }
        if (currentIndex == index -1 ){
            Node* temp = current->next;
            Node* node2 = new Node(value);
            current->next = node2;
            node2->next = temp;
            _size++;

    }


    
    /*
     * Insert value at the given index (0-indexed).
     * Return number of operations (traversals + insertion).
     * 
     * Hint: Traverse to index-1, then insert after that node.
     */
    // TODO: Implement this
    return 0;
}

std::pair<int, int> LinkedList::get(int index) {
    
    int operations = 0;
    
    if (head == nullptr){
        return {-1,operations};
    }
    Node* current = head;
    int currentIndex = 0;

    while(current != nullptr){
        operations++;

        if (currentIndex == index){
            return {current->data,operations};
        }
        current = current->next;
        currentIndex++;
    }
    return{-1,operations};


    /*
     * Get value at given index.
     * Return (value, operations) or (-1, operations) if out of bounds.
     * 
     * Hint: Traverse from head, counting as you go.
     */
    // TODO: Implement this
    return {-1, 0};
}

std::pair<int, int> LinkedList::search(int value) {
    int operations = 0;
    int index = 0;
    Node* current = head;
    if (head == nullptr){
        return {-1,0};
    }
    while(value != current->data && current->next != nullptr)
    {
        current = current->next;
        operations++;
        index++;

        

    }
    if (current->data == value)
    {
        return {index,operations};
    }


    /*
    
     * Search for value in the list.
     * Return (index, operations) or (-1, operations) if not found.
     * 
     * Hint: Traverse and count operations until you find it or reach the end.
     */
    // TODO: Implement this
    return {-1, 0};
}

std::pair<bool, int> LinkedList::remove(int value) {
    int operations = 0;
    Node* current = head;

    if (current == nullptr) {
        return {false, 1};
    }

    if (current->data == value) {
        head = current->next; 
        delete current;
        _size--;
        return {true, 1};
    }

    while (current->next != nullptr) {
        operations++;

        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            _size--;
            return {true, operations};
        }

        current = current->next;
    }

    return {false, operations};
}
    

    /*
     * Delete the first occurrence of value.
     * Return (success, operations).
     * 
     * Hint: Find the node before the one to delete, then update its 'next' pointer.
     * Don't forget to delete the removed node to avoid memory leaks!
     */
    // TODO: Implement this


int LinkedList::size() const {
    return _size;
}

std::string LinkedList::display() const {
    if (!head) {
        return "[]";
    }
    
    std::stringstream ss;
    ss << "[";
    Node* current = head;
    while (current) {
        ss << current->data;
        if (current->next) {
            ss << " -> ";
        }
        current = current->next;
    }
    ss << "]";
    return ss.str();
}

bool LinkedList::has_cycle() const {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}