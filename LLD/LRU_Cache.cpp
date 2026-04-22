#include<bits/stdc++.h>
using namespace std;


// Node of a doubly linked list
class Node {
    public:
        int key;    // Key for node
        int value;  // Each node will store a value
        Node* prev; // Point to pevious node
        Node* next; // Point to the next node
        Node(int key, int val) {
            this->key = key;    // Initialize the key
            this->value = val;  // Initialize the value

            this->prev = nullptr;
            this->next = nullptr;
        }
};

class DoublyLinkedList {
    private:
        int size; // The current size of linked list
        Node* head; // Dummy head of the linked List
        Node* tail; // Dummy tail of the linked list

        // This is private so that caller can't update the size even though there is no insertion to the linked list
        void increaseSize() {
            this->size += 1; // This should be called whenever we make a insertion to the Linked list
        }

        // This is private so that caller can't update the size even though there is no deletion to the linked list
        void decreaseSize() {
            this->size -= 1; // This should be called whenever we make a deletion to the Linked list
        }

    public:
        DoublyLinkedList() {
            this->size = 0;
            
            // Initialize head and tail
            this->head = new Node(-1, -1);
            this->tail = new Node(-1, - 1);

            // Point head to tail
            this->head->next = this->tail;

            // Point tail to head
            this->tail->prev = this->head;
        }

        /// We always insert at the end of the linked list
        Node* insert(int key, int val) {
            Node* newNode = new Node(key, val);

            // Update the pointer of new node correctly
            newNode->prev = this->tail->prev;
            newNode->next = this->tail;

            this->tail->prev->next = newNode; // update the previous last element and connect to new node
            this->tail->prev = newNode; // update the tail's prev to point new node

            this->increaseSize();
            return newNode;
        }

        // Overloaded insert method to directly insert a node to linked list
        void insert(Node* newNode) {

            newNode->prev = this->tail->prev;
            newNode->next = this->tail;

            this->tail->prev->next = newNode; // update the previous last element and connect to new node
            this->tail->prev = newNode; // update the tail's prev to point new node

            this->increaseSize();
        }

        // Remove the last node of the linked list
        Node* remove() {
            if (head->next == tail) {
                cout << "No elemets left to remove\n";
                return nullptr;
            }
            Node* leastRecentlyUsedNode = head->next;

            head->next = leastRecentlyUsedNode->next;
            leastRecentlyUsedNode->next->prev = head;

            this->decreaseSize();
            return leastRecentlyUsedNode;
        }

        void remove(Node* node) {
            if (node == nullptr) {
                cout << "\n That's an empty node. return early!\n";
                return;
            }
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        void updateNodeToMostRecent(Node* node) {
            this->remove(node);
            this->insert(node);
        }

        /// print all the elements of linked list
        void printLinkedList() {
            Node* idx = this->head->next; // first element of the linked list

            // while we don't reach the tail of linked list
            while (idx != tail) { 
                cout << idx->value << " ";
                idx = idx->next;
            }
            cout << "\n";
        }

        int getSize() {
            return this->size;
        }
};

class Cache {
    public:
        int capacity;
        unordered_map<int, Node*> dict;
        DoublyLinkedList* linkedList;
        
};

class LRUCache: public Cache {
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            linkedList = new DoublyLinkedList;
        }

        // Enter a element to the cache
        void pushElement(int key, int value) {
            if (this->linkedList->getSize() >= this->capacity) {
                cout << "\nCache is full. We need to remove the least recent one to make some space\n";

                Node* removedNode = this->linkedList->remove();
                // Remove it from the dictionary
                this->dict.erase(removedNode->key);
                delete removedNode;
            }
            // Insert the value to linked list
            Node* newNode = this->linkedList->insert(key, value);
            this->dict[key] = newNode;

            // For testing
            this->linkedList->printLinkedList();
        }

        // Get an element
        void getElement(int key) {
            // Check if the element is present in the dictionary
            if (this->dict.find(key) == this->dict.end()) {
                cout << "\nThe element [" << key << "] is not present in the cache!\n";
                return;
            }
            // Cache hit
            Node* node = this->dict[key];
            cout << "\nThe value associated with key [" << key << "] is [" << node->value << "]\n"; 

            // Update the node position in linkedList
            this->linkedList->updateNodeToMostRecent(node);

            // For testing
            this->linkedList->printLinkedList();
        }
};

int main()
{   
    LRUCache* cache = new LRUCache(3);

    cache->pushElement(2, 22);
    cache->pushElement(3, 33);
    cache->pushElement(4, 44);
    
    cache->pushElement(5, 55);
    cache->getElement(2); // Check if this element is successfully removed from dictionary

    cache->getElement(4);
    cache->pushElement(6, 66);

    cache->getElement(3);
    cache->getElement(5);

    return 0;
}