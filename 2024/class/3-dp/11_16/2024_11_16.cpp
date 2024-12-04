
/**
 * LCS - 最长公共子序列 （在所有序列中，这个公共子序列最长）
 * 
 * 满足3条规则
 * 1. 满足子序列的条件
 * 2。该子序列同时存在于2个或以上序列中
 * 3. 该子序列所在的公共子序列中，元素个数最多
 * complexity O(n^2)
 * 
 * 应用
 * 1. 平面移动 (grid paths)
 * 2. array description
 */


#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for s1[0..m-1], s2[0..n-1]
int lcs(vector<int> s1, vector<int> s2, int m, int n) {
  
    // Base case: If either string is empty, the length of LCS is 0
    if (m == 0 || n == 0)
        return 0;

    // If the last characters of both substrings match
    if (s1[m - 1] == s2[n - 1])
      
        // Include this character in LCS and recur for remaining substrings
        return 1 + lcs(s1, s2, m - 1, n - 1);

    else
        // If the last characters do not match
        // Recur for two cases:
        // 1. Exclude the last character of s1 
        // 2. Exclude the last character of s2 
        // Take the maximum of these two recursive calls
        return max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
}

int main() {
    int n,m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    cout << lcs(a, b, n, m) << endl;

    return 0;
}