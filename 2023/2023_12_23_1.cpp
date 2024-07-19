#include<iostream>
#include<vector>
using namespace std;
vector<vector<bool> >convert(vector<vector<bool> >board, int i, int j);
bool dp(vector<vector<bool> >board);
bool done=false;
vector<int>queens(7,7);//queens[0]=layer

int main(){
    vector<vector<bool> >board(6, vector<bool>(6,false));
    queens[0]=0;
    dp(board);
    for (int i=1; i<7; i++){
        cout<<queens[i]<<endl;
    }
    return 0;
}
//input: board, 多少层了。。。???
//output: board, 是否可行？或者往下传。。

bool dp(vector<vector<bool> >board){
    for (int j=0; j<board[0].size(); j++){
        if (board[queens[0]][j]==false){
            if (dp(convert(board,queens[0],j))==true) return true;
            if (queens[6]!=7) return true;
        }
    }
    if (queens[6]!=7) return true;
    return false;
}

vector<vector<bool> >convert(vector<vector<bool> >board, int i, int j){
    for (int a=0; a<6; a++){
        for (int b=0; b<6; b++){
            if (a==i || b==j || a+b==i+j || a-b==i-j){
                board[a][b]=true;
            }
        }
    }
    queens[queens[0]+1]=j;
    if (queens[0]<5)queens[0]++;
    return board;
}