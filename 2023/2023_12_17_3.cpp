#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int check();
struct p{ll h; ll a; ll t;};
bool comp(p i, p j) {return i.t>j.t;};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int T;
    cin>>T;
    for (int i=0; i<T; i++){
       cout<<check()<<endl;
    }
}

int check(){
    ll N;
    cin>>N;
    vector<p> plant(N);
    for (int i=0; i<N; i++){
        cin>>plant[i].h;
    }
    for (int i=0; i<N; i++){
        cin>>plant[i].a;
    }
    for (int i=0; i<N; i++){
        cin>>plant[i].t;
    }
    if (N==1) return 0;
    sort(plant.begin(), plant.end(), comp);
    ll mini=0, maxi=9999999999999;
    for (int i=0; i<N-1; i++){
        if (plant[i].h>plant[i+1].h && (plant[i+1].a-plant[i].a)!=0)
            mini = max(mini, ((plant[i].h-plant[i+1].h)/(plant[i+1].a-plant[i].a))+1);
        else if (plant[i].a>plant[i+1].a)
            maxi = min(maxi, (plant[i].h-plant[i+1].h)/(plant[i+1].a-plant[i].a));
        else if ((plant[i].h>=plant[i+1].h && plant[i].a>=plant[i+1].a))
            return -1;
        if (maxi<mini) return -1;
    }
    return mini;
}