//USACO 2021 January Contest, Bronze
//Problem 2. Even More Odd Photos
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1084

#include<iostream>
using namespace std;

int main(){
    int a=0, b=0, n, c;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>c;
        if (c%2==0) b++;
        else a++;
    }
    int count=0;
    bool even=true;
    while(true){
        if (even==true){
            if (b>0) b--;
            else if (a>1) a-=2;
            else break;
            count++;
            even=!even;
        } else {
            if (a>0) a--;
            else break;
            count++;
            even=!even;
        }
    }
    if (a==1 && even) count--;
    cout<<count<<endl;
}