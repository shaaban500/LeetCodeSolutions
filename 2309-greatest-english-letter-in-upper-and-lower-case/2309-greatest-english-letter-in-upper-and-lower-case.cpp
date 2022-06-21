class Solution {
public:
    string greatestLetter(string s) 
    {
        char mx = 'A';
        bool flag = 0;
        unordered_map<char, bool> found;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if('a' <= s[i] && s[i] <= 'z')
            {
                char capitalChar = toupper(s[i]);
                if(found[capitalChar])
                {
                    if(capitalChar > mx)
                        mx = capitalChar;
                    flag = 1;
                }
            }
            else
            {
                char smallChar = tolower(s[i]);
                if(found[smallChar])
                {
                    if(s[i] > mx)
                        mx = s[i];
                    flag = 1;
                }
            }
            
            found[s[i]] = 1;
        }
        
        string ans = "";
        ans += mx;
        
        if(!flag)
            return "";
       
        else 
            return ans;
    }
};