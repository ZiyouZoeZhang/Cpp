#include<bits/stdc++.h>
using namespace std;
int N;

struct c {
    int x;
    int y;
    int p;
};

bool canReach(int x1, int y1, int x2, int y2, int p){
    if (sqrt((float)((pow((x2-x1), 2))+(pow((y2-y1), 2))))<=p) return true;
    return false;
}

int main(){
    cin>>N;
    vector<c> v;
    for (int i=0; i<N; i++){
        c a;
        cin>>a.x>>a.y>>a.p;
        v.push_back(a);
    }

    vector<vector<int>> adj(N);

    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            if (canReach(v[i].x, v[i].y, v[j].x, v[j].y, v[i].p)) adj[i].push_back(j);
            if (canReach(v[i].x, v[i].y, v[j].x, v[j].y, v[j].p)) adj[j].push_back(i);
        }
    }

    int m = 0, cow;

    for (int i=0; i<adj.size(); i++){ //for each starting cow
        queue<int> q;
        vector<bool> vis (N, false);
        q.push(i);
        vis[i]=true;
        int count = 1;
        while(!q.empty()){
            int a=q.front(); q.pop();
            for (int b: adj[a]){
                if (vis[b]) continue;
                vis[b] = true;
                q.push(b);
                count++;
            }
        }
        m = max(m, count);
    }

    cout<<m<<endl;
    return 0;
}