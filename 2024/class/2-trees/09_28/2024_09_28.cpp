//树状数组的一个常见应用，算出左边有多少个数字比targeted数字大 or 小

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define lowbit(x) ((x)&(-x))

int a[300000];
int ans[300000];
int tree[300000];
int n;
int MAXN = 100000;

void add(int x, int d){  //ax = ax + d
  while(x <= MAXN) {
    tree[x] += d;  
    x += lowbit(x); 
 }
}

int sum(int x) {  //求和：sum=a1+...+ax
  int s = 0;
  while(x > 0){
    s += tree[x];  
    x -= lowbit(x);
  }
  return s;
}

int main(void){
    cin >> n;
    for(int i = 1; i <=n ; i++){
        cin >> a[i];
        ans[i] = sum(a[i]-1);
        add(a[i],1);
    }

    cout<<"左边有几个数字比他小？"<<endl;
    for(int i = 1; i <=n ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    cout<<"左边有几个数字比他大？"<<endl;
    for(int i = 1; i <=n ; i++){
        cout << i-ans[i]-1 << " ";
    }
    cout << endl;

   return 0;
}