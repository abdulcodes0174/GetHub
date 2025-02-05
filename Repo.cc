#include "Repo.h"


Repo::Repo(const string& title, const string& owner): title(title), owner(owner) {
	fileList = new FileList();
}

Repo::Repo(const Repo& repo){
	title = repo.title;
	owner = repo.owner;
	fileList = new FileList();
	File* ep;
	for (int i = 0; i < repo.getNumFiles(); ++i){
		ep = repo.fileList->get(i);
		// TODO does not check if it is full
		if (!(fileList->isFull())) {
			fileList->add(new File(*ep));
		}
	}
}


Repo::~Repo(){
	for (int i = 0; i < fileList->size(); ++i){
		delete fileList->get(i);
	}
	delete fileList;
}

//getter
const string& Repo::getTitle() const{
	return title;
}

const string& Repo::getOwner() const{
	return owner;
}

//other
int Repo::getNumFiles() const{
	return fileList->size();
}

bool Repo::addFile(const string& title, const string& content,const  Date& d){
	if (fileList->isFull()) return false;
	fileList->add(new File(title, content, d));
	return true;
}

// File* Repo::get(int index) const{
// 	return fileList->get(index);
// }

void Repo::printContents(int file) const{
	cout << endl;
	File* f = fileList->get(file);
	if (f != nullptr)
		f->printContents();
	else{
		cout<<"File not found"<<endl;
	}
}

bool Repo::removeFile(int index){
	File* goner = fileList->remove(index);
	if (goner == nullptr) return false;
	delete goner;
	return true;
}

bool Repo::lessThan(const Repo& p) const{
	return title < p.title;
}



void Repo::print() const{
	cout<<"Title:   "<<title<<endl;
	cout<<"owner:    "<<owner<<endl<<endl;
}

void Repo::printFiles() const{
	print();
	for (int i = 0; i < fileList->size(); ++i){
		cout << i << ") ";
		fileList->get(i)->print();
		cout << endl;
	}
}

// void Repo::printFileContents(int index) const{
// 	if (index < 0 || index >= fileList->size()){
// 		cout << "File not found." << endl;
// 		return;
// 	};
// 	cout << endl;
// 	cout<<"Title:   "<<title<<endl;
// 	cout<<"owner:    "<<owner<<endl<<endl;
// 	fileList->get(index)->play();
// }