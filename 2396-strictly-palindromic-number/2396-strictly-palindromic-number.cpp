class Solution {
public:
    bool isStrictlyPalindromic(int n)
    {
        for(int i = 2 ; i < n - 1 ; i++)
        {
            string s = convertToBaseB(n, i);
            if(!isPalindrome(s))
            {
                return false;
            }
        }
        return true;
    }
    
    
    bool isPalindrome(string s)
    {
        int n = s.size();
        for(int i = 0 ; i < n / 2 ; i++)
        {
            if(s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
    
    string convertToBaseB(int n, int b)
    {
        string s = "";
        while(n > 0) 
        {
            s += (char) ((n % b) + '0');
            n /= b;
        }
        return s;
    }
    
};