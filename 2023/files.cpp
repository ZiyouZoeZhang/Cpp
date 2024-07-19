#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


//resources lets go



//if stream resources   https://cplusplus.com/reference/fstream/ifstream/ 
void writeFile(string filename, string input){
    ofstream outfile;
    outfile.open(filename,ios::app);
    outfile<<input<<endl;
    outfile.close();
} 

void readFile(string filename){
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout<<line<<endl;
        }
        file.close();
    }
}

//seperate items in a file
//must follow rules, no exceptions
void seperate_items(string filename){
    ifstream file(filename);
    int index;
    string name;
    int age;

    if(file.is_open()) 
    {
        while(file  >>index >> name >>age)  
        {
            cout << name <<" "<< age <<" "<< index << endl;
        }
    }else{
        cout<< "file open fail" <<endl;
    }

}


int main() {
    seperate_items("test.txt");
}