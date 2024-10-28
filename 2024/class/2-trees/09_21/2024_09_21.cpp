//segment tree
/** quick wise words about segment trees and 树状数组
 * 
 * Coordinate Compression
 * If the coordinates are large (say, up to $10^9$), then you should apply coordinate compression 
 * before using a BIT or segment tree (though sparse segment trees do exist). 
 * 
 *  */

#include <bits/stdc++.h>
using namespace std;

int n, tree[200010];

void add(int k, int x){ // k -> index, x -> values
    k += n;
    tree[k] += x;
    for (k/=2; k>=1; k/=2) {
        tree[k] = tree[2*k] + tree[2*k+1];
    }
}

int sum(int a, int b){ //查区间内的元素值
    a += n; b+=n; 
    int s = 0; //sum
    while (a<=b){
        if (a%2 == 1) s+= tree[a++];
        if (b%2 == 0) s+= tree[b--];
        a/=2; b/=2;
    }

    return s;
}