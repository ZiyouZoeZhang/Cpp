#include <iostream>
#include <vector>
using namespace std;
int cal(int maxi);
int check_Cur(int cur, int m, bool front, int f, int s);
vector<int> nums;
vector<int> mpos;

int T;
int main(){
    cin>>T;
    for (int i=0; i<T; i++){
        nums.clear();
        int n, m=0;
        cin>>n;
        for (int j=0; j<n; j++){
            int s;
            cin>>s;
            nums.push_back(s);
            m=max(m,s);
        }
        if (m==0) cout<<0<<endl;
        else cout<<cal(m)<<endl;
    }
}


void check(int m){
    //右，左，m中间，等
}

// 13 1 8 6 7 3 4 1 13
// 14 14 14 14
// 13 15 7 3 4 1 13