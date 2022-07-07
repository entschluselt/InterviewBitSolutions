#define dp longest_till_here
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> longest_till_here(n,0);
        int res = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    longest_till_here[i] = 2 + ((i -2 >= 0) ? longest_till_here[i-2]  : 0);
                    res = max(res, longest_till_here[i]);
                } else {
                    if(i - longest_till_here[i-1]-1 >= 0  and  s[i - longest_till_here[i-1] -1] == '('){
                        longest_till_here[i] = dp[i-1] + 2 + ((i - dp[i-1] - 2 >= 0) ? dp[i - dp[i-1] - 2] : 0);
                    }
                    res = max(res, longest_till_here[i]);
                }
            }
        }
        return res;
        
    }
};
