/*

没做完。。。嗯。。。好像不大对？？。。。
USACO 2020 December Contest, Silver
Problem 2. Rectangular Pasture
http://www.usaco.org/index.php?page=viewproblem2&cpid=1063
*/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
struct point {int x; int y;};
bool comp(point a, point b) {
    return a.x < b.x;
}
void input();

vector<point> nums; 
vector<int> pfss;

int main(){
    input();
    return 0;
}

void input(){
    ll n;
    cin>>n;
    for (int i=0; i<n; ++i){
        int x, y;
        cin>>x>>y;
        point temp;
        temp.x=x, temp.y=y;
        nums.push_back(temp);
    }
    //now sort nums based on x-value, by costumise the sort() function
    sort(nums.begin(), nums.end(), comp);

    //now trying to get the pfss right~
    for (int i=0; i<n; ++i){
        int pfs=0;
        for (int j=0; j<i; j++) if(nums[i].y>nums[j].y) ++pfs;
        pfss.push_back(pfs);
    }
    sort(pfss.begin(), pfss.end());
}