#include <fstream>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

map<string, int> storage;

void seperate_items(string filename){
    ifstream file(filename);
    string company;
    string type;
    int amount=0;
    if(file.is_open()) 
    {
        while(file  >> company >> type >> amount)  {
            //cout << name <<" "<< amount <<" "<< endl;
            if (storage.find(company) == storage.end()) {
                
                //seat, meals, luggage, fee or tax
                if (type == "seat" || type == "meals" || type=="luggae" || type =="fee" || type == "tax") {
                    //add
                    storage[company]=amount;
                } else {
                    storage[company]=-amount;
                }
            } else {
                // found
                if (type == "seat" || type == "meals" || type=="luggae" || type =="fee" || type == "tax") {
                    //add
                    storage[company]+=amount;
                } else {
                    storage[company]-=amount;
                }
            }
        }
        
    }else{
        cout<< "file open fail" <<endl;
    }
    int ans=0;
    for (auto i: storage){
        ans = max(ans, i.second);
    }
    cout<<ans<<endl;
}
int main(){
    seperate_items("day1.txt");
}