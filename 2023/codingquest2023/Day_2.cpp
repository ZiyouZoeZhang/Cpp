#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

vector<int> myList (0);
int count_1 = 0;
string number = "";
float avg=0;

string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

//34132
//31114
//53800

void readFile(string filename){
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            //cout<<line<<endl;
            //check whether meeting first criteria
            count_1=0;
            for (int i=0; i<toBinary(stoi(line)).size(); i++){
                count_1+=toBinary(stoi(line))[i];
            }
            if ( count_1 % 2==0){
                //cout<<toBinary(stoi(line))<<"; "<<toBinary(stoi(line)).size()<<endl;
                //meets
                //
                number=toBinary(stoi(line));
                if(toBinary(stoi(line)).size()==16){
                    //cout<<"yes"<<endl;
                    number[0]='0';
                    
                }
                myList.push_back(stoi(number,0,2));
                //cout<<stoi(number,0,2)<<endl;
                //cout<<line<<endl<<endl;
            }
        }
        file.close();
    }
    for (int i =0; i<myList.size(); i++){
        avg+=myList[i];
    }
    avg=avg/myList.size();
    cout<<avg<<endl;
    //end calculate avg
}
 
int main(){
    readFile("Day_2.txt");
}

