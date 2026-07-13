class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //dp[i][0] = maximum profit till i th day (not holding a stock)
        //dp[i][1] = maximum profit till i th day (while holding a stock)
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]); // if not holding we either do not hold today or we sold today
            dp[i][1] = max(dp[i-1][1], dp[i][0] - prices[i]);// if holding yesterday we either keep holding or sell
        }
        return dp[n-1][0];
    }
    


};

// 7,1,5,3,6,4
//sell = false
//dp[0] = 0
// buy = 7, sell = true
// profit = max(0,1-7) = 0
//dp [1] = 0, sell = false;


