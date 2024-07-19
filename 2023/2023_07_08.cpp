//http://www.usaco.org/index.php?page=viewproblem2&cpid=811
#include <iostream>
#include <vector>
using namespace std;

int N, B;
vector <int> tiles;
vector<pair<int, int> > boots;
int dp(int boot, int tile, int discarded);
int cal();
//first = depth, second = step size

int main(){
    cin>>N>>B;
    for(int i=0; i<N; ++i){
        int ni;
        cin>>ni;
        tiles.push_back(ni);
    }
    cout<<"2";
    for (int i=0; i<B; ++i){
        int b1, b2;
        cin>>b1>>b2;
        boots.push_back(make_pair(b1, b2));
    }
    cout<<"3";
    cout<<endl;
    int a=dp(0,0,0);
    cout<<a;
    cal();
    return 0;
}

int cal(){
    int i=0;
    while (i<N){
        while(tiles[i+boots[0].second]<=boots[0].first) i+=boots[0].second;
        int j=boots[0].second;
        while((j>0)&&(tiles[i+j]>boots[0].first)) j--;
        if(j>0) i+=j;
        else boots.erase(boots.begin()+1);
    }
}



int dp(int boot, int tile, int discarded){
    cout<<"1";
    //if boot.second > tile.size-tile, return discarded
    //if boot must be disrecarded, meaning any further step > boot.first, return ++discarded
    //if boot is able to take n steps, choose the one with the least num of discarded, for each boot++, tile depends...
    if(boots[boot].second + tile >= tiles.size()) return discarded;
    bool available=false;
    int min_dis=B;
    for(int i=tile; i<=tile+boots[boot].second; ++i) {
        if (boots[boot].first >= tiles[i]) {
            available=true;
            int dis=dp(++boot, i, discarded);
            min_dis = (dis<min_dis) ? dis : min_dis;
        }
    }
    if(available==true) return min_dis;
    else return discarded+1;
}