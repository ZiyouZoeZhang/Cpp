//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

//tree and insert node

struct tree {
    int id;//id of node
    int value;//value of node
    tree *parent;//parent node
    tree *left_child,*right_child;//childre,optional
};
vector <tree> binary_tree;
void insert_node(int value){
    tree temp_node; 
    binary_tree.push_back(temp_node);

    binary_tree[binary_tree.size()-1].value=value; //value = value
    binary_tree[binary_tree.size()-1].id=binary_tree.size(); //id
    binary_tree[binary_tree.size()-1].parent=&binary_tree[(binary_tree.size()-1)/2]; //他的parent node = 他的id （size-1）/2
    binary_tree[(binary_tree.size()-1)/2].left_child=&binary_tree[binary_tree.size()-1];  //要把他的parent id 指针指向自己
    binary_tree[binary_tree.size()-1].left_child=NULL; //默认没有孩子
    binary_tree[binary_tree.size()-1].right_child=NULL; //也默认没有孩子
}

int main(){
    tree temp_node;
    //init root
    binary_tree.push_back(temp_node);

    binary_tree[0].id=1;
    binary_tree[0].value=30;
    binary_tree[0].parent=NULL;

    //try
    insert_node(27);

    for (int i = 0; i<binary_tree.size(); i++){
        cout<<binary_tree[i].value<<endl;
    }

}

//ok 一棵树
//每个node,包含value, id，parent node （指针） and possibly left and right child （指针）


