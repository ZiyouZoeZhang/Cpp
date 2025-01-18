#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
using namespace std;

vector<long long> treePos;

void ans(){
    int N, K; 
    cin >> N >> K;

    treePos.resize(N);
    for(int i=0; i<N; i++){
        cin >> treePos[i];
    }
    sort(treePos.begin(), treePos.end());

    vector<vector<int>> cons(K, vector<int>(3));
    for(int i=0; i<K; i++){
        cin >> cons[i][0] >> cons[i][1] >> cons[i][2];
    }

    vector<vector<int>> cons2 = cons;


    sort(cons.begin(), cons.end(), 
         [](auto &a, auto &b){
             if(a[0] != b[0]) return a[0] < b[0];
             return a[1] < b[1];
         });

    sort(cons2.begin(), cons2.end(),
         [](auto &a, auto &b){
             if(a[1] != b[1]) return a[1] < b[1];
             return a[0] < b[0];
         });


    multiset<int> need;  
    int mneed = 0;
    int L = 0, R = 0; 
    int sumKept = 0; 
    int deleted = 0;

    FOR(i, 0, N){
        long long pos = treePos[i];
        while(L < K && cons[L][0] <= pos){
            need.insert(cons[L][2]);
            L++;
        }
        while(R < K && cons2[R][1] < pos){
            auto it = need.find(cons2[R][2]);
            if(it != need.end()) {
                need.erase(it);
            }
            R++;
        }

        if(!need.empty()){
            mneed = max(mneed, *need.rbegin());
        } else {
            mneed = 0;
        }

        if(sumKept >= mneed){
            deleted++;
        } else {
            sumKept++;
        }
    }

    cout << deleted << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        ans();
    }
    return 0;
}
