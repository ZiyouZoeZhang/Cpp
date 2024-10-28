//https://usaco.org/index.php?page=viewproblem2&cpid=922
#include <bits/stdc++.h>
#define FOR(i, a, b)  for(ll i = (a); i < (b); i++)
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;

//vector 模拟 stack

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)(name).size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int n;
vector<int>vec[100001];
int c = 0; //此处的c表示的是实际要用到的栈的数量值。
int maxv = 0; //Elsie所构建的那个数组（从下往上是递增的），此时的maxv就是那个数组最顶部的元素
int x;

int main(void){
    setIO("dishes");
    cin >> n;
    for(int i = 1; i <= n ; i++){
        cin >> x;
        if(c == 0){
            c++; 
            vec[c].push_back(x);
        }
        else if(x < maxv){
            cout<< (i-1) << endl;
            return 0;
        }
        else if(x > vec[c].front()){
            c++; 
            vec[c].push_back(x);            
        }
        else{ //此处二分算法的目标是为了找第一个底部元素值大于x的vector结构编号
            int left = 1, right = c, pos = -1;
            while(left <= right){
                int mid = (left+right)/2;
                if(vec[mid].front()>x){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            pos = left;
            while(!vec[pos].empty() && vec[pos].back() < x){
                maxv = max(maxv,vec[pos].back());
                vec[pos].pop_back();
            }
            vec[pos].push_back(x);
        }
    }

    cout << n << endl;

    return 0;
}