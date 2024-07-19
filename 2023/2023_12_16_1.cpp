//USACO 2023 February Contest, Bronze
//Problem 1. Hungry Cow
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1299
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define f first
#define s second
using namespace std;
bool comp(pair<ll,ll> q, pair<ll,ll> b) {return q.f<b.f;};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    ll N, T;
    cin>>N>>T;
    vector<pair<ll, ll> >a(N); //f day
    for (ll i=0; i<N; i++){
        cin>>a[i].f>>a[i].s;
    }
    sort(a.begin(), a.end(), comp);
    ll i=0, count=0;
    while(a[i+1].f<=T && i<a.size()-1){
        while (a[i].f==a[i+1].f) {
            a[i+1].s+=a[i].s;
            i++;
        }
        if (a[i+1].f>T || i>=a.size()-1) break;
        count+=min(a[i+1].f-a[i].f, a[i].s);
        if (a[i].s>a[i+1].f-a[i].f){
            a[i+1].s+=a[i].s-(a[i+1].f-a[i].f);
        }
        i++;
    }
    if(a[i].f<=T  && i<a.size()){
        T++;
        count+=min(T-a[i].f, a[i].s);
    }
    cout<<count;
}