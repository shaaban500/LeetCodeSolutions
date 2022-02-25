class Solution
{
public:
    bool IsVowel(char c)
    {
        return (c == 'a' || c == 'o' || c == 'e'|| c == 'u'|| c == 'i');
    }
    
    long long countVowels(string word) 
    {
        long long ans = 0;
        long long n = word.size();
        long long curSum = 0;
        
        for(int i = 0 ; i < n ; i++)
        {   
            curSum = (n - i) * (i + 1);
            
            if(IsVowel(word[i]))
                ans += curSum;
        }
        
        return ans;
    }
};