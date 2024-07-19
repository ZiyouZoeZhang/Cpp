//https://www.luogu.com.cn/problem/P1216
#include <iostream>
#include <vector>
using namespace std;
vector <vector<long> > nums;
int N;

int main(){
    int n;
    long sol=0;
    cin>>N;
    nums.resize(N, vector<long>(N));
    for (int i=1; i<=N; i++){
        for (int j=0; j<i; j++){
            cin>>n;
            nums[i-1][j]=n;
        }
    }
    for (int i=2; i<=N; i++){
        for (int j=0; j<i; j++){
            if (j==0) nums[i-1][j]+=nums[i-2][j];
            else if (j==i-1) nums[i-1][j]+=nums[i-2][j-1];
            else if (nums[i-2][j-1]>nums[i-2][j]) nums[i-1][j]+=nums[i-2][j-1];
            else nums[i-1][j]+=nums[i-2][j];

            if (i==N){
                sol=max(sol, nums[N-1][j]);
            }
        }
    }
    cout<<sol;
    return 0;
}