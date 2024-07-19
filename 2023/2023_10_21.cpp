#include <iostream>
#include <vector>
using namespace std;
int n;
vector <int> nums[n];
void cmp(int parent);


int main(){
    for (int i=n/2-1; i>=0; i++) cmp(i);
}

void cmp(int parent) { //从上往下 
    if (parent*2<nums.size() && nums[parent]<nums[parent*2]) {
        swap(nums[parent],nums[parent*2]);
        cmp(parent*2);
    }
    if (parent*2+1<nums.size() && nums[parent]<nums[parent*2 +1]) {
        swap(nums[parent],nums[parent*2 +1]);
        cmp(parent*2+1);
    }
}