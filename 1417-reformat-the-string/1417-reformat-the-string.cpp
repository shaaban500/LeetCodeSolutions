class Solution {
public:
    string reformat(string s) 
    {
        int n = s.size();
        string a = "", b = "";
        
        for(int i = 0 ; i < n ; i++)
            (s[i] >= '0' && s[i] <= '9') ? a += s[i] : b += s[i];
        
        
        int x = a.size();
        int y = b.size();
        
        if(abs(x - y) > 1)
            return "";
        
        string ans = "";
        for(int i=0;i<n;i++) ans += " ";
        
        int l = 0, r = 0; 
        for(int i = 0 ; i < n ; i++)
            ans[i] = (x >= y) ? (i & 1) ? b[r++] : a[l++] : (i & 1)? a[l++] : b[r++];
        
        return ans;
    }
};