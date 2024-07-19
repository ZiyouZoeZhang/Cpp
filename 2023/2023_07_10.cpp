//USACO 2020 December Contest, Bronze 1
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#define ll long long
using namespace std;
bool first_1(ll A, ll B, ll C, vector<ll> nums);
void first();

int main(){
    first();
}

void first(){
    vector<ll> nums;
    vector <ll> final;
    for (int i=0; i<7; ++i){
        ll num;
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    //qsort (nums, 7, sizeof(ll), compare);
    if (first_1(nums[0], nums[1], nums[2], nums)==true){
        cout<<nums[0]<<' '<<nums[1]<<' '<<nums[2]<<endl;;
        return;
    } else if (first_1(nums[0], nums[1], nums[3], nums)==true){
        cout<<nums[0]<<' '<<nums[1]<<' '<<nums[3]<<endl;
        return;
    }
    else if (first_1(nums[0], nums[2], nums[3], nums)==true){
        cout<<nums[0]<<' '<<nums[2]<<' '<<nums[3]<<endl;
        return;
    } else cout<<"WARNING"<<endl;
}

bool first_1(ll A, ll B, ll C, vector<ll> nums){
    vector <ll> check{A, B, C, A+B, B+C, A+C, A+B+C};
    sort(check.begin(), check.end());
    //qsort (check, 7, sizeof(ll), compare);
    for (int i=0; i<nums.size(); ++i){
        if (check[i]!=nums[i]) return false;
    }
    return true;
}