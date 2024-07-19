//USACO 2020 December Contest, Silver
//Problem 3. Stuck in a Rut
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1064

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int> >locs;
bool compn(int a, int b) {return locs[a].first<locs[b].first;};
bool compe(int a, int b) {return locs[a].second<locs[b].second;};

int main(){
    int N;
    cin>>N;
    vector<int> north; // index in locs
    vector<int> east; //also index in locs
    for (int i=0; i<N; i++){
        char a;
        int x, y;
        cin>>a>>x>>y;
        locs.push_back(make_pair(x, y));
        if (a=='N') north.push_back(i);
        else east.push_back(i);
    }
    sort(north.begin(), north.end(), compn);
    sort(east.begin(), east.end(), compe);
    vector<int> amtStopped(N, 0);
    vector<bool> stopped(N, false);
    for (int n=0; n<north.size(); n++){
        for (int e=0; e<east.size(); e++){
            if( !stopped[north[n]] && !stopped[east[e]] && locs[east[e]].first < locs[north[n]].first && locs[east[e]].second > locs[north[n]].second) {
                if (locs[north[n]].first-locs[east[e]].first < locs[east[e]].second - locs[north[n]].second){
                    //xd<yd -> north gets blocked by east
                    stopped[north[n]]=true;
                    amtStopped[east[e]]+=amtStopped[north[n]]+1;
                } else if (locs[north[n]].first-locs[east[e]].first > locs[east[e]].second - locs[north[n]].second){
                    stopped[east[e]]=true;
                    amtStopped[north[n]]+=amtStopped[east[e]]+1;
                }
            }
        }
    }
    for (int i=0; i<N; i++) cout<<amtStopped[i]<<endl;
    return 0;
}