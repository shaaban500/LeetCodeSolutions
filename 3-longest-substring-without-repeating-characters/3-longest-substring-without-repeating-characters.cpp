class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
    
        int ans = 0;
        int n = s.size(), l = 0, r = 0;
        map<char, int> freq;
        
        while(r < n)
        {
            if(freq[s[r]] == 0)
            {
                freq[s[r]]++;
                r++;

            }
            else
            {
                freq[s[l]]--;
                l++;
            }

            ans = max(ans, r - l);
        }
        
        return ans;
    }
};




















