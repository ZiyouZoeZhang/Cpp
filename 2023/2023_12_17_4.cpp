#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define s second
#define f first
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    ll N, M;
    cin>>N>>M;
    vector<ll> cow(N);
    vector<pair<ll,ll> > candy;
    ll high=-1;
    for (ll i=0; i<N; i++)
        cin>>cow[i];
    for (ll i=0; i<M; i++){
        ll a;
        cin>>a;
        candy.push_back(make_pair(0,a));
    }
    ll count=0;
    for (int i=0; i<cow.size(); i++){
        int j=0;
        while (candy[j].f<=cow[i] && j<candy.size()){
            ll change=min(cow[i], candy[j].s)-candy[j].f;
            candy[j].f+=change;
            cow[i]+=change;
            if (candy[j].f>=candy[j].s) count++;
            if (count>=candy.size()) break;
            j++;
        }
        if (count>=candy.size()) break;
    }
    for (int i=0; i<cow.size(); i++){
        cout<<cow[i]<<endl;
    }
}
