//USACO 2023 January Contest, Silver
//Problem 2. Following Directions
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1279 

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//Index: ps=presum, pi=prei, pj=prej
struct point { int sign=1, ps=1; };
int cal(int fir, int sec);
vector<vector<point> > cows;
int sum, n, q;

int main() {
    //freopen("15.in","r",stdin);
    char dir;
    cin>>n;
    cows.resize(n+1 , (vector<point>(n+1)));
    for (int i=0; i<=n; ++i){
        for (int j=0; j<=n; ++j){
            if (i==n && j==n) break;
            if (i==n || j==n) cin>>cows[i][j].sign, cows[i][j].ps-=1, sum+=cows[i][j].sign*cows[i][j].ps;
            else {
                cin>>dir;
                cows[i][j].sign= (dir=='R') ? 0 : 1;
                if (dir=='R') cows[i][j+1].ps+=cows[i][j].ps;
                else cows[i+1][j].ps+=cows[i][j].ps;
            }
        }
    }
    cout<<sum<<endl;
    cin>>q;
    int first, second;
    for (int i=0; i<q; i++) cin>>first>>second, cout<<cal(first-1, second-1)<<'\n';
}

int cal(int i, int j){
    int pi=i, pj=j, count=1, change=cows[i][j].ps;
    while (pi!=n && pj!=n) {
        if (cows[pi][pj].sign==0) pj++, cows[pi][pj].ps-=change;
        else pi++, cows[pi][pj].ps-=change;
    }
    int lost=cows[pi][pj].sign;

    //second time
    pi=i, pj=j;
    cows[i][j].sign= (cows[i][j].sign==0) ? 1:0;
    while (pi!=n && pj!=n) {
        if (cows[pi][pj].sign==0) pj++, cows[pi][pj].ps+=change;
        else pi++, cows[pi][pj].ps+=change;
    }
    sum=sum-(lost*change)+(change*cows[pi][pj].sign);
    return sum;
}
/*
3
D R D 1
R D D 2
D R R 6
3 4 5 0
*/