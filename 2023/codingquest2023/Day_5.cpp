#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
vector<vector<bool> > solution(10, vector<bool> (50,false));

void seperate_items(string filename){
    ifstream file(filename);
    int left = 0, top=0, width=0, hight=0;
    if(file.is_open()) 
    {
        while(file>>left>>top>>width>>hight)  
        {
            cout <<left<<" "<<top<<" "<<width<<" "<<hight<<endl;
            for (int row=top; row<top+hight; row++){
                for (int column=left; column<left+width; column++){
                    if (solution[row][column]==false) solution[row][column]=true;
                    else solution[row][column]=false;
                }
            }
            left = 0, top=0, width=0, hight=0;
        }
    }else cout<< "file open fail" <<endl;
}


int main() {
    seperate_items("Day_5.txt");
    for (int i =0; i<10; i++) {
        for (int j=0; j<50; j++){
            if (solution[i][j]==false) cout<<".";
            else if (solution[i][j]==true) cout<<"#";
        }
        cout<<endl;
    }
}