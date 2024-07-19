//USACO 2023 US Open Contest, Silver
//Problem 2. Field Day
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1327

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

int main(){
    int n, c;
    cin>>c>>n;
    vector<int> teams(n);
    vector<int> dists(1<<c, 1000);
    //equivelant to 1000000000000000000 (18*c)
    queue<int> priority_queue;

    for (int i=0; i<n; i++){
        string s;
        cin>>s;
        int x=0; 
        int rx=0;
        //h=1, h=0
        for (int j=0; j<c; j++){
            x= 2*x + (s[j]=='G');
            rx= 2*rx+ (s[j]=='H');
        }
        teams[i]=x;
        dists[rx]=0;
        priority_queue.push(rx);
    }
    while (!priority_queue.empty()){
        int x = priority_queue.front();
        priority_queue.pop();
        for (int i=0; i<c; i++){
            int nx = x ^ (1<<i); //flip bitwise
            if (dists[nx] == 1000){
                priority_queue.push(nx); 
                dists[nx] = dists[x]+1;
            } 
        }
    }
    for (int i=0; i<n; ++i){
        cout<< (c-dists[teams[i]]) <<endl;
    }

}
