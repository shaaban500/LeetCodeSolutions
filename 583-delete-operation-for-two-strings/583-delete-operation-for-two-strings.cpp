class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) 
    {
        memset(dp, -1, sizeof dp);
        return word1.size() + word2.size() - solve(0, 0, word1, word2) * 2;
    }
    
    
    int solve(int i, int j, string word1, string word2)
    {
        if(i == word1.size())
            return 0;
        
        if(j == word2.size())
            return 0;
        
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int maxCommonSubString = 0;
        
        if(word1[i] == word2[j])
            maxCommonSubString = max(maxCommonSubString, solve(i + 1, j + 1, word1, word2) + 1);
        else
        {
            maxCommonSubString = max(maxCommonSubString, solve(i + 1, j, word1, word2));
            maxCommonSubString = max(maxCommonSubString, solve(i, j + 1, word1, word2));
        }
        
        return dp[i][j] = maxCommonSubString;
    }

};