#include <iostream>
#include <deque>
using namespace std;
int cal(int N, deque<int> nums, int maxi);
int T;

int main(){
    cin>>T;
    
    for (int i=0; i<T; i++){
        int n, maxi=0;
        cin>>n;
        deque<int> nums;
        for (int j=0; j<n; j++){
            int s;
            cin>>s;
            nums.push_back(s);
            maxi=max(maxi,s);
        }
        if (maxi==0) cout<<0<<endl;
        else cout<<cal(n, nums, maxi)<<endl;
    }
}

int cal(int N, deque<int> nums, int maxi) {
    int times=0, m=maxi, count=0;
    while (!nums.empty()) {
        int cur=nums.front();
        nums.pop_front();

        if (cur<m){
            while (cur<m && !nums.empty()){
                cur+=nums.front();
                nums.pop_front();
                count++;
            }
            if (cur<m && nums.empty()) break;
        }
        if(cur>m) {
            nums.push_front(cur);
            while (times>0){
                nums.push_front(m);
                nums.push_back(m);
                times--;
            }
            m=cur;
            continue;
        }

        cout<<"";
        if (nums.size()==1 && nums.front()!=cur) return count+=1; 
        if (nums.empty()) break;
        cout<<"";
        

        cur = nums.back();
        nums.pop_back();
        
        if (cur<m){
            while (cur<m && !nums.empty()){
                cur+=nums.back();
                nums.pop_back();
                count++;
            }
            if (cur<m && nums.empty()) break;
        }
        if(cur>m) {
            nums.push_back(cur);
            while (times>0){
                nums.push_front(m);
                nums.push_back(m);
                times--;
            }
            m=cur;
            continue;
        }
        if (nums.size()==1 && nums.front()!=cur) return count+=1; 
        if (nums.empty()) break;

        ++times;
    }
    return count;
}
