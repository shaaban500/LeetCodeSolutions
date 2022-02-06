class Solution {
public:
    vector<string> divideString(string s, int k, char fill)
    {
        string t = "";
        vector<string>v;
        int n = s.size(),x=0;
        
        for(int i = 0 ; i < n ; i++)
        {
            t += s[i];
            x++;
            if(x==k) 
                x = 0, v.push_back(t), t = "";
        }
        
        if(x < k && x)
        {
            for(int i=x+1 ; i<=k ; i++)
                t += fill;
            
            v.push_back(t);
        }
        
        return v;
        
    }
};