class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j] = min cost of converting i to j
        vector<vector<int>> dp(word1.length() + 1,vector<int> (word2.length()+1));
        //base case
        dp[0][0] = 0;
        for(int i = 0; i <= word1.length(); i++){
            dp[i][0] = i;
        }

        for(int j = 0; j <= word2.length(); j++){
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({
                        dp[i-1][j-1],   // replace
                        dp[i-1][j],     // delete
                        dp[i][j-1]      // insert
                    });
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};