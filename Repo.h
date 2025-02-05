#ifndef REPO_H
#define REPO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "File.h"
#include "FileList.h"
#include "defs.h"


using namespace std;


class Repo {
		
	public:
		//constructor
		Repo(const string& title, const string& owner);
		//copy constructor
		Repo(const Repo& repo);
		
		//destructor
		~Repo();

		//getter
		const string& getTitle() const;
		const string& getOwner() const;
		
		//other
		int getNumFiles() const;
		bool addFile(const string& title, const string& content,const Date& date);
		bool removeFile(int);
		// File* getFile(int) const;
		bool lessThan(const Repo&) const;
		void print() const;
		void printFiles() const;
		void printContents(int file) const;

	
	private:
		string title;
		string owner;
		FileList* fileList;
	
};
#endif
