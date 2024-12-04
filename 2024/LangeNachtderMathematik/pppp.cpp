#include <bits/stdc++.h>
using namespace std;

int main(){

    int ans = 0;
    for(int b=1; b<2024; b++){
        for(int a=1; a<=b; a++){
            int sum = 0;
            for(int count=a; count>=0; count--){
                sum+=(b-count)*(a-count);
            }
            if (sum==2024){
                cout<<a<<" "<<b<<endl;
            }
        }
    }

    return 0;

}