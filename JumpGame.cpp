class Solution {
public:
    
    int dp[10002];
    bool f(int index, int target_index, vector<int> &a){
        if(index > target_index) return 0;
        if(index == target_index) return dp[index] = 1;
        if(a[index] == 0) return dp[index] = 0;
        if(dp[index] != -1) return dp[index];
        int count = a[index];
        dp[index] = 0;
        int j = index;
        while(count--){
            dp[index] = dp[index] or f(++j, target_index, a);
        }
        return dp[index];
    }
    
    bool canJump(vector<int>& a) {
        memset(dp, -1, sizeof(dp));
        int n = a.size();
        f(0,n-1,a);
        return dp[0];
    }
};
