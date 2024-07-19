//从左往右，记录最大下标，如果有小的下标，count++
//USACO 2022 February Contest, Bronze
//Problem 2
//my dad's version (which doesn't work)
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N;
    cin>>N;
    vector<int> a(N);
    vector<int> b(N);
    int count=0;
    for (int i=0; i<N; i++)
        cin>>a[i];
    for (int i=0; i<N; i++)
        cin>>b[i];
}

void old(){
    int N;
    cin>>N;
    vector<int> a(N);
    vector<int> b(N);
    int count=0;
    for (int i=0; i<N; i++)
        cin>>a[i];
    for (int i=0; i<N; i++)
        cin>>b[i];
    for (int i=0; i<N; i++){
        //old location = aloc - a.begin(), new location = i
        auto h=find(a.begin(), a.end(), b[i]);
        if ( h-a.begin() != i){
            a.erase(h);
            a.insert(a.begin()+i, b[i]);
            count++;
        }
    }
    cout<<count;
}