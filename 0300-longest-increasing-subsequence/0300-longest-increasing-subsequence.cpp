class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i] = length of the longest increasing subsequence till index[i]
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 0;
        for(int i=1;i<n;i++){
            for(int j=0; j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            
           
        }
        for(int i=0;i<n;i++){
            int temp = dp[i];
            maxi = max(maxi,temp);
        }

        return maxi;
    }
};