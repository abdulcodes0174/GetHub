#include "RepoList.h"

RepoList::RepoList() {
    numRepos = 0;
    head = nullptr;
    tail = nullptr;
}

// Copy Constructor
RepoList::RepoList(const RepoList& list) {
    numRepos = 0;
    head = nullptr;
    tail = nullptr;

    Node* current_node = list.head;
    while (current_node != nullptr) {
        // Make use of the add method to create
        // a new node with a copy of each
        // file within the list
        add(new Repo(*current_node->repo));
        current_node = current_node->next;
    }
}

RepoList::~RepoList() {
    Node* current_node = head;
    while (current_node != nullptr) {
        Node* next_node = current_node->next;
        delete current_node->repo; // Delete the Repo object within the node
        delete current_node;       // Delete the Node itself
        current_node = next_node;
    }
    numRepos = 0;
}


bool RepoList::add(Repo* r) {
    // We are adding to the back always so therefore we are always 
    // making this the new tail in the list
    Node* newNode = new Node;
    newNode->repo = r;

    newNode->prev = nullptr;
    newNode->next = nullptr;

    Node* current_node = tail;

    // Case if this is the first node in the list
    if (size() == 0) {
        head = newNode;
        tail = newNode;
    } else {
        // Inserting at the end (new node is the tail)
        newNode->prev = current_node;
        current_node->next = newNode;

        tail = newNode;
    }

    // Append the number of repos in the list
    numRepos++;
    return true;
}

Repo* RepoList::remove(int index) {
    // Check if index is in bounds
    if (index < 0 || index >= size()) {
        return nullptr;
    }

    Node* current_node = head;

    // Case if removing the first node in the list (head)
    if (index == 0) {
        Repo* removed_repo = current_node->repo;

        if (head->next != nullptr) {
            head->next->prev = nullptr;
            head = head->next;
        } else {
            // this is the case if the list just became empty
            head = nullptr;
            tail = nullptr;
        }
        delete current_node;
        numRepos--;

        return removed_repo;
    }

    // Case if removing the last node in the list (tail)
    if (index == size() - 1) {
        current_node = tail;
        Repo* removed_repo = current_node->repo;

        current_node->prev->next = nullptr;

        tail = current_node->prev;
        delete current_node;
        numRepos--;

        return removed_repo;
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

    Repo* removed_repo = current_node->repo;

    current_node->next->prev = current_node->prev;
    current_node->prev->next = current_node->next;

    delete current_node;
    numRepos--;
    
    return removed_repo;
}

Repo* RepoList::remove(const string& title) {
    Node* current_node = head;

    // Traverse through the list
    while (current_node != nullptr) { // Do this to ensure the loop doesn't go on forever past the tail
        if (current_node->repo->getTitle() == title) {
            Repo* removed_repo = current_node->repo;

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
            numRepos--;
            return removed_repo;
            } 
        current_node = current_node->next;
        }
    // If no node with the matching name was found, return nullptr
    return nullptr;
}

Repo* RepoList::get(int index) const{
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
    return current_node->repo;
}

Repo* RepoList::get(const string& title) const{
    // Traverse through the list until name is found, then return
    // File object at that position
    Node* current_node = head;

    while (current_node != nullptr) {
        if (current_node->repo->getTitle() == title) {
            return (current_node->repo);
        }
        current_node = current_node->next;
    }
    // If no node with the matching name was found, return nullptr
    return nullptr; 
}

bool RepoList::isFull() const{
    return false;
}

int RepoList::size() const{
    return numRepos;
}
