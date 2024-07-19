#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    ll N, M;
    cin>>N>>M;
    vector<ll> cows(N);
    vector<ll> candy(M);
    vector<ll> highc;
    ll high=-1;
    for (ll i=0; i<N; i++){
        cin>>cows[i];
        if (cows[i]>high){
            highc.push_back(i);
            high=cows[i];
        }
    }
    for (ll i=0; i<M; i++){
        cin>>candy[i];
    }

    high=0;
    for (ll i=0; i<candy.size(); i++){
        high=0;
        for (ll j=0; j<highc.size(); j++){
            ll change=min(candy[i], cows[highc[j]]-high);
            high=cows[highc[j]];
            cows[highc[j]]+=change;
            candy[i]-=change;
            if (candy[i]==0) break;
        }
        high=0;
        for (ll j=0; j<highc.size(); j++){
            if(cows[highc[j]]<=high) {
                highc.erase(highc.begin()+j);
                j--;
            } else high=cows[highc[j]];
        }
    }
    for (ll i=0; i<cows.size(); i++){
        cout<<cows[i]<<endl;
    }
}