Compilation Instructions: Navigate to project directory and then run make all,
                          run ./a3 and ./a3test to see the results. 

Classes OverView:

The Date class (Entity object):
(a) Contains date information.

The File class (Entity object):
(a) Contains information about the File (name, content, last date modified)

The Repo class (Entity object):
(a) Contains information about the Repo (title, owner)
(b) Manages a collection of Files

The FileList class (Collection object):
(a) Data structure for File pointers

The RepoList class (Collection object):
(a) Data structure for Repo pointers

The GetHub class (Control, Collection, View object):
(a) Manages a collection of Repos.
(b) Provides services to add, delete, access, and print Repos and the Files in the Repos.
(c) Prints (error) messages to std::cout

The View class (Boundary object):
(a) Presents a menu, takes input from the user

The Control class (Control object):
(a) Manages the interaction of the other objects.

The TestControl class (Control object):
(a) Manages the interaction of the other objects in order to run tests

The Tester class:
(a) Provides testing functionality
