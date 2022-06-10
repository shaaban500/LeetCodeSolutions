class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> freq;
        int ans = 0, n = s.size(), l = 0, r = 0;
        
        while(r < n)
        {
            !freq[s[r]] ? freq[s[r++]]++ : freq[s[l++]]--;
            ans = max(ans, r - l);
        }
        
        return ans;
    }
};