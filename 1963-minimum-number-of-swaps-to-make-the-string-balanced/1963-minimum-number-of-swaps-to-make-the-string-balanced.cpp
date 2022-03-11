class Solution {
public:
    int minSwaps(string s) 
    {
        int swaps = 0;
        stack<char>st;
        int n = s.size();
        
        for(int i = 0 ; i < n ; i ++)
        {
            if(s[i] == '[') st.push('[');
            else
            {
                if(st.empty()) st.push(']');
                else st.pop();
            }
        }
        
        return st.size() / 2;
    
    }
};
