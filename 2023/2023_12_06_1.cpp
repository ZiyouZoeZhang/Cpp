//
//
//
#include <iostream>
#include <vector>
#define ll long long
ll n;
using namespace std;
struct point{char dir; ll x; ll y; ll blockedBy=-1; ll d=0; ll count=0; vector<pair<ll,ll> >blocks;};
vector<point>C;
int cal(ll cur);
//vector<bool> north;

int main(){
    cin>>n;
    for (ll i=0; i<n; i++){
        point temp;
        cin>>temp.dir>>temp.x>>temp.y;
        C.push_back(temp);
        /*
        if (a=='E') E.push_back(temp), north.push_back(false);
        else N.push_back(temp), north.push_back(true);
        */
    }
    for (ll i=0; i<C.size()-1; i++){
        for (ll j=i+1; j<C.size(); j++){
            if (C[i].dir!=C[j].dir){
                point* down = (C[i].dir=='N') ? &C[i] : &C[j];
                point* left = (C[j].dir=='E') ? &C[j] : &C[i];
                if (left->x > down->x || down->y > left->y) continue;
                ll yd=left->y-down->y;
                ll xd=down->x-left->x;
                //left will be blocked if
                if (yd<xd && (xd<left->d || left->blockedBy==-1)){
                    if(C[i].dir=='E'){
                        C[i].d=xd;
                        C[i].blockedBy=j;
                        C[j].blocks.push_back(make_pair(i,xd));
                    } else {
                        C[j].d=xd;
                        C[j].blockedBy=i;
                        C[i].blocks.push_back(make_pair(j,xd));
                    }
                } else if (yd>xd && (yd<down->d || down->blockedBy==-1)){
                    if(C[i].dir=='N'){
                        C[i].d=yd;
                        C[i].blockedBy=j;
                        C[j].blocks.push_back(make_pair(i,yd));
                    } else {
                        C[j].d=yd;
                        C[j].blockedBy=i;
                        C[i].blocks.push_back(make_pair(j,yd));
                    }
                }
                /*
                ll yd=C[j].y-C[i].y;
                ll xd=C[i].x-C[j].x;
                if (C[i].dir=='N' && C[i].y<C[j].y && C[i].x>C[j].x){
                    if(yd < xd && xd< C[i].d) { // j gets blocked
                        C[j].blockedBy=i;
                        C[j].d=xd;
                    } else if (xd < yd && yd < C[i].d){
                        C[i].blockedBy=j;
                        C[i].d=yd;
                    }
                } else if (C[i].y>C[j].y && C[i].x>C[j].x){
                    if(xd < yd && xd < C[j].d) {
                        C[j].blockedBy=i;
                        C[j].d=xd;
                    } else if (yd < xd && yd < C[i].d){
                        C[i].blockedBy=j;
                        C[i].d=yd;
                    }
                }*/
            }
        }
    }
    for (ll i=0; i<C.size(); i++){
        if (C[i].blockedBy==-1){
            C[i].count=cal(i);
        }
    }
    for (ll i=0; i<C.size(); i++){
        cout<<C[i].count<<endl;
    }
    return 0;
}
int cal(ll cur) {
    if (C[cur].blocks.empty()) {
        return 1;
    }

    for (ll i = 0; i < C[cur].blocks.size(); i++) {
        if (C[cur].blocks[i].second < C[cur].d || C[cur].d == 0) {
            C[cur].count += cal(C[cur].blocks[i].first);
        }
    }

    return C[cur].count + 1;
}