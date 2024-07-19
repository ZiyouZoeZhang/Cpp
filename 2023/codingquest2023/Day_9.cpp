#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <sstream>
#include <math.h>
#include<deque>
using namespace std;


struct TreeNode {
    long long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
};

int max_height,max_width;

class BinaryTree {
private:
    TreeNode* root;
public:
    BinaryTree() : root(nullptr) {}
    void insert(long long val) {
        TreeNode* node = new TreeNode(val);
        if (root == nullptr) {
            root = node;
            return;
        }
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (val < cur->val) {
                if (cur->left == nullptr) {
                    cur->left = node;
                    return;
                }
                cur = cur->left;
            } else {
                if (cur->right == nullptr) {
                    cur->right = node;
                    return;
                }
                cur = cur->right;
            }
        }
    }
    void cal_width_and_height(){
        TreeNode *last = this->root;
        int temp_width=0;
        deque <TreeNode*> nodes;
        nodes.push_back(this->root);
        while(!nodes.empty()){//BFS
            TreeNode* first=nodes.front();
            temp_width++;
            if(first){
                cout<<first->val<<endl;
                nodes.pop_front();//out
                if(first->left){
                    nodes.push_back(first->left);
                }
                if(first->right){
                    nodes.push_back(first->right);
                }
            }
            if(first==last){//last item in this depth
                if(!nodes.empty()){//if still not the depthest
                    last=nodes.back();
                }
                max_height++;
                if(temp_width>max_width){
                    max_width=temp_width;
                }
                temp_width=0;
            }
        }
    }
};


int main() {
    freopen("Day_9.txt","r",stdin);
    BinaryTree tree;
    string temp;
    for(int i=1;i<=10000;i++){
        cin>>temp;
        cout<<"insert "<<temp<<endl;
        tree.insert(stol(temp,0,16));
    }
    tree.cal_width_and_height();
    cout<<max_width<<endl<<max_height;
    return 0;
}
/*
struct tree {
    string id;//id of node
    long value;//value of node
    tree *parent=NULL;//parent node
    tree *left_child=NULL;
    tree *right_child=NULL;//childre,optional
    //140737488355328
};

void insert_node(long value, string hex);
void readFile(string filename);
void find_parent(long value, tree* cur);
vector <tree> binary_tree;
int max_height=0;
int cur_max_height=0;
int tree_size=1;

map<int, int> levels;

void insert_width(int level){
    if (levels.find(level) == levels.end()) {
                // not found
                levels[level]=1;
            } else {
                // found
                levels[level]+=1;
            }
}

void readFile(string filename){
    ifstream file(filename);
    if (file.is_open()) {
        cout<<"111"<<endl;
        string line;
        while (getline(file, line)) {
            cout<<line<<"; ";
            cout<<stol(line,0,16)<<endl;
            insert_node(stol(line,0,16), line);
        }
        file.close();
        cout<<"size: "<<tree_size;
    }
}


int main(){
    binary_tree.clear();
    tree temp_node;
    binary_tree.push_back(temp_node);
    binary_tree[0].id="800000000000";
    binary_tree[0].value=140737488355328;
    binary_tree[0].parent=NULL;
    binary_tree[0].left_child=NULL;
    binary_tree[0].right_child=NULL;
    readFile("Day_9.txt");
    
    for (int i = 0; i<tree_size; i++){
        cout<<binary_tree[i].value<<endl;
    }
    
    
    unsigned currentMax = 0;
    unsigned arg_max = 0;
    for(auto it = levels.cbegin(); it != levels.cend(); ++it ) {
        if (it ->second > currentMax) {
            arg_max = it->first;
            currentMax = it->second;
        }
    }
    cout << "Value " << arg_max << " occurs " << currentMax << " times " << endl;
    cout<<"here"<<endl;
    cout<<max_height<<"hyh"<<endl;
    cout<<"done"<<endl;
}


void insert_node(long value, string hex){
    cout<<"entered"<<endl;
    cur_max_height=1;
    tree temp_node; 
    
    cout<<"HELLO"<<endl;
    cout<<temp_node.value<<endl;
    cout<<"everything is fine"<<endl;
    cout<<binary_tree.size()-1<<endl;
    cout<<binary_tree[binary_tree.size()-1].value<<endl;
    cout<<value<<endl;
    
    tree_size+=1;
    binary_tree[tree_size-1].value=value; //value = value
    binary_tree[tree_size-1].id=hex; //id
    binary_tree[tree_size-1].left_child=NULL; //默认没有孩子
    binary_tree[tree_size-1].right_child=NULL; //也默认没有孩子 
    
    //binary_tree.push_back(temp_node);
    cout<<"where is my dad?"<<endl;
    find_parent(value, &binary_tree[0]);
    insert_width(cur_max_height);
    if (max_height<cur_max_height){
        max_height=cur_max_height;
        cout<<max_height<<endl;
    }
    cout<<"continue"<<endl;
}

void find_parent(long value, tree* cur) {
    cur_max_height+=1;
    cout<<"!!!"<<endl;
    cout<<value<<endl;
    cout<<cur->value<<endl;
        if (value< cur->value){
            cout<<"left"<<endl;
            if (!cur->left_child||cur->left_child==NULL){
                cout<<"found"<<endl;
                cur->left_child=&binary_tree[tree_size-1]; //要把他的parent id 指针指向自己
                return;
            } else if (cur->left_child||cur->left_child!=NULL){
                find_parent(value, cur->left_child);
            } else {
                cout<<"ERROR QTF?????";
            }
        } else if (value>=cur->value) {
            cout<<"right"<<endl;
            if (!cur->right_child||cur->right_child==NULL){
                cout<<"found"<<endl;
                cur->right_child=&binary_tree[tree_size-1]; //要把他的parent id 指针指向自己
                //cout<<"again found"<<endl;
                return;
            } else if (cur->right_child||cur->right_child!=NULL){
                //cout<<"right child: "<<cur->right_child->value<<endl;
                find_parent(value, cur->right_child);
            } else {
                cout<<"ERROR QTF?????";
            }
        } else cout<<"ERROR WTF?"<<endl;
    }
*/