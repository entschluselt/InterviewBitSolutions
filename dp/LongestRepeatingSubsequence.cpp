/*
Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.
*/

// basically we calculate longest repeating subsequence of this type where characters are same but indexes are different
// and if the length of longest repeating subsequence is greater than 1 we return true
int Solution::anytwo(string s) {
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int> (n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i-1] == s[j-1] and i != j)
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // here dp[n][n] is the length of longest repeating subsequence
    if(dp[n][n] > 1) return 1;
    return 0;

}
