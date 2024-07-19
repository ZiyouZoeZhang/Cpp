/*
#include<iostream>
#include<vector>
#include <utility>
#define f first
#define s second
using namespace std;
vector< pair<int, int> > cow; //first weight second count
int N, M, K;

int main(){
    cin>>N>>M>>K;
    cow.resize(N);
    for (int i=0; i<N; i++){
        cin>>cow.first>>cow.s;
    }
    sort(cow.begin().f, cow.end().f, [&](int A, int B) { return A < B; });
    return 0;
}
*/