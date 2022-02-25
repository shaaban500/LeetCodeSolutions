class Solution {
public:
    int countVowelSubstrings(string word) 
    {
        int ans = 0;
        int n = word.size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                
                if(i>=j) break;
                bool f=1,a=0,o=0,I=0,e=0,u=0;
                for(int k = i ; k <= j ; k++)
                {
                    a |= (word[k] == 'a');
                    o |= (word[k] == 'o');
                    e |= (word[k] == 'e');
                    u |= (word[k] == 'u');
                    I |= (word[k] == 'i');
                    
                    if(word[k] != 'a' && word[k] != 'o' && word[k] != 'u' && word[k] != 'e' && word[k] != 'i')
                        f = 0;
                };
                ans += (f && a && o && u && e && I);
            }
        }
        
        return ans;
    }
};