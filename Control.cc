
#include <iostream>
#include <string>
#include <vector>
#include "Control.h"


vector<string> Control::menu ={
    "Print all repos",
    "Print repo",
    "Print file",
    "Remove repo",
    "Remove file\n\n Client functions",
    "Download repo",
    "Print client repo",
    "Print file content"
};

// void printRepos();
// void printRepo();
// void printFileContents();
// void removeRepo();
// void removeFile();


Control::Control(){
    
}

void Control::launch(){
    //make a view, get input, launch the appropriate test
    View view;
    int choice = -1;

    initGetHub();

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: printRepos(); break;
            case 2: printRepo(); break;
            case 3: printFileContents(); break;
            case 4: removeRepo(); break;
            case 5: removeFile(); break;
            case 6: downloadRepo(); break;
            case 7: printClientRepo(); break;
            case 8: printClientFileContent(); break;
        }
    }
}

void Control::downloadRepo(){
    //TODO finish this function

    // Variable to store the user's selected Repo
    int repo_index;

    // Show the user the current repositories
    getHub.printRepos();
    cout << "Please choose a repository by index to download" << endl;

    view.getNumber(repo_index);

    client.cloneRepo(getHub, repo_index);
}

void Control::printClientRepo(){
    //TODO finish this function
    client.printRepo();

}

void Control::printClientFileContent(){
    //TODO finish this function
    int file_index;

    printClientRepo();

    // Ask user for preffered file index
    cout << "Please choose a file by index to print its contents: " << endl;

    view.getNumber(file_index);

    // Call the Client's method to print the file content.
    client.printFileContents(file_index);


}

void Control::initGetHub(){
    cout<<"Initializing GetHub..."<<endl;
    for (int j = 0; j < 5; ++j){
        getHub.addRepo(repoTitles[j],owners[j]);
    }
    //we add the repos first, then the files for test purposes
     for(int j = 0; j < 5; ++j){  
        for (int i = 0; i <5; ++i){
            getHub.addFile(repoTitles[j],fileTitles[j][i], content[j][i], dates[j][i]);
        }
    }
}

void Control::printRepos(){
    getHub.printRepos();
}

void Control::printRepo(){
    int repo;
    getHub.printRepos();
    cout<<"Enter repo number: ";
    view.getNumber(repo);
    getHub.printRepo(repo);
}

void Control::printFileContents(){
    int repo, file;
    getHub.printRepos();
    cout<<"Enter repo number: ";
    view.getNumber(repo);
    getHub.printRepo(repo);
    cout<<"Enter file number: ";
    view.getNumber(file);
    getHub.printFileContents(repo,file);
}

void Control::removeRepo(){
    int repo;
    getHub.printRepos();
    cout<<"Enter repo number to delete: ";
    view.getNumber(repo);
    getHub.deleteRepo(repo);
    cout<<"Repo deleted."<<endl;
}

void Control::removeFile(){
    int repo, file;
    getHub.printRepos();
    cout<<"Enter repo number: ";
    view.getNumber(repo);
    getHub.printRepo(repo);
    cout<<"Enter file number to delete: ";
    view.getNumber(file);
    getHub.deleteFile(repo,file);
    cout<<"File deleted."<<endl;
}

const string Control::repoTitles[5] = {
    "TechTrendsUnleashed",
    "CulinaryExplorerHQ",
    "LaughLagoonNetwork",
    "FitnessFiestaRepo",
    "MindfulMysteriesShow"};

const string Control::owners[5] = {"Bob", "Sue", "Joe", "Mary", "Bill"};

// These do not make any sense - just for testing
const string Control::fileTitles[5][5] = {
    {"Lion", "Lion 2", "Fishbowl", "Alien", "Castle"},
    {"Love", "Anonymous", "Games","Music","Welcome"},
    {"Monkey", "Stranger","Ant","Turtle","Smile"},
    {"Crab","City","Apple","Pig","Dog"},
    {"Helicopter","Unlock","Santa's Sleigh", "Guitar","Whale"}
};

// some of these dates are out of order - on purpose for testing
 const Date Control::dates[5][5]={
    {Date(2024, 1, 1), Date(2023, 1, 2), Date(2024, 8, 3), Date(2022, 6, 4), Date(2023, 3, 5)},
    {Date(2024, 1, 1), Date(2023, 1, 2), Date(2024, 8, 3), Date(2022, 6, 4), Date(2023, 3, 5)},
    {Date(2023, 4, 15), Date(2024, 11, 7), Date(2023, 8, 22), Date(2024, 5, 12), Date(2023, 6, 30)},
    {Date(2023, 7, 18), Date(2024, 3, 12), Date(2023, 11, 5), Date(2024, 2, 20), Date(2023, 9, 9)},
    {Date(2024, 7, 25), Date(2023, 2, 14), Date(2024, 10, 8), Date(2023, 5, 28), Date(2024, 1, 19)},
 };


// Also nonsense
const string Control::content[5][5] = {
R"(
 ▄▀▀▀▀▀───▄█▀▀▀█▄
▐▄▄▄▄▄▄▄▄██▌▀▄▀▐██
▐▒▒▒▒▒▒▒▒███▌▀▐███
 ▌▒▓▒▒▒▒▓▒██▌▀▐██
 ▌▓▐▀▀▀▀▌▓─▀▀▀▀▀)",

R"(
┼┼┼┼┼┼┼┼▓▓▓▓┼┼┼
┼╔═▒▒▒▒▓▄░░▄▓┼┼
┼▀┼▒▒▒▓▓▒──▒▓▓┼
┼┼┼▒▌▒▐┼▓▓▓▓┼┼┼)",

R"(
─▀▀▌───────▐▀▀
─▄▀░◌░░░░░░░▀▄
▐░░◌░▄▀██▄█░░░▌
▐░░░▀████▀▄░░░▌
═▀▄▄▄▄▄▄▄▄▄▄▄▀═
)",

R"(
▒▒▄▀▀▀▀▀▄▒▒▒▒▒▄▄▄▄▄▒▒▒
▒▐░▄░░░▄░▌▒▒▄█▄█▄█▄█▄▒
▒▐░▀▀░▀▀░▌▒▒▒▒▒░░░▒▒▒▒
▒▒▀▄░═░▄▀▒▒▒▒▒▒░░░▒▒▒▒
▒▒▐░▀▄▀░▌▒▒▒▒▒▒░░░▒▒▒▒
)",
R"(
─────────█▄██▄█
█▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█
███┼█████▐████▌█████┼███
█████████▐████▌█████████
)",
R"(
█───▄▀▀▀▀▄─▐█▌▐█▌▐██
█──▐▄▄────▌─█▌▐█─▐▌─
█──▐█▀█─▀─▌─█▌▐█─▐██
█──▐████▄▄▌─▐▌▐▌─▐▌─
███─▀████▀───██──▐██
)",
R"(
─────█─▄▀█──█▀▄─█─────
────▐▌──────────▐▌────
────█▌▀▄──▄▄──▄▀▐█────
───▐██──▀▀──▀▀──██▌───
──▄████▄──▐▌──▄████▄──
)",
R"(
─▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄
█░░░█░░░░░░░░░░▄▄░██░█
█░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█
█░░░▀░░░▄▄▄▄▄░░██░▀▀░█
─▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀
)",
R"(
║░█░█░║░█░█░█░║░█░█░║
║░█░█░║░█░█░█░║░█░█░║
║░║░║░║░║░║░║░║░║░║░║
╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝
)",
R"(
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█
█░░║║║╠─║─║─║║║║║╠─░░█
█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█

)",
R"(
───▄██▄─────────────▄▄
──█████▄▄▄▄───────▄▀
────▀██▀▀████▄───▄▀
───▄█▀▄██▄████▄─▄█
▄▄█▀▄▄█─▀████▀██▀
)",
R"(
█▓▒▓█▀██▀█▄░░▄█▀██▀█▓▒▓█
█▓▒░▀▄▄▄▄▄█░░█▄▄▄▄▄▀░▒▓█
█▓▓▒░░░░░▒▓░░▓▒░░░░░▒▓▓█
)",
R"(
──▄──▄────▄▀
───▀▄─█─▄▀▄▄▄
▄██▄████▄██▄▀█▄
─▀▀─█▀█▀▄▀███▀
──▄▄▀─█──▀▄▄
)",
R"(
─▄▀▀▀▄────▄▀█▀▀█▄
▄▀─▀─▀▄▄▀█▄▀─▄▀─▄▀▄
█▄▀█───█─█▄▄▀─▄▀─▄▀▄
──█▄▄▀▀█▄─▀▀▀▀▀▀▀─▄█
─────▄████▀▀▀▀████─▀▄
)",
R"(
╔══╗░░░░╔╦╗░░╔═════╗
║╚═╬════╬╣╠═╗║░▀░▀░║
╠═╗║╔╗╔╗║║║╩╣║╚═══╝║
╚══╩╝╚╝╚╩╩╩═╝╚═════╝
)",
R"(
░░▄█▀▀▀░░░░░░░░▀▀▀█▄
▄███▄▄░░▀▄██▄▀░░▄▄███▄
▀██▄▄▄▄████████▄▄▄▄██▀
░░▄▄▄▄██████████▄▄▄▄
░▐▐▀▐▀░▀██████▀░▀▌▀▌▌
)",
R"(
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▄▄▄▒▒▒█▒▒▒▒▄▒▒▒▒▒▒▒▒
▒█▀█▀█▒█▀█▒▒█▀█▒▄███▄▒
░█▀█▀█░█▀██░█▀█░█▄█▄█░
░█▀█▀█░█▀████▀█░█▄█▄█░
████████▀█████████████
)",
R"(
┊┊┊┊┊┊┊╱▏┊┊┊┊┊┊┊
┊┊┊┊┊┊▕╱┊┊┊┊┊┊┊┊
┊┊┊╱▔▔╲┊╱▔▔╲┊┊┊┊
┊┊▕┈┈┈┈▔┈┈┈╱┊┊┊┊
┊┊▕┈┈┈┈┈┈┈┈╲┊┊┊┊
┊┊┊╲┈┈┈┈┈┈┈╱┊┊┊┊
┊┊┊┊╲▂▂▂▂▂╱┊┊┊┊┊
)",
R"(
▂╱▔▔╲╱▔▔▔▔╲╱▔▔╲▂
╲┈▔╲┊╭╮┈┈╭╮┊╱▔┈╱
┊▔╲╱▏┈╱▔▔╲┈▕╲╱▔┊
┊┊┊┃┈┈▏┃┃▕┈┈┃┊┊┊
┊┊┊▏╲┈╲▂▂╱┈╱▕┊┊┊
)",
R"(
╥━━━━━━━━╭━━╮━━┳
╢╭╮╭━━━━━┫┃▋▋━▅┣
╢┃╰┫┈┈┈┈┈┃┃┈┈╰┫┣
╢╰━┫┈┈┈┈┈╰╯╰┳━╯┣
╢┊┊┃┏┳┳━━┓┏┳┫┊┊┣
╨━━┗┛┗┛━━┗┛┗┛━━┻
)",
R"(
▀▀▀▀█▀▀▀▀
─▄▀█▀▀█──────▄
█▄▄█▄▄██████▀
▀▀█▀▀▀█▀▀
─▀▀▀▀▀▀▀
)",
R"(
──▄▀▀▀▄───────────────
──█───█───────────────
─███████─────────▄▀▀▄─
░██─▀─██░░█▀█▀▀▀▀█░░█░
░███▄███░░▀░▀░░░░░▀▀░░
)",
R"(
░╔╔╩╩╝
▄██▄
░░██████▄░░░░░░▄▄▄▄▄▄█
░░█▀█▀█▀█░░▄░▄████████
░▄▌▄▌▄▌▄▌░▀▄▄▄▄█▄▄▄▄█▄
)",
R"(
░▄▀▀▀▀▄░░▄▄
█░░░░░░▀▀░░█░░░░░░▄░▄
█░║░░░░██░████████████ 
█░░░░░░▄▄░░█░░░░░░▀░▀
░▀▄▄▄▄▀░░▀▀
)",
R"(
─────▀▄▀─────▄─────▄
──▄███████▄──▀██▄██▀
▄█████▀█████▄──▄█
███████▀████████▀
─▄▄▄▄▄▄███████▀
)"
};


