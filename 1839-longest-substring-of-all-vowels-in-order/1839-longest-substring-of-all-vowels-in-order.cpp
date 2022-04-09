class Solution {
public:
    int longestBeautifulSubstring(string s) 
    {
        int n = s.size();
        int cnt, j, ans = 0;
        string a = "aeiou", t = "";

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == 'a')
            {
                t = 'a';
                cnt = 1;
                j = i + 1;
                
                while(j < n && cnt < 6)
                {
                    if(s[j] != s[j - 1])
                    {
                        if(s[j] == a[cnt++])
                            t += s[j];
                        else 
                            break;
                    }
                    j++;
                }
                
                if(t == a)
                    ans = max(ans, j - i);
                
                i = j - 1;
            }
                
        }
        return ans;
    }
};