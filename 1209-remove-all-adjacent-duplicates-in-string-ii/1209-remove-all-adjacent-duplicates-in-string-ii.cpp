class Solution
{
    public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char,int>>st;
        
        for(int i=0 ; i<s.size() ; i++)
        {
            if(!st.empty() && s[i]==st.top().first)
            {
                if(st.top().second < k-1) 
                    st.push({s[i] , st.top().second+1});
                else
                    while(!st.empty() && st.top().first==s[i])
                        st.pop();
            }
            else st.push({s[i] , 1});
            
        }
        
        string t = "";
        while(!st.empty())
        {
            t += st.top().first;
            st.pop();
        }
        reverse(t.begin() , t.end());
        return t;
    }
};