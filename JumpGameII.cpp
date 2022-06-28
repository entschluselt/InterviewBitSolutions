class Solution {
public:
    
    int jump(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,100000);
        dp[n-1] = 0;
        for(int i = n - 2; i >= 0; i--){
            int count = a[i];
            if(count == 0) {
                dp[i] = 100000;
                continue;
            }
            int j = i;
            while(j + 1 < n and count--){
                dp[i] = min(dp[i], dp[++j] + 1);
            }
        }
        return dp[0];
    }
};
