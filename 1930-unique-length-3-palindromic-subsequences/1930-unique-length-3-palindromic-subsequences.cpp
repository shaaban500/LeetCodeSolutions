class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        int n = s.size();
        int first[26], last[26];
        
        for(int i = 0 ; i < 26 ; i++)
            first[i] = n , last[i] = -1;

        for(int i = 0 ; i < n ;  i++)
        {
            int x = s[i] - 'a';
            first[x] = min(i, first[x]);
            last[x] = max(i, last[x]);
        }
 
        int sum = 0;
        for(int i = 0 ; i < 26 ; i++)
        {
            int l = first[i];
            int r = last[i];
        
            if(l < n && r > -1 && r - l > 1)
            {
                unordered_set<int>st;
                st.clear();
            
                for(int j = l + 1 ; j < r ; j++)
                    st.insert(s[j]);
                
                sum += st.size();
            }
        }
        
        return sum;    
    }
};