//https://www.luogu.com.cn/problem/P1002 
//过河卒
//wrote during class - not my code
#include<bits/stdc++.h>
using namespace std;

int  targetx,targety, horsex, horsey;
int status[21][21]; //二位数组定义为全局数组的时候，它的元素值默认为0
long long ans[21][21] ;   //ans[i][j]表示的是从坐标原点(0,0)到坐标点(i,j)之间有多少条路径 
int offsetx[8] = {2,2,1,1,-2,-2,-1,-1};
int offsety[8] = {-1,1,-2,2,-1,1,-2,2};

//这个函数表示的是从坐标原点(0,0)到坐标点(x,y)一共有多少种走法

long long f(int x,int y){
 if(x==0 and y ==0){
  return 1;
 }

 if(x>=0 and x<= 20 and y >=0 and y <= 20){
  if(status[x][y] == 1){
   return 0;
  }
  if(ans[x][y] !=0){
   return ans[x][y];
  }
  else{
   ans[x][y] = f(x-1,y) + f(x,y-1);
   return ans[x][y];
  }
 }
 else{
  return 0;
 }
}

int main(void){
 cin >> targetx >> targety >> horsex >> horsey ; 

 //将所有马脚坐标点与马的坐标点状态置为1，表示不能访问
 status[horsex][horsey] = 1;
 for(int i=0;i<8;i++){
  int  x = horsex + offsetx[i];
  int y = horsey +  offsety[i];
  if(x>=0 and x<= 20 and y >=0 and y <= 20){
   status[x][y] = 1;
  }
 }
 f(targetx,targety);
 cout << ans[targetx][targety] << endl;

 return 0;
}