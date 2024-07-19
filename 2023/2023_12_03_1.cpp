//USACO 2022 January Contest, Bronze
//Problem 2. Non-Transitive Dice
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1180


#include <iostream>
#include <vector>
using namespace std;
int T;
int better(vector<int>d1, vector<int>d2);
bool cal();


int main(){
    cin>>T;
    for (int i=0; i<T; i++){
        if (cal()==true) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}

bool cal(){
    vector<int>d1(4);
    vector<int>d2(4);
    vector<int>d3(4);
    for (int i=0; i<4; i++) cin>>d1[i];
    for (int i=0; i<4; i++) cin>>d2[i];
    int r1=better(d1,d2);
    if (r1==0) return false;
    for (int a=1; a<=10; a++){
        for (int b=1; b<=10; b++){
            for (int c=1; c<=10; c++){
                for (int d=1; d<=10; d++){ // 123,132,
                    d3[0]=a;
                    d3[1]=b;
                    d3[2]=c;
                    d3[3]=d;
                    int r2=better(d1,d3);
                    int r3=better(d2,d3);
                    if ((r1==1 && r3==1 && r2==2) || (r2==1 && r3==2 && r1==2)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int better(vector<int>d1, vector<int>d2){ //1 if dice 1 is greater, 2 if d2 is greater, 0 if equal
    int c1=0, c2=0;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (d1[i]>d2[j]) c1++;
            if (d1[i]<d2[j]) c2++;
        }
    }
    if (c1>c2) return 1;
    if (c2>c1) return 2;
    return 0;
}


