class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       //dp[i] = max amoutn of money robbed till ith day
       vector<int> dp(n);
       if(n == 1) return dp[0] = nums[0];
       dp[0] = nums[0];
       dp[1] = max(nums[0],nums[1]);
       for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
       }
       return dp[n-1];
    }
};