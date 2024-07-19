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
void move();
string moves = "RRRRRRRRRRDDDDDDDDDDUUUUULLLLLLDDDDDDDDDDDDRRRRRRUUUUUUUUUUULLLLLLUUUURRDDRDRDDRDRDRDRDDDDRRRRRRUULLLLLLDLDLDLUUUUUUUULLLLLLLLUUURRRRDDDRRRRRRRRRRRRUUULLDDDRRDDDDDDDDDDLLLLLLLLLLLUUUUUUUUUUUUUUUULLLLLDDDRURRDDDDDDLLDRRRRRRUUUUUUURURRRRRRDDDDDDDDDDDDDLLLLLDRRRRRRRRUUUUUULLLLLLLUUUUUUUUURRRDDDDDDLLLDDRRRRUUUUURRDDDDDDLLLLLLLLLLLLLLLDDDDRRRRUUURUUUUUUUUURRRRRDDDDRRRRRDDDDDDLLLLLLDLLLLLUUUUUUUUURRDDDDDDDDDDDDDLLLLUUUUURRRUUURRDDDDLLDRRRRRRRRRRUUUUUUULLLDDDRDDDLLLDDRRRRRRUUUUUUUUUUUUULLLLDDDDDDDDDDDDDDLLLLUUUUUUUUUUURRRRRRRDDDDDDDLLLLLLDDDDDLDLLLUUUUUULLLLLLLUUUUUUUUURRRRRRRRRDDDDDDDDDDRRRRRRRRUULLLLLLUUUUURRRUUUUULLLLDDLDLLLLLDDDDRRRRRRRRRRRRRUUUUUUUULLLLLLLLLLLDDDDLLLDDDDDDDDDDRRRRRRRRRRRRRRRUUUUUUUUUULLLLLLLLLULLLLLLLUURRRRRRRRRRRRRRRRRDDDDDDDDDDDLLLLLLLLLDDDDLLLLLLLLDRRRRRRRRRUUURRRRRRRRDDDDLLLLLLLLLLLLLLLLLLUUUURRRRRRRULLLLLLLUUUUUUUUUUUURRRRRRRRDDDDDRDDDDDDDDDDDRRRRRDRRRRUULLLLLLLURRRRRRRULLLLLLLURRRRRRRULLLLLLLURRRRRRRULLLLLLLURRRRRRRULLLLLLLURRRRRRRULLLLLLLURRRRRRRULLLLLLLURRRRRRRUULLLLLLLLLLLLLLLLDDDDDDDD";
//string moves ="DDDRRRDDLLLDRRRRRRRDD";
string str("5,5 8,17 5,2 17,14 2,4 17,6 17,17 1,1 2,3 4,9 13,2 12,15 18,15 12,1 17,5 2,14 7,3 17,6 7,13 6,5 5,17 17,12 16,7 15,15 14,14 10,8 15,5 12,12 9,18 7,16 1,3 16,13 12,11 13,6 11,1 5,4 15,8 6,3 5,14 5,3 5,1 17,12 10,14 13,14 18,14 6,14 7,1 15,16 13,4 18,3 9,1 3,13");
//string str("3,3 2,5 7,7 6,0");
vector <int> apples;
int snake_x=0, snake_y=0, score=0, num_app=0, des_x, des_y, last_x, last_y, cur;

void setup() {
    stringstream ss(str);
    for (int i; ss >> i;) {
    apples.push_back(i);
    if (ss.peek() == ',' || ss.peek()== ' ') ss.ignore();
    }
    des_x=apples[0];
    des_y=apples[1];
    
}

int main(){
    setup();
    move();
    cout<<"solution:  "<<score<<endl;
    cout<<num_app;
    return 0;
}

void move(){
    for (cur=0; cur<1500; cur++){
        if (moves[cur]=='D') snake_y+=1;
        else if (moves[cur]=='U') snake_y-=1;
        else if (moves[cur]=='L') snake_x-=1;
        else if (moves[cur]=='R') snake_x+=1;
        if(snake_x<0 || snake_x>19 || snake_y<0 || snake_y>19) return;
        last_y=snake_y;
        last_x=snake_x;
        for (int i=1; i<num_app/2; i++){
            if (moves[cur-i]=='D') last_y-=1;
            else if (moves[cur-i]=='U') last_y+=1;
            else if (moves[cur-i]=='L') last_x+=1;
            else if (moves[cur-i]=='R') last_x-=1;
            if (last_y==snake_y && last_x==snake_x){
                score-=1;
                return;
            }
        }
        if (snake_x==des_x && snake_y==des_y){
            score+=101;
            num_app+=2;
            des_x=apples[num_app];
            des_y=apples[num_app+1];
        } else if (moves[cur]=='D'||moves[cur]=='U'||moves[cur]=='L'||moves[cur]=='R')score+=1;
        else return;
    }
}
