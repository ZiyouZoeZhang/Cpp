/*
ID: zz415821
TASK: transform
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int N;

ofstream fout ("transform.out");
ifstream fin ("transform.in");

vector<vector<bool>> input(){
    vector<vector<bool>>v (N, vector<bool>(N, false));
    char c;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            fin>>c;
            if (c=='@') v[i][j]=true;
        }
    }
    return v;
}

vector<vector<bool>> rotate90(vector<vector<bool>> v1) {
    vector<vector<bool>>v2 (N, vector<bool>(N));
    int i2=0, j2=0;
    for (int j1=0; j1<N; j1++){
        for (int i1=N-1; i1>=0; i1--){
            v2[i2][j2]=v1[i1][j1];
            j2++;
        }
        i2++;
        j2=0;
    }
    return v2;
}

vector<vector<bool>> reflect(vector<vector<bool>> v1) {
    vector<vector<bool>>v2 (N, vector<bool>(N));
    int i2=0, j2=0;
    for (int i1=0; i1<N; i1++){
        for (int j1=N-1; j1>=0; j1--){
            v2[i2][j2]=v1[i1][j1];
            j2++;
        }
        i2++;
        j2=0;
    }
    return v2;
}

/*
void output (vector<vector<bool>>v){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return;
}
*/

int check(vector<vector<bool>> v1, vector<vector<bool>> v2){
    if (rotate90(v1)==v2) return 1;
    if (rotate90(rotate90(v1))==v2) return 2;
    if (rotate90(rotate90(rotate90(v1)))==v2) return 3;
    if (reflect(v1)==v2) return 4;
    if (rotate90(reflect(v1)) == v2 || rotate90(rotate90(reflect(v1))) == v2 || rotate90(rotate90(rotate90(reflect(v1)))) == v2 ) {
        return 5;
    }
    if (v1==v2) return 6;
    return 7;
}

int main (){
    fin>>N;
    vector<vector<bool>> v1 = input();
    vector<vector<bool>> v2 = input();
    fout<<check(v1, v2)<<endl;
    return 0;
}