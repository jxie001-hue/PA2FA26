//goal:
//mode1: loop everything typed in
//mode2: print out everything within the provided file

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void newcat();
void newcat(char* argv[], int argc);


int main(int argc, char* argv[]){
    switch (argc){
        case 1:
            newcat();
            break;
        default:
            newcat(argv,argc);
            break;
    }


    return 0;
}

void newcat(){
    string x = "";


    while (!cin.eof()){
        getline(cin,x);
        cout<<x<<endl;
    }

}

void newcat(char* argv[], int argc){
    ifstream fin;
    string y = "";
    //test and find out to exit
    for (int x = 1; x< argc; x++){
        fin.open(argv[x]);
        if (fin.fail()){
            exit(1);
        }
        fin.close();

    }

    //print file informations
    for (int x = 1; x < argc; x++){
        fin.open(argv[x]);
        while(getline(fin,y)){
            cout<<y<<endl;
        
        }
        fin.close();

    }
    
    //debug
    cout<<"print finish"<<endl;
    
}


