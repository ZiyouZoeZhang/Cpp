#include <iostream>
#include <vector>
using namespace std;

//发糖吃

vector <int> nums;
vector <int> result_list;
int result=0;

int main(){
    int m, n;
    cin>>m;
    result_list.resize(m, 1);
    for (int i=0; i<m; i++){
        cin>>n;
        nums.push_back(n);
    }
    cout<<"done"<<endl;

    for (int i=1; i<m; i++){
        if (nums[i-1]<nums[i]) result_list[i]=result_list[i-1]+1;
        else if (nums[i-1]>=nums[i] && result_list[i-1]!=1) result_list[i]=result_list[i-1]-1;
        else if (nums[i-1]>nums[i] && result_list[i-1]==1){
            int j=0;
            while (nums[i-j-1]>nums[i-j]){
                result_list[i-j-1]+=1;
                j+=1;
            }
        } //else if (nums[i-1]==nums[i]) result_list[i]=result_list[i-1];
    }
    for (int i=0; i<result_list.size(); i++){
        result+=result_list[i];
        cout<<result_list[i]<<" ";
    }
    cout<<endl<<result<<endl;
}