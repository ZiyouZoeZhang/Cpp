#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

vector <int> dataset (0);
int sum =0;

void readFile(string filename){
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        int i=0;
        while (getline(file, line)) {
            line=stoi(line);
            dataset.push_back(stoi(line));
            cout<<dataset.size()<<endl;
            sum=(sum+stoi(line))/(i+1);
            if (i)
            /*
            for (int j=0; j<=dataset.size(); j++){
                cout<<dataset[j]<<endl;
            }
            */
            //cout<<"hihihihih"<<endl<<endl;
            i+=1;
        }
        file.close();
    }
}

int main() {
    readFile("input.txt");
}