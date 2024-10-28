/*
本节课是Disjoint Set Union 结构与生成树算法的一次习题课，主要围绕第4次课程课后5道习题展开学习。主要包括
Part1 8月17日课后作业题讲解
  1、习题Strongest Friendship Group讲解；
Part2 function graph
  1、功能图的存储与遍历。存储部分主要学习2种策略，
    1是基于邻接表存储图，
    2是基于一个一维数组存储节点指向目标节点；遍历部分主要基于DFS计算联通块并以此为基础，找出联通块内的环结构；
  2、功能图中环路探测，Floyd算法。分3大部分，
    1是通过双指针计算环上点；
    2是通过双指针计算环上第1个点；
    3是通过单指针计算环上节点个数，此部分是本次课程核心，课上通过指针移动图进行了演示；
  3、功能图的识别。基础方法是出度为1，本次课学习的扩展方法是序列中的元素移动，首先形成图结构中的边，满足目标端点个数为1时即为功能图；
Part3 Topologic Sort
  1、基于DFS的Topologic Sort；
  2、基于Topologic Sort的环路图判断。
*/

#include <bits/stdc++.h>
using namespace std;

int main (){
    
}

vector<int> topsort(){
    vector<int> states();
}

int Floyd(int x){

    vector<int> succ;

    int a = succ[x];
    int b = succ[succ[x]];

    while (a!=b){
        a = succ[a];
        b = succ[succ[b]];
    } 
    //now where they meet

    a = x;
    while (a!=b){
        a = succ[a];
        b = succ[b];
    }

    int first = a; //where the cycle starts

    b = succ[a]; 
    int length = 1; 
    while (a != b) { 
        b = succ[b]; 
        length++;
    } //length = how long the cycle is

    return 0;
}