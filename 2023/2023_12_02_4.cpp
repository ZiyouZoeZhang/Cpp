//http://www.usaco.org/index.php?page=viewproblem2&cpid=1205
//USACO 2022 February Contest, Bronze
//Problem 3. Blocks
#include<iostream>
#include<vector>
using namespace std;
vector<string> dice(4);
int N;
bool check(vector<vector<int> > loc);

int main(){
    cin>>N;
    for (int i=0; i<4; i++)
        cin>>dice[i];

    for (int j=0; j<N; j++){
        string word;
        cin>>word;
        vector<vector<int> > loc(word.size());
        for (int i=0; i<word.size(); i++){
            for (int a=0; a<4; a++){
                for (int b=0; b<6; b++){
                    if (dice[a][b]==word[i]) {
                        loc[i].push_back(a);
                        b=6;
                    }
                }
            }
        }
        if (check(loc)==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
bool check(vector<vector<int> > loc){
    for (int a=0; a<loc[0].size(); a++){
        if (loc.size()>1){
            for (int b=0; b<loc[1].size(); b++){
                if (loc.size()>2){
                    for (int c=0; c<loc[2].size(); c++){
                        if (loc.size()>3){
                            for (int d=0; d<loc[3].size(); d++){
                                if (loc[0][a]!=loc[1][b] && loc[0][a]!=loc[2][c] && loc[2][c]!=loc[1][b] && loc[3][d]!=loc[1][b] && loc[0][a]!=loc[3][d] && loc[2][c]!=loc[3][d]) return true;
                            }
                        } else if (loc[0][a]!=loc[1][b] && loc[0][a]!=loc[2][c] && loc[2][c]!=loc[1][b]) return true;
                    }
                } else if (loc[0][a]!=loc[1][b]) return true;
            }
        } else return true;
    }   
    return false;
}