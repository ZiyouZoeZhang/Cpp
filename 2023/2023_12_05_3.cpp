#include<vector>
#include<iostream>
#include <algorithm>
#define ll long long
using namespace std;
vector<vector<int> > psum;
bool comp(pair<ll,ll>a, pair<ll,ll>b) {return a.second<b.second;};
bool compx(pair<ll,ll>a, pair<ll,ll>b) {return a.first<b.first;};
vector<pair<ll,ll> > p;
ll N;

int rsum(int x1, int y1, int x2, int y2)
{
  return psum[x2+1][y2+1] - psum[x2+1][y1] - psum[x1][y2+1] + psum[x1][y1];
}

int main(){
    cin>>N;
    for (ll i=0; i<N; i++){
        ll x, y;
        cin>>x>>y;
        p.push_back(make_pair(x,y));
    }
    psum.resize(N+1, vector<int>(N+1, 0));
    sort(p.begin(), p.end(), compx);
    for (int i=0; i<p.size(); i++) p[i].first=i+1;
    sort(p.begin(), p.end(), comp);
    for (int i=0; i<p.size(); i++) p[i].second=i+1;
    for (int i=0; i<p.size(); i++) psum[p[i].first][p[i].second]++;
    for (int i=1; i<psum.size(); i++){
        for (int j=1; j<psum.size(); j++){
            psum[i][j]=psum[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
        }
    }
    ll a=1;
    for (int i=0; i<N; i++){
        for (int j=i; j<N; j++){
            int x1=min(p[i].first, p[j].first)-1;
            int x2=max(p[i].first, p[j].first)-1;
            a += rsum(0,i,x1,j) * rsum(x2,i,N-1,j);
        }
    }
    cout<<a<<endl;
}