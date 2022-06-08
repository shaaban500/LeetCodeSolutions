class Solution 
{
public:
    int removePalindromeSub(string s) 
    {
        if(isPalindrome(s))
            return 1;
        
        return 2;
    }
    
    
    bool isPalindrome(string s)
    {
        int n = s.size();
        
        for(int i = 0 ; i < (n + 1) / 2 ; i++)
            if(s[i] != s[n - i - 1])
                return false;
    
        return true;
    }
    
};