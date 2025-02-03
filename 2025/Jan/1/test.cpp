#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;



int main(){
    int N;
    cin>>N;

    vector<int> same(N, 0);

    if (N%2!=0){
        same[0] = (N-1)*(N)/2 +1;
        int count = ((N/2))*2;

        FOR(i, 1, N){
            count -= 2;
            same[i] = same[i-1]-count;
            if(i==N/2){
                count += 2;
            }
        }
        if(N==2){
            same[0] = 2;
            same[1] = 2;
        }
        
    }else{
        same[0] = (N-1)*(N)/2 +1;
        int count = ((N/2))*2-1;

        FOR(i, 1, N){
            count -= 2;
            same[i] = same[i-1]-count;
            if (i==N/2 -1){
                same[N/2] = same[N/2 -1];
                i++;
            }

        }
    }

    return 0;
}