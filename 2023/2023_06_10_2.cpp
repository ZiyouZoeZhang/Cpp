//http://www.usaco.org/index.php?page=viewproblem2&cpid=1303
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct point{
    long x;
    long y;
    long t;
};
vector <point> gras;
int pro1(long x, long y, long t);

int main(){
    long g, n;
    cin>>g>>n;
    for (int i=0; i<g; ++i) {
        long x, y, t;
        cin>>x>>y>>t;
        point temp = {x, y, t};
        gras.push_back(temp);
    }
    long crim = 0;
    for (int i=0; i<n; ++i){
        long x, y, t;
        cin>>x>>y>>t;
        crim+=pro1(x, y, t);
        if (gras.size()==0) break;
    }
    cout<<n-crim<<endl;
}

int pro1(long x, long y, long t){
    //long lx=x-t, hx=x+t, ly=y-t, hy=y+t;
    for (int i=0; i<gras.size(); ++i){
        //if ((gras[i].x<lx)||gras[i].x>hx||gras[i].y<ly||gras[i].y>hy) continue;
        long double dis = (pow(x - gras[i].x, 2) + pow(y - gras[i].y, 2) * 1.0), dt = pow(t - gras[i].t, 2);
        if (dis <= dt){
            gras.erase(gras.begin()+(i-1));
            return 1;
        }
    }
    //cout<<x<<"; "<<y<<endl;
    return 0;
}