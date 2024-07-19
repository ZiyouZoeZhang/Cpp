#include <iostream>
#include <vector>
using namespace std;
int N;
struct node{char val; node* right=NULL; node* left=NULL;};
vector <node*> tree;
int find(char element);
void processInput();
string sol;
void preOrder(node* parent);

int main() {
    cin>>N;
    processInput();
    preOrder(tree[0]);
    cout<<sol;
    return 0;
}

void processInput() {
    for (int i = 0; i < N; i++) {
        char n, r, l;
        cin >> n >> l >> r;
        int index = find(n);
        //cout << "index is " << index << endl;
        if (l != '*') tree[index]->left = tree[find(l)];
        if (r != '*') tree[index]->right = tree[find(r)];
        //cout << tree.size() << endl;
    }
}

int find(char element) {
    for (int i = 0; i < tree.size(); i++) {
        if (tree[i]->val == element) {
            return i;
        }
    }
    node* temp = new node;  
    temp->val = element;
    tree.push_back(temp);
    return tree.size() - 1;
}

void preOrder(node* parent) {
    if (parent != NULL) {
        sol += parent->val;
        preOrder(parent->left);
        preOrder(parent->right);
    }
    return;
}