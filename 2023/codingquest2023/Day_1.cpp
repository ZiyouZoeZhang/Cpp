#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;

map<string, int> storage;


void seperate_items(string filename){
    ifstream file(filename);
    string index;
    string name;
    int amount = 0, ans = 1, cur=0;

    if(file.is_open()) 
    {
        while(file  >> index >> amount >> name)  {
            //cout << name <<" "<< amount <<" "<< endl;
            if (storage.find(name) == storage.end()) {
                // not found
                storage[name]=amount;
            } else {
                // found
                storage[name]+=amount;
            }
        }
        for (auto i: storage){
            cur=i.second%100;
            cout << i.first << " " << i.second<<" cur = "<<cur<<endl; 
            ans = ans*cur;
            cout<<"ans "<<ans<<endl;
        }
        cout<<"ans "<<ans<<endl;
    }else{
        cout<< "file open fail" <<endl;
    }
}
 
int main(){
    seperate_items("Day_1.txt");
}