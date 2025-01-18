#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;

//sort left

struct comp {
    bool operator() (vector<int> a, vector<int> b) {
        if (a[1]!=b[1]) return a[1] < b[1];
        else return a[0] < b[0];
    }
};

vector<int> tree;


int howMany(int l, int r){
    return ((upper_bound(tree.begin(), tree.end(), l)-tree.begin())-(lower_bound(tree.begin(), tree.end(), r)-tree.begin()));

}


int ans(){
    int N, K; cin>>N>>K;

    tree.resize(N);

    FOR(i, 0, N){
        cin>>tree[i];
    }

    sort(tree.begin(), tree.end());

    vector<vector<int>> cons(K, vector<int>(3));
    FOR(i, 0, K){
        cin>>cons[i][0]>>cons[i][1]>>cons[i][2];
    }

    sort(cons.begin(), cons.end(), comp());
    cout<<endl;


    FOR(i, 0, N){ //tree
        

    }

    return 0;

}

int T;

int main(){
    cin>>T;
    FOR(i, 0, T){
        cout<<ans()<<endl;
    }
}

