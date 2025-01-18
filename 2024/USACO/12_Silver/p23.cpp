#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;

struct comp1 {
    bool operator() (vector<int> a, vector<int> b) {
        if (a[0]!=b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    }
};


struct compr {
    bool operator() (vector<int> a, vector<int> b) {
        if (a[1]!=b[1]) return a[1] < b[1];
        else return a[0] < b[0];
    }
};

vector<int> tree;


int howMany(int l, int r){
    return ((upper_bound(tree.begin(), tree.end(), r)-tree.begin()))-(lower_bound(tree.begin(), tree.end(), l)-tree.begin());
}

void ans(){
    int N, K; cin>>N>>K;

    tree.resize(N);
    vector<bool> vis(N, false);

    FOR(i, 0, N){
        cin>>tree[i];
    }

    sort(tree.begin(), tree.end());

    int largest = 0;

    vector<vector<int>> cons(K, vector<int>(3));
    FOR(i, 0, K){
        cin>>cons[i][0]>>cons[i][1]>>cons[i][2];
        largest = max(largest, cons[i][1]);
    }

    sort(cons.begin(), cons.end(), comp1());


    vector<int> current;
    int add = 0;

    FOR(i, 0, N){
        if (i>=tree.size()) {
            break;
        }
        if (tree[i] < cons[0][0]){tree.erase(tree.begin()+i); i--; continue;}
        else if (tree[i]>largest){tree.erase(tree.begin()+i); i--; continue;}

        while(add<cons.size() && cons[add][0]<=tree[i]){
            current.push_back(add);
            ++add;
        }


        bool ok = true;
        FOR(j, 0, current.size()){
            //if outdated
            if (cons[current[j]][1]<tree[i]) {
                current.erase(current.begin()+j);
                j--;
                continue;
            }

            if (cons[current[j]][2] == howMany(cons[current[j]][0], cons[current[j]][1])){
                i=upper_bound(tree.begin(), tree.end(), cons[current[j]][1])-tree.begin()-1;
                ok = false;
                break;
            }
        }

        if (ok){
            tree.erase(tree.begin()+i);
            i--;
        }
    }

    cout<<N-tree.size()<<endl;
}

int T;

int main(){
    cin>>T;
    FOR(i, 0, T){
        ans();
    }
}