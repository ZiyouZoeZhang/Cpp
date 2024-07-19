#include <iostream>
#include <vector>
using namespace std;
struct node{char val; node* right=NULL; node* left=NULL;};
vector<node*> tree;
string middle;
string back;
string sol;
int sortSubTree(int indexStart_s, int indexEnd_s, int indexStart_f);
void process(node* parent);

/*
BADC 中序 左中右
BDCA 后序 左右中
先序 

    A
   / \
  B   C
     /
    D
*/

int main(){
    cin>>middle;
    cin>>back;
    sortSubTree(0,middle.size()-1, 0);
    process(tree[0]);
    cout<<sol;
    return 0;
}

int sortSubTree(int indexStart_s, int indexEnd_s, int indexStart_f) {


    //chatgpt's version
    node* temp = new node;
    temp->val = back[indexEnd_s];
    tree.push_back(temp);
    int returnVal = tree.size() - 1;

    int parentIndex_f = indexStart_f;
    while (middle[parentIndex_f] != temp->val) parentIndex_f++;

    cout<<"  ";
    //cout<<indexStart<<"+"<<parentIndex-1<<"  "<<parentIndex<<"+"<<indexEnd-1<<endl;
    if (indexStart_s<indexEnd_s && parentIndex_f>indexStart_f){
        temp->left = tree[sortSubTree(indexStart_s, indexStart_s+(parentIndex_f-indexStart_f)-1, indexStart_f)];
        //cout<<" ";
    }
    if (indexStart_s<indexEnd_s && parentIndex_f<indexStart_f+(indexEnd_s-indexStart_s)){
        temp->right = tree[sortSubTree(indexStart_s+(parentIndex_f-indexStart_f), indexEnd_s-1, parentIndex_f+1)];
    }

    return returnVal;


}

void process(node* parent){
    //中左右
    if (parent==NULL) return;
    sol.push_back(parent->val);
    process(parent->left);
    process(parent->right);
}