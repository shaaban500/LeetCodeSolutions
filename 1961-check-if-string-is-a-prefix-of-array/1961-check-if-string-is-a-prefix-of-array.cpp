class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) 
    {
        string con = "";
        int n = words.size();
        for(int i = 0 ; i < n ; i++)
        {
            con += words[i];
            if(con == s)
                return true;
        }
        return false;
    }
};