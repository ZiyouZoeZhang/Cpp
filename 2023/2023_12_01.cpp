//add front up till m, if front reaches m, front ++
                    // if cur doesn't,
                        //if cur smaller than m, set m to m+cur, clean and restart
                        //if fcur bigger than m, m=cur and clean and restart
//add back up till m, if back reaches m, back ++
                    // if cur doesn't,
                        //if cur smaller than m, set m to m+cur, clean and restart
                        //if fcur bigger than m, m=cur and clean and restart

#include <iostream>
#include <deque>
#include <stack> 
using namespace std;
int cal(int maxi);
int check_Cur(int cur, int m, bool front, int f, int s, stack<int> current);
deque<int> nums;
int T;

int main(){
    cin>>T;
    
    for (int i=0; i<T; i++){
        nums.clear();
        int n, maxi=0;
        cin>>n;
        for (int j=0; j<n; j++){
            int s;
            cin>>s;
            nums.push_back(s);
            maxi=max(maxi,s);
        }
        if (maxi==0) cout<<0<<endl;
        else cout<<cal(maxi)<<endl;
    }
}

int cal(int m) {
    int front=0, back=0, count=0;
    while(nums.size()>1){
        int cur=0, thisCount=0;
        stack<int> current;
        while(cur<m && !nums.empty()){
            cur+=nums.front();
            current.push(nums.front());
            nums.pop_front();
            thisCount++;
        }
        thisCount--;
        if (cur<=m) count+=thisCount;
        if (cur==m) front++;
        else m=check_Cur(cur, m, true, front, back, current), front=0, back=0;
        if (nums.size()<2) {break;}
        
        cur=0, thisCount=0;
        while(!current.empty()) current.pop();
        while(cur<m && !nums.empty()){
            cur+=nums.back();
            current.push(nums.back());
            nums.pop_back();
            thisCount++;
        }
        thisCount--;
        if (cur<=m) count+=thisCount;
        if (cur==m) back++;
        else m=check_Cur(cur, m, false, front, back, current), front=0, back=0;
        if (nums.size()<2) {break;}
    }
    if (nums.size()==1 && front>0 && back>0 && nums.front()!=m) count+=2;
    else if (nums.size()==1 && nums.front()!=m) count++;
    return count;
}
int check_Cur(int cur, int m, bool front, int f, int s, stack<int> current){
    //if cur smaller than m, set m to m+cur, clean and restart
    //if fcur bigger than m, m=cur and clean and restart
    if (front){
        while (!current.empty()) {
            nums.push_front(current.top());
            current.pop();
        }
    } else {
        while (!current.empty()) {
            nums.push_back(current.top());
            current.pop();
        }
    }
    while (f-- > 0) nums.push_front(m);
    while (s-- > 0) nums.push_back(m);
    if (cur<m) m=m+cur;
    if (cur>m) m=cur;
    return m;
}
