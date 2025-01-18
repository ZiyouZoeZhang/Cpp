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
    return ((upper_bound(tree.begin(), tree.end(), r-1)-tree.begin()))-(lower_bound(tree.begin(), tree.end(), l)-tree.begin());
}

void ans(){
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

    vector<vector<int>> cons2 = cons;
    sort(cons.begin(), cons.end(), comp1());//left
    sort(cons2.begin(), cons2.end(), compr());

    vector<int> pre(N, 0);
    int L= 0, R = 0;
    int sum = 0;
    vector<int> need;
    int mneed = 0;
    int deleted = 0;


    FOR(i, 0, N){
        while(L<K && cons[L][0] <= tree[i]){
            mneed = max(mneed, cons[L][2]);
            need.pb(cons[L][2]);
            L++;
        }
        while(R < K && cons2[R][1] < tree[i]) {
            need.erase(remove(need.begin(), need.end(), cons2[R][2]), need.end());
            sum-=pre[lower_bound(tree.begin(), tree.end(), cons2[R][1])-tree.begin()];
            if (mneed == cons2[R][2]) {
                mneed = 0;
                FOR(i, 0, need.size()){
                    mneed = max(mneed, need[i]);
                }
            }
            R++;
        }

        if (mneed<=sum){
            deleted++;
        } else {
            sum++;
            pre[i+1]=sum;
        }
    }

   cout<<deleted<<endl;
}

int T;

int main(){
    cin>>T;
    FOR(i, 0, T){
        ans();
    }
}