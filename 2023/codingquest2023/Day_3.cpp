#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include<sstream>
using namespace std;

vector <int> player_x;
vector <int> player_o;
string cur;
bool turn = true, found=false;
int x=0;
int o=0;
int tied = 0;


void readFile(string filename){
    int count=0;
    ifstream file(filename);
    if (file.is_open()) {
        string cur_game;
        while (getline(file, cur_game)) {
            turn=true;
            found=false;
            player_x.clear();
            player_o.clear();
            istringstream this_round(cur_game);
            string move;      
            while(getline(this_round, move, ' ')) {
                if ((turn==true)&&(found==false)){
                    player_x.push_back(stoi(move));
                    turn=false;
                    for (int i =0; i<player_x.size(); i++){
                        if (found==true) continue;
                        if((find(player_x.begin(), player_x.end(), player_x[i]+1) != player_x.end())&&(find(player_x.begin(), player_x.end(), player_x[i]+2) != player_x.end())&&((player_x[i]==1)||(player_x[i]==4)||(player_x[i]==7))){
                            x+=1;
                            found=true;
                        } else if ((find(player_x.begin(), player_x.end(), player_x[i]+3) != player_x.end())&&(find(player_x.begin(), player_x.end(), player_x[i]+6) != player_x.end())&&((player_x[i]==1)||(player_x[i]==2)||(player_x[i]==3))){
                            x+=1;
                            found=true;
                        } else if ((find(player_x.begin(), player_x.end(), 1) != player_x.end())&&(find(player_x.begin(), player_x.end(), 5) != player_x.end())&&(player_x[i]==9)){
                            x+=1;
                            found=true;
                        } else if ((find(player_x.begin(), player_x.end(), 3) != player_x.end())&&(find(player_x.begin(), player_x.end(), 5) != player_x.end())&&(player_x[i]==7)){
                            x+=1;
                            found=true;
                        } 
                    }
                } else if (turn==false&&found==false) {
                    player_o.push_back(stoi(move));
                    turn=true;
                    for (int i =0; i<player_o.size(); i++){
                        if (found==true) continue;
                        if((find(player_o.begin(), player_o.end(), player_o[i]+1) != player_o.end())&&(find(player_o.begin(), player_o.end(), player_o[i]+2) != player_o.end())&&((player_o[i]==1)||(player_o[i]==4)||(player_o[i]==7))){
                            o+=1;
                        } else if ((find(player_o.begin(), player_o.end(), player_o[i]+3) != player_o.end())&&(find(player_o.begin(), player_o.end(), player_o[i]+6) != player_o.end())&&((player_o[i]==1)||(player_o[i]==2)||(player_o[i]==3))){
                            o+=1;
                        } else if ((find(player_o.begin(), player_o.end(), 1) != player_o.end())&&(find(player_o.begin(), player_o.end(), 5) != player_o.end())&&(player_o[i]==9)){
                            o+=1;
                            found=true;
                        } else if ((find(player_o.begin(), player_o.end(), 3) != player_o.end())&&(find(player_o.begin(), player_o.end(), 5) != player_o.end())&&(player_o[i]==7)){
                            o+=1;
                            found=true;
                        } 
                    }
                }
            }
            if (found==false){
                tied+=1;
            }
            cout<<count<<endl;
            count+=1;
        }
        file.close();
    }
}

int main(){
    readFile("Day_3.txt");
    cout<<"tied: "<<tied<<"   x: "<<x<<"    o: "<<o<<endl;
    cout<<tied*x*o<<endl;
    return 0;
}