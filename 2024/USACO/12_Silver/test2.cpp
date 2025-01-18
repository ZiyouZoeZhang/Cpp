#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
//#define f first
//#define s second
#define pb push_back
using namespace std;

int optimalFinalNumber(vector<int>& nums) {
    int n = nums.size();
    // Initialize DP table
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: Single number left
    for (int i = 0; i < n; ++i) {
        dp[i][i] = nums[i];
    }

    // Build the table for all ranges of length 2 to n
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            // Person 1's turn: maximize the result
            int replaceLeft = (i + 1 < n ? dp[i + 2][j] : INT_MIN) + nums[i] + nums[i + 1];
            int replaceRight = (j - 1 >= 0 ? dp[i][j - 2] : INT_MIN) + nums[j - 1] + nums[j];
            int replaceBothEnds = dp[i + 1][j - 1] + nums[i] + nums[j];
            
            dp[i][j] = max({replaceLeft, replaceRight, replaceBothEnds});

            // Person 2's turn: minimize the result for Person 1
            if (i + 1 <= j) dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            if (i <= j - 1) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }

    // The final result is stored in dp[0][n-1]
    return dp[0][n - 1];
}

int main() {
    vector<int> nums = {3, 9, 1, 2};
    cout << "Optimal final number: " << optimalFinalNumber(nums) << endl;
    return 0;
}