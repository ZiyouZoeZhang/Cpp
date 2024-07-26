//https://usaco.org/index.php?page=viewproblem2&cpid=896
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

ofstream fout ("mountains.out");
ifstream fin ("mountains.in");

int main (){
    int N;
    vector<pair<int, int>> v;
    fin>>N;
    
    for (int i=0; i<N; i++){
        int x, y;
        fin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), [](const pair<int, int>a, const pair<int, int>b){if (a.f != b.f) return a.f < b.f; else return b.s < a.s;});
    
    vector<bool> alive (N, true);
    int x1 = v[0].f, y1 = v[0].s;
    for (int i=1; i<N; i++){
        int x2 = v[i].f, y2 = v[i].s;
        if (y2 > y1 - (x2 - x1)){ // can be seen
            x1 = x2;
            y1 = y2;
        } else {
            alive[i] = false;
        }
    }

    int x2 = v[N-1].f, y2 = v[N-2].s;
    for (int i= N-2; i>=0; i--){
        int x1 = v[i].f, y1 = v[i].s;
        if (y1 > y2 - (x2 - x1)){
            x2 = x1;
            y2 = y1;
        } else {
            alive[i] = false;
        }
    }

    int sum = 0;
    for (int i=0; i<N; i++){
        if (alive[i]) sum++;
    }

    fout<<sum<<endl;

   return 0;
}