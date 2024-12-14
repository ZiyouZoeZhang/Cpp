#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
//#define s second
#define pb push_back
using namespace std;


void topologicalSortUtil(int v, vector<vector<int> >& adj, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    Stack.push(v);
}


vector<int> topologicalSort(vector<vector<int> >& adj, int V)
{
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    vector<int> ans;

    while (!Stack.empty()) {
        ans.pb(Stack.top());
        Stack.pop();
    }
    return ans;

}

int main()
{
    freopen("/Users/zoezhang/Documents/Home/C/2024/adventOfCode/day5.txt", "r", stdin);
    int a, b;
    vector<vector<int>> adj (100);

    string line;

    while (getline(cin, line)){
        if (line==""){ break; }
        a = stoi(line.substr(0, 2));
        b = stoi(line.substr(3, 2));
        adj[a].pb(b);
    }

    //vector<int> top = topologicalSort(adj, 100);

    ll ans = 0;
    while (getline(cin, line)) {
        vector<int> num;
        string number;

        for(stringstream sst(line); getline(sst, number, ',');){
            num.push_back(stoi(number));
        }

        bool ok = true;
        FOR(i, 0, num.size()){
            FOR(j, i+1, num.size()){
                if (find(adj[num[j]].begin(), adj[num[j]].end(), num[i])!=adj[num[j]].end()){
                    ok = false;
                    break;
                }
            }
        }

        if (!ok){
            while (!ok){
                ok = true;
                FOR(i, 0, num.size()){
                    FOR(j, i+1, num.size()){
                        if (find(adj[num[j]].begin(), adj[num[j]].end(), num[i])!=adj[num[j]].end()){
                            swap(num[i], num[j]);
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) break;
                }
            }
            ans += num[num.size()/2];
        }
    }

    cout<<ans<<endl;
}