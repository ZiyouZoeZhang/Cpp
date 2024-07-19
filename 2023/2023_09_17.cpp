#include <iostream>
#include <vector>
using namespace std;

struct node {
    int value;
    int parent;
    int lchild;
    int rchild;
};

int main(){
    vector<node> tree;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        node c;
        cin>>c.value;
        
        tree.push_back(c);
    }

}