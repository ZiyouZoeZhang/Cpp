//https://acm.hdu.edu.cn/showproblem.php?pid=1205
//鸽巢原理
/**
 * 比如假设有三个苹果，然后有两个抽屉， 那么放苹果最多的抽屉最少会放2个苹果
 * 可以用反证法 
 * 识别出谁是糖果，谁是抽屉
 */

#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;


bool run(){
    int N;
    ll total = 0;
    cin>>N;
    vector<int> v(N);

    FOR(i, 0, N){
        cin>>v[i];
        total+=v[i];
    }

    FOR(i, 0, N) {
        if (v[i] > (total+1)/2)
            return false;
    }
    return true;
}

int main(){

    int N; cin>>N;
    FOR(i, 0, N){
        run() ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    }
}