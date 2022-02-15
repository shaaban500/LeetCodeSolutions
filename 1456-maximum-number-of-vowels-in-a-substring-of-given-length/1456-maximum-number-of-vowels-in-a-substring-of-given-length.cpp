class Solution {
public:
    
    bool isVowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); 
    }
    
    
    int maxVowels(string s, int k) 
    {
        int cnt = 0;
        
        for(int i=0 ; i<k ; i++)
        {
            if(isVowel(s[i]))
                cnt++;            
        }

        int mx = cnt;
        
        for(int i=1,j=k ; j<s.size() ; i++,j++)
        {
            if(isVowel(s[i-1])) cnt--;
            
            if(isVowel(s[j])) cnt++;
                
            mx = max(mx , cnt);           
        }
        
        return mx;
    }
};
