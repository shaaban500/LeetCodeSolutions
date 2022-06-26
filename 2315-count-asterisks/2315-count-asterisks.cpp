class Solution {
public:
    int countAsterisks(string s) 
    {
        int cnt = 0, ans = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '|')
                cnt++;
            
            if(s[i] == '*' && cnt % 2 == 0)
                ans++;
        }
        return ans;
    }
};