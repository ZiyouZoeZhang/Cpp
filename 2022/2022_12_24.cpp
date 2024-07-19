
#include <iostream>
using namespace std;
int main(){
    int a[100], maxSize;
    cin>>maxSize;
    for (int i=0; i<maxSize; i++) cin>>a[i];
    for (int i=0; i<maxSize; i++){
        for (int j=maxSize-1; j>i; j--) {
            //last one 最大
            if (a[j]>a[j-1]){
                swap(a[j], a[j-1]);
            }
        }
    }
    for (int i=0; i<maxSize; i++) cout<<a[i]<<' ';
    return 0;
}

