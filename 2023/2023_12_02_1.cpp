//http://www.usaco.org/index.php?page=viewproblem2&cpid=1203
#include <iostream>
#include <vector>
using namespace std;
int cal(vector<int> sleep, int sum);
int T;


int main(){
    cin>>T;
    for (int i=0; i<T; i++){
        int n, sum=0;
        vector<int> sleep;
        cin>>n;
        for (int i=0; i<n; i++){
            int s;
            cin>>s;
            sum+=s;
            sleep.push_back(s);
        }
        cout<<cal(sleep, sum)<<endl;
    }
}

int cal(vector<int> sleep, int sum){
    if (sum==0) return 0;
    //i=分成哪些个数
    for (int i=1; i<sum; i++){
        if (sum%i>0) {continue;}
        bool yesyes=false;
        int part=0;
        for (int j=0; j<sleep.size(); j++){
            if (part+sleep[j]<i) part+=sleep[j];
            else if (part+sleep[j]==i) part=0;
            else {break;}
            if (j==sleep.size()-1 && part==0) yesyes=true;
        }
        if (yesyes==true) {
            return sleep.size()-(sum/i);
        }
    }
    return sleep.size()-1;
}
