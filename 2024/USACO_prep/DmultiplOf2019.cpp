//https://atcoder.jp/contests/abc164/tasks/abc164_d
//this could be implemented with prefix sum, but I didn't

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    string S;
    cin>>S;

    int c=0;
    for (int l=4; l<S.size(); l++){
        for (int i=0; i+l<=S.size(); i++){
            if (stoll(S.substr(i, l))%2019==0) {
                c++;
                cout<<S.substr(i, l)<<endl;
            }
        }
    }

    cout<<c<<endl;
    return 0;
}