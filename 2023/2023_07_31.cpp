#include <iostream>
#include <vector>

using namespace std;
long long N, ans=0;
vector<pair<long long, long long> >cows;
//first height, second index
bool cmp(const pair<long long,long long>& a, const pair<long long,long long>& b) {return a.first < b.first;}

int main(){
    cin>>N;
    for (long long i=0; i<N; ++i) {
        long long n;
        cin>>n;
        cows.push_back(make_pair(n,i));
    }
    sort(cows.begin(), cows.end(), cmp);
    for (long long i=1; i<N; ++i){
        ans+=max(cows[i-1].second,cows[i].second)-min(cows[i-1].second,cows[i].second);
    }
    //sort based on value, push in largest first. store place.
    cout<<ans<<endl;
    return 0;
}