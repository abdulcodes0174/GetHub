#include "FileList.h"

FileList::FileList() {
    numFiles = 0;
    head = nullptr;
    tail = nullptr;
}

// Copy Constructor
FileList::FileList(const FileList& list) {
    numFiles = 0; 
    head = nullptr;
    tail = nullptr;

    Node* current_node = list.head;
    while (current_node != nullptr) {
        // Make use of the add method to create
        // a new node with a copy of each
        // file within the list
        add(new File(*current_node->file));
        current_node = current_node->next;
    }
}

// Destructor
FileList::~FileList() {
    Node* current_node = head;
    while (current_node != nullptr) {
        Node* next_node = current_node->next;
        delete current_node->file; // Delete the File object within the node
        delete current_node;       // Delete the Node itself
        current_node = next_node;
    }
    numFiles = 0;
}

bool FileList::add(File* f) {
    // Create a new node to store the data in f
    Node* newNode = new Node;
    newNode->file = f;

    newNode->prev=nullptr; //Do this to avoid valgrind errors
    newNode->next=nullptr;

    // Case if this is the first node in the list
    if (size() == 0) {
        head = newNode;
        tail = newNode;
        // Append the number of files in the list
        numFiles++;
        return true;
    }

    // Traverse the list and use the File::lessThan method to
    // insert the new Node in the correct position
    // (just before the current_node)
    Node* current_node = head;

    while (current_node != nullptr && newNode->file->lessThan(*(current_node->file))) {
        current_node = current_node->next;
    }

    // Inserting at the front (new node is the head)
    if (current_node == head) {
        newNode->next = current_node;
        newNode->prev = nullptr;

        current_node->prev = newNode;

        head = newNode;
        numFiles++;
        return true;
    }
    
    // Inserting at the end (new node is the tail)
    if (current_node == nullptr) {
        newNode->prev = current_node;
        newNode->next = nullptr;

        current_node->next = newNode;

        tail = newNode;
        numFiles++;
        return true;
    }

    // Inserting at the middle (add just before the current_node)
    newNode->next = current_node;
    newNode->prev = current_node -> prev;
    
    current_node->prev->next = newNode;
    current_node->prev = newNode;
    numFiles++;
    return true;
}

File* FileList::remove(int index) {
    // Check if index is in bounds
    if (index < 0 || index >= size()) {
        return nullptr;
    }

    Node* current_node = head;
    // Case if removing the first node in the list (head)
    if (index == 0) {
        File* removed_file = current_node->file;

        if (head->next != nullptr) {
            head->next->prev = nullptr;
            head = head->next;
        } else {
            // this is the case if the list just became empty
            head = nullptr;
            tail = nullptr;
        }
        delete current_node;
        numFiles--;

        return removed_file;
    }

    // Case if removing the last node in the list (tail)
    if (index == size() - 1) {
        current_node = tail;
        File* removed_file = current_node->file;

        if (current_node->prev != nullptr) {
            current_node->prev->next = nullptr;
        }

        tail = current_node->prev;
        delete current_node;
        numFiles--;

        return removed_file;
    }

    // Middle Removal if Node is closer to the head
    // First, traverse to get to the index of the file we want to remove
    if ((index) < (size() / 2)) {
        for (int i = 0; i < index; ++i) {
        current_node = current_node->next;
    }
    } else {
        // Middle removal if Node is closer to the tail
        current_node = tail;
        for (int i = size() - 1; i > index; --i) {
            current_node = current_node->prev;
        } 
    }

    File* removed_file = current_node->file;

    if (current_node->next != nullptr) {
        current_node->next->prev = current_node->prev;
    }
    
    if (current_node->prev != nullptr) {
        current_node->prev->next = current_node->next;
    }

    delete current_node;
    numFiles--;
    
    return removed_file;
}

File* FileList::remove(const string& name) {
    Node* current_node = head;

    // Traverse through the list
    while (current_node != nullptr) { // Do this to ensure the loop doesn't go on forever past the tail
        if (current_node->file->getName() == name) {
            File* removed_file = current_node->file;

            // Case if node to be removed is the head
            if (current_node == head) {
                if (head->next != nullptr) {
                    head->next->prev = nullptr;
                    head = head->next;
                } else {
                    // this is the case if the list just became empty
                    head = nullptr;
                    tail = nullptr;
                }
            
            // Case if node to be removed is the tail
            }else if (current_node == tail) {
                current_node->prev->next = nullptr;
                tail = current_node->prev;
            
            // Case if node is in the middle
            } else {
                current_node->next->prev = current_node->prev;
                current_node->prev->next = current_node->next;
            }
            delete current_node;
            numFiles--;
            return removed_file;
            } 
        current_node = current_node->next;
        }
    // If no node with the matching name was found, return nullptr
    return nullptr;
}

File* FileList::get(const string& name) const{
    // Traverse through the list until name is found, then return
    // File object at that position
    Node* current_node = head;

    while (current_node != nullptr) {
        if (current_node->file->getName() == name) {
            return (current_node->file);
        }
        current_node = current_node->next;
    }
    // If no node with the matching name was found, return nullptr
    return nullptr; 
}

File* FileList::get(int index) const{
    // Check if index is in bounds
    if (index < 0 || index >= size()) {
        return nullptr;
    }

    Node* current_node = head;
    if ((index) < (size() / 2)) {
        for (int i = 0; i < index; ++i) {
        current_node = current_node->next;
    }
    } else {
        current_node = tail;
        for (int i = size() - 1; i > index; --i) {
            current_node = current_node->prev;
        } 
    }
    return current_node->file;
}


int FileList::size() const{
    return numFiles;
}

bool FileList::isFull() {
    return false; // Using doubly linked lists so technically an infinite data structure
}

