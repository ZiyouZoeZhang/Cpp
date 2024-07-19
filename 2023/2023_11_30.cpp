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
using namespace std;
int cal(int maxi);
int check_Cur(int cur, int m, bool front, int f, int s);
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
        int cur=0;
        while(cur<m && !nums.empty()){
            cur+=nums.front();
            nums.pop_front();
            count++;
        }
        count--;
        if (cur==m) front++;
        else m=check_Cur(cur, m, true, front, back), front=0, back=0;
        if (nums.size()<2) {break;}
        
        cur=0;
        while(cur<m && !nums.empty()){
            cur+=nums.back();
            nums.pop_back();
            count++;
        }
        count--;
        if (cur==m) back++;
        else m=check_Cur(cur, m, false, front, back), front=0, back=0;
        if (nums.size()<2) {break;}
    }
    if (nums.size()==1 && front>0 && back>0 && nums.front()!=m) count+=2;
    else if (nums.size()==1 && nums.front()!=m) count++;
    return count;
}
int check_Cur(int cur, int m, bool front, int f, int s){
    //if cur smaller than m, set m to m+cur, clean and restart
    //if fcur bigger than m, m=cur and clean and restart
    if (front) nums.push_front(cur);
    else nums.push_back(cur);
    while (f-- > 0) nums.push_front(m);
    while (s-- > 0) nums.push_back(m);
    if (cur<m) m=m+cur;
    if (cur>m) m=cur;
    return m;
}
