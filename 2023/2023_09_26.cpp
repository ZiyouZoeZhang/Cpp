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
BDCA 前序 中左右
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
    node* temp = new node;
    temp->val = back[indexStart_s];
    tree.push_back(temp);
    int returnVal = tree.size() - 1;

    int parentIndex_f = indexStart_f;
    
    while (middle[parentIndex_f] != temp->val) parentIndex_f++;
    cout<<" ";
    if (indexStart_s<indexEnd_s && parentIndex_f>indexStart_f){//check conditions
        temp->left = tree[sortSubTree(indexStart_s+1, indexStart_s+(parentIndex_f-indexStart_f)-1, indexStart_f)];
    }
    if (indexStart_s<indexEnd_s && parentIndex_f<indexStart_f+(indexEnd_s-indexStart_s)){//check conditions
        temp->right = tree[sortSubTree(indexStart_s+(parentIndex_f-indexStart_f), indexEnd_s, parentIndex_f+1)];
    }

    return returnVal;

}

void process(node* parent){
    //中左右
    if (parent==NULL) return;
    process(parent->left);
    process(parent->right);
    sol.push_back(parent->val);
}