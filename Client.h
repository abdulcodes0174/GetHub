#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "GetHub.h"

using namespace std;

class Client {
    public: 

        // Constructor
        Client();


        // Destructor
        ~Client();




        // Other
        void cloneRepo(GetHub& gethub, int repo);
        void printRepo() const;
        void printFileContents(int index) const;





    private: 

        // Member Variables
        Repo* current_repo;



};

#endif