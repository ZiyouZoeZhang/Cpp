#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;
vector<vector<bool> > solution(100, vector<bool> (100,false));

void seperate_items(string filename){
    ifstream file(filename);
    float left = 0, top=0, width=0, hight=0;
    if(file.is_open()) {
        while(file>>left>>top>>width>>hight)  {
            //runs for 60 seconds.
            left=left+(width*3600);
            top=top+(hight*3600);
            for (int i=0; i<60; i++){
                if (floor(left)<=99 && floor(top)<=99 && floor(left)>=0 && floor(top)>=0){
                    if (solution[floor(left)][floor(top)]==false) solution[floor(left)][floor(top)]=true;
                }
                left+=width;
                top+=hight;
            }
            left = 0, top=0, width=0, hight=0;
        }
    } else cout<< "file open fail" <<endl;
}


int main() {
    seperate_items("Day_6.txt");

    cout<<endl<<endl<<endl;
    for (int i =0; i<99; i++) {
        for (int j=0; j<99; j++){
            if (solution[i][j]==false) cout<<"."<<i<<' '<<j;
            else cout<<"X";
        }
        cout<<endl;
    }
    return 0;
}