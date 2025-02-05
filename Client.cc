#include "Client.h"

Client::Client() {
    current_repo = nullptr;
}

Client::~Client() {
    // If object is nullptr, no need to do anything,
    // otherwise, we delete current_repo and set it to nullptr
    if (current_repo != nullptr) {
        delete current_repo;
        current_repo = nullptr;
    }
}



void Client::cloneRepo(GetHub& gethub, int repo) {

    // Making sure that current_repo doesn't already point to a
    // repo to avoid potential memory leaks
    if (current_repo != nullptr) {
        delete current_repo;
        current_repo = nullptr; // Redundant?? NOTE: Review lecture slides
    }
    
    Repo* downloaded_repo = nullptr;

    // Access the Repository from Gethub 
    if (gethub.download(repo, &downloaded_repo)) {
        if (downloaded_repo != nullptr) {
            // Create a deep copy of the repo 
            current_repo = new Repo(*downloaded_repo);
        } else {
            // Invlaid case, print error message for the user
            cout << "ERROR: Invalid index......." << repo << endl;
        }
    }
}

void Client::printRepo() const{
    if (current_repo != nullptr) {
        current_repo->printFiles();
    } else {
        cout << "ERROR: NULLPTR! No repository currently loaded......." << endl;
    }
}

void Client::printFileContents(int index) const{
    if (current_repo != nullptr) {
        current_repo->printContents(index);
    } else {
        cout << "ERROR: NULLPTR! No repository currently loaded.......";
    }
}