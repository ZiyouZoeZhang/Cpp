//USACO 2023 February Contest, Bronze
//Problem 2. Stamp Grid
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1300
#include<iostream>
#include<vector>
using namespace std;
bool run();
vector<pair<int, int> >rotate(vector<pair<int, int> >a, int n2);

int main(){
    int K;
    cin>>K;
    for (int i=0; i<K; i++){
        if(run()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
bool run(){
    int n1, n2;
    cin>>n1;
    int count=0;
    vector<vector<bool> >paint(n1, vector<bool>(n1, false));
    for (int i=0; i<n1; i++){
        for (int j=0; j<n1; j++){
            char a;
            cin>>a;
            if (a=='*') paint[i][j]=true, count++;
        }
    }
    cin>>n2;

    vector<pair<int, int> > stamp;
    for (int i=0; i<n2; i++){
        for (int j=0; j<n2; j++){
            char a;
            cin>>a;
            if (a=='*') stamp.push_back(make_pair(i,j));
        }
    }
    vector<vector<bool> >painted(n1, vector<bool>(n1, false));
    for (int h=0; h<4; h++){
        for (int i=0; i<=n1-n2; i++){
            for (int j=0; j<=n1-n2; j++){
                bool yes=true;
                for (int z=0; z<stamp.size(); z++){
                    if (paint[stamp[z].first+i][stamp[z].second+j]==false){
                        yes=false;
                        break;
                    }
                }
                if (!yes) {continue;}
                for (int z=0; z<stamp.size(); z++){
                    if (paint[stamp[z].first+i][stamp[z].second+j]==true && painted[stamp[z].first+i][stamp[z].second+j]==false){
                        painted[stamp[z].first+i][stamp[z].second+j]=true;
                        count--;
                        if (count<=0) return true;
                    }
                }
            }
        }
        stamp=rotate(stamp,n2-1);
    }
    for (int i=0; i<n1; i++){
        for (int j=0; j<n1; j++){
            if (painted[i][j]!=paint[i][j]) return false;
        }
    }
    return true;
}
vector<pair<int, int> >rotate(vector<pair<int, int> >a, int n2){
    for (int i=0; i<a.size(); i++){
        swap(a[i].first, a[i].second);
        a[i].second=n2-a[i].second;
    }
    return a;
}