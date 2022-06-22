class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int ans = 0;
        long double sum = 0;
        
        reverse(s.begin(), s.end());
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '0')
            {
                ans++;
                continue;    
            }
            
            sum += pow(2, ans);
            if(sum <= k)
                ans++;
        }

        return ans;
    }
};