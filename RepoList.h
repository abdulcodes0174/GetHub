#ifndef REPOLIST_H
#define REPOLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Repo.h"
#include "defs.h"

using namespace std;

// TODO make this a linked list

class RepoList {
		
	public:
		//constructor
		RepoList();
		//copy constructor
		RepoList(const RepoList& repo);
		
		//destructor
		~RepoList();
		
		//other
		bool add(Repo* r);
		Repo* get(const string& title) const;
		Repo* get(int index) const;
		Repo* remove(const string& title);
		Repo* remove(int index);
		int size() const;
		bool isFull() const;
		void print() const;
	
	private:
		int numRepos;
		Repo** repos;

		// Doubly-Linked List Node
		struct Node {
			Node* prev;
			Node* next;
			Repo* repo;
		};

		Node* head;
		Node* tail;
};
#endif
