//USACO 2021 December Contest, Silver 1
//卡了。。。
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define ll long long
#define s second
#define f first
#define loop(i, min, max) for (ll i=min; i<max; ++i)
using namespace std;
struct point{ll sum=0; vector<pair<ll, ll> > locs; pair<ll, ll>limit;};
void calculation();
ll K, M, N;
//K=length of grass
//M=Farmer Nhoj's number of cows
//N=Framer John"
vector<pair<ll, ll> >Kvec;
vector<point> vec;
vector<ll>hi;
//vec.sum=sum, vec.locs[n].f=loc, vec.locs[n].s=tastiness;

bool comp(const ll &a, const ll &b) {return a > b;}

int main(){
    //input grass
    freopen("/Users/zoezhang/Documents/Home/C/001/1.in", "r", stdin);
    cin>>K>>M>>N;
    loop(i,0,K){
        ll loc, tas;
        cin>>loc>>tas;
        Kvec.push_back(make_pair(loc,tas));
    }

    //input Nhoj and 
    ll i=0, pre=0, loc;
    cout<<M<<endl;
    cin>>loc;
    hi.push_back(0);
    while (Kvec[i].f<loc){
        hi[0]+=Kvec[i].s;
        ++i;
    }
    pre=loc;
    //最左ok

    while(i<K && i<M){
        point temp;
        while (loc<Kvec[i].f) cin>>loc;
        temp.limit=make_pair(pre, loc); //fix
        while(Kvec[i].f<loc && i<Kvec.size()){
            temp.locs.push_back(Kvec[i]);
            temp.sum+=Kvec[i].s;
            ++i;
        }
        if (temp.sum>0) vec.push_back(temp);
        pre=loc;
    }
    ll temp=0;
    while(i<K){
        temp+=Kvec[i].s;
        ++i;
    }
    if (temp>0) hi.push_back(temp);
    
    calculation();

    sort(hi.begin(), hi.end(), comp);
    ll sol=0;
    ll s=0;
    while(s<N && s<hi.size()) sol+=hi[s], ++s;
    cout<<sol<<endl;
    return 0;
}

void calculation(){
    loop(i, 0, vec.size()){
        //keep max length and cur length
        //if cur length + vec[i+1].limits.f > maxlength
        //   sum -= vec[begin].limits.s, begin++;

        double length=(vec[i].limit.second-vec[i].limit.first)/2;
        ll maxSum=0, sum=vec[i].locs[0].s, begin=0;
        loop(j, 1, vec[i].locs.size()){
            if (vec[i].locs[j].f-vec[i].locs[begin].f<length) sum+=vec[i].locs[j].s;
            else {
                maxSum=max(maxSum, sum);
                while (vec[i].locs[j].f-vec[i].locs[begin].f>=length) sum-=vec[i].locs[begin].s, begin++;
            }
        }
        maxSum=max(maxSum, sum);
        hi.push_back(maxSum);
        if (maxSum-vec[i].sum>0)hi.push_back(maxSum-vec[i].sum);
    }
    return ;
}