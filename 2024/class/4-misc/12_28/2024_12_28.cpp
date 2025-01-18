#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;

/**
 * L的上限为 序列里面的最小值除以4
 * 前四个元素中，俩俩找最小的因子
 * e.g. (a-b)%L = 0 
 * 
 * 
 * 
 */

/**
 * 拿到4的倍数会失败
 * 
 * 4以及以上 --》两轮
 * 8以及以上 --》三轮 
 * 等
 */

const int MAXN = 1e7;                 //定义空间大小，1e7约10M
int prime[MAXN+1];                    //存放素数，它记录visit[i] = false的项
bool visit[MAXN+1];                   //true表示被筛掉，不是素数
int E_sieve(int n)  {                 //埃式筛法，计算[2, n]内的素数
    int k=0;                            //统计素数个数
    for(int i=0; i<=n; i++)  visit[i]= false;  //初始化
    for(int i=2; i<=n; i++) {        //从第一个素数2开始。
        if(!visit[i]) {
            prime[k++] = i;               //i是素数，存储到prime[]中
            for(int j=2*i; j<=n; j+=i)  //i的倍数，都不是素数。
                visit[j] = true;          //标记为非素数，筛掉
        }
    }
    return k;                              //返回素数个数
}

/**
 * 整数a和b的最大公约数 gcd(a, b)

辗转相除法求gcd(a, b) ：
int gcd(int a, int b) { 
       return b == 0 ? a : gcd(b, a%b);  
}
复杂度 O(logn)


 */

//__gcd()

/**
 * 求方程ax+by=gcd(a,b)的一个特解(x0, y0)

void extend_gcd(int a, int b, int &x, int &y){ 
                          //返回x，y，即一个特解(x0, y0)
    if(b==0) {
        x=1, y=0;      return ;
    }
    extend_gcd(b, a%b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a/b)*y;
}


 */