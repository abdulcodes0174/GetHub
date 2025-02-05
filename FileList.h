
#ifndef FILELIST_H
#define FILELIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "File.h"
#include "defs.h"

using namespace std;

// TODO make this a linked list

class FileList {
		
	public:
		//constructor
		FileList();
		//copy constructor
		FileList(const FileList& list);
		
		//destructor
		~FileList();
		
		//other
		bool add(File* f);
		File* get(const string& name) const;
		File* get(int) const;
		File* remove(const string& name);
		File* remove(int index);
		int size() const;
		bool isFull();
		void print();
	
	private:
		int numFiles;
		File** files;

		// Doubly-Linked List Node
		struct Node {
			Node* prev;
			Node* next;
			File* file;
		};

		Node* head;
		Node* tail;

};
#endif