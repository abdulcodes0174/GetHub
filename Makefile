objects = main.o View.o Control.o GetHub.o Repo.o File.o RepoList.o FileList.o Date.o Client.o
testobjects = test.o View.o TestControl.o Tester.o GetHub.o Repo.o File.o RepoList.o FileList.o Date.o Client.o

all: a3 a3test

debug: $(testobjects)
	g++  -std=c++11 -g -o a3test $(testobjects)

a3: $(objects)
	g++  -std=c++11 -o a3 $(objects)

a3test: $(testobjects)
	g++  -std=c++11 -o a3test $(testobjects)

test.o: test.cc TestControl.o
	g++  -std=c++11 -c test.cc

main.o: main.cc Control.o
	g++  -std=c++11 -c main.cc 

View.o: View.h View.cc 
	g++ -c View.cc

TestControl.o: TestControl.h TestControl.cc GetHub.o
	g++ -std=c++11 -c TestControl.cc

Tester.o: Tester.h Tester.cc
	g++ -std=c++11 -c Tester.cc

Control.o: Control.h Control.cc GetHub.o
	g++ -std=c++11 -c Control.cc

GetHub.o: GetHub.h GetHub.cc RepoList.o
	g++ -std=c++11 -c GetHub.cc

Client.o: Client.h Client.cc
	g++ -std=c++11 -c Client.cc

FileList.o: FileList.h FileList.cc
	g++ -std=c++11 -c FileList.cc

RepoList.o: RepoList.cc RepoList.h Repo.o
	g++ -std=c++11 -c RepoList.cc

Repo.o: Repo.cc Repo.h File.h
	g++ -c Repo.cc

File.o: File.cc File.h Repo.h
	g++ -std=c++11 -c File.cc

Date.o: Date.cc Date.h
	g++ -std=c++11 -c Date.cc

clean:
	rm -f a3 a3test *.o