//从左往右，记录最大下标，如果有小的下标，count++
//USACO 2022 February Contest, Bronze
//Problem 2

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int N;
    cin>>N;
    unordered_map<int, int> loc(N); //first=val, second=index 
    vector<int> nums(N);
    for (int i=0; i<N; i++){
        cin>>nums[i];
    }
    for (int i=0; i<N; i++){
        int n;
        cin>>n;
        loc.insert(make_pair(n, i));
    }

    int count=0, m=-1; //m=cur_max
    for (int i=0; i<N; i++){
        if (loc.find(nums[i])->second > m) m=loc.find(nums[i])->second;
        else count++;
    }
    cout<<count<<endl;
    return 0;
}