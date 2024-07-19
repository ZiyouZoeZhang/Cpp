#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
void cal();

//发现， 如果b<b+1, 1. b-1!=b; b=0 or 之前必定有一个数字或者b后面跟了一个更小的数字, 
//input.insert(input.begin()+n, number)
int main(){
    int test_cases;
    cin>>test_cases;
    for (int i=0; i<test_cases; i++) cal();
    
}

void cal(){
    vector<int> input;
    bool inserted=false;
    int changed = 0;
    int n,m;
    cin>>m;
    for (int i=1; i<m; i++){
        cin>>n;
        input.push_back(n);
    }
    for (int i=0; i<=input.size(); i++){
        if (input[i]<input[i+1]&&max(0,input[i+1])!=input[i]) {
            if(input[i-1]==input[i]){
                input[i]=0;
                changed = i;
            } else if (inserted==false){
                input.insert(input.begin()+i-1, 0);
                inserted=true;
            } else cout<<"inserted and idk what to do now"<<endl;
        }
        else if (input[i]>input[i+1]&&input[i-1]==input[i]&&max(0,input[i+1])!=input[i]){
            input[i]=0;
            changed = i;
        }
    }
    if (inserted==false&&changed==true) input.insert(input.begin()+changed+1, 0);
    else if(inserted==false&&changed==false) input.push_back(0);
    for (int i=0; i<input.size(); i++) cout<<input[i];
    cout<<endl;
}