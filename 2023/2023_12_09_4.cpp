//first version

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int n, K;
    cin>>n>>K;
    vector<vector<bool> > vv (n, vector<bool>(n, false));
    vector<int> c(n, 1);
    vector<int> pos;
    for (int i=0; i<n; i++){
        pos.push_back(i);
        vv[i][i]=true;
    }
    vector<pair<int, int> > change;
    for (int i=0; i<K; i++){
        int a, b;
        cin>>a>>b;
        change.push_back(make_pair(a-1, b-1));
    }
    int a, b;
    bool happened;
    while (true){
        happened=false;
        for (int k=0; k<K; k++){
            a=change[k].first;
            b=change[k].second;
            if (vv[pos[b]][a]==false){
                vv[pos[b]][a]=true;
                c[pos[b]]++;
                happened=true;
            }
            if (vv[pos[a]][b]==false ){
                vv[pos[a]][b]=true;
                c[pos[a]]++;
                happened=true;
            }
            swap(pos[a], pos[b]);
        }   
        if (!happened) break;
    }
    for (int i=0; i<n; i++){
        cout<<c[i]<<endl;
    }
}
