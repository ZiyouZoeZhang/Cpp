#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;
//sort right

struct comp {
    bool operator() (vector<int> a, vector<int> b) {
        if (a[0]!=b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    }
};

vector<int> tree;


int howMany(int l, int r){
    return ((lower_bound(tree.begin(), tree.end(), r)-(upper_bound(tree.begin(), tree.end(), l)-tree.begin())-tree.begin()));
}


int ans(){
    int N, K; cin>>N>>K;

    tree.resize(N);
    vector<bool> vis(N, false);

    FOR(i, 0, N){
        cin>>tree[i];
    }

    sort(tree.begin(), tree.end());

    vector<vector<int>> cons(K, vector<int>(3));
    FOR(i, 0, K){
        cin>>cons[i][0]>>cons[i][1]>>cons[i][2];
    }

    sort(cons.begin(), cons.end(), comp());

    multiset<pair<int, int>>relevant; //ending pos, index

    int x = 0;
    int deleted = 0;

    FOR(i, 0, tree.size()){
        while(x<K && cons[x][0]<=tree[i]) relevant.insert({cons[x][1], x}), x++;//contrains trasting posistion smaller/euqals the current tree
/*
        if (tree[i] == 10){
            cout<<endl;
        }*/
        bool ok = true;

        for (auto itr = relevant.begin(); itr != relevant.end(); ++itr) {

            int ind=(itr->second);
            if (cons[ind][1] < tree[i]){
                auto temp = itr;
                ++itr;
                relevant.erase(temp);
                break;
                //if (relevant.empty()) break;
                //--itr;
            }

            /*
            int ind=(itr->second);
            if (cons[ind][1] < tree[i]){
                auto temp = itr;
                ++itr;
                if (temp!=relevant.end()) {
                    relevant.erase(temp);
                    if (relevant.empty()) break;
                    --itr;
                    continue;
                } else{
                    relevant.erase(temp);
                    ind = -1;
                }
            }
            */
            
            if (ind!=-1 && cons[ind][2] == howMany(cons[ind][0], cons[ind][1])) {
                ok = false;
                i = lower_bound(tree.begin(), tree.end(), cons[ind][1])-tree.begin()-1;
            }
            if (ind!=-1) int total = howMany(cons[ind][0], cons[ind][1]);

            if (!ok || ind==-1) break;
        }

        if (ok) {
            tree.erase(tree.begin()+i);
            deleted++;
            i--;
        }
    }

    return N-tree.size();
}

int T;

int main(){
    cin>>T;
    FOR(i, 0, T){
        cout<<ans()<<endl;
    }
}

