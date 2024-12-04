#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){

    for(ll a=-100; a<100; a++){
        for(ll b=-100; b<=100; b++){
            for(ll c = -100; c<=100; c++){
                /*

                if (pow(a, b)== 343) {
                    if (pow(b, c)== 10) {
                        if (pow(c,a)== 7) {
                            cout<<" "<<a<<" "<<b<<" "<<c<<endl;
                        }
                    }
                }
                */

                
                if (a*b + c == 17){
                    if(b*c+a==19){
                        cout<<" "<<a<<" "<<b<<" "<<c<<endl;
                    }
                }
                
                
                

                

                /*
                if (pow(a, (abs(b)))== 16) {
                    if (pow(b, (abs(c)))== 512) {
                        if (pow(c, (abs(a)))== 6561) {
                            cout<<" "<<a<<" "<<b<<" "<<c<<endl;
                        }
                    }
                }
                */
            }
        }
    }

    return 0;
}