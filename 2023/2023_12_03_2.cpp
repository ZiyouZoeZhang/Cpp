//4 6 4 4 6 4
//2 2 
//  2 2
//      2 2
//        2 2
//2 2 2 2 2 2

/*
0 1 0
1 1
  1 1

1 2

10 9 9

4 6 6 6 6 4
    2 2  

*/

#include <iostream>
#include <vector>
using namespace std;
long long cal();

int main(){
    long long T;
    cin>>T;
    for (long long i=0; i<T; i++){
        cout<<cal()<<endl;
    }
}

long long cal(){
    long long N, m=0, c=0;
    cin>>N;
    vector<long long> a(N);
    for (long long i=0; i<N; i++) {
        cin>>a[i];
        m=min(m, a[i]);
    }
    if (a.size()==1) return 0;
    if (a.size()==2){
        if (a[0]==a[1]) return 0;
        return -1;
    }
    for (long long i=0; i<N-2; i++) {
        if (a[i]<a[i+1]) {
            c+=(a[i+1]-a[i])*2;
            a[i+2]-=a[i+1]-a[i];
            a[i+1]=a[i];
        }
    }
    for (long long i=N-1; i>1; i--) {
        if (a[i-1]>a[i]) {
            c+=(a[i-1]-a[i])*2;
            a[i-2]-=a[i-1]-a[i];
            a[i-1]=a[i];
        }
    }
    for (long long i=0; i<N-2; i++){
        if (a[i]!=a[i+1]) return -1;
        if (a[i]<0) return -1;
    }
    if (a[a.size()-1]!=a[0]) return -1;
    return c;
}
