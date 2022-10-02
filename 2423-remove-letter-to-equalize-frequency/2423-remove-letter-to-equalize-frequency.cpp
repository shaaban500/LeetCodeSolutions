class Solution {
public:
    bool equalFrequency(string word) 
    {
        int d = 0;
        vector<int> freq(26, 0);
        
        for(int i = 0 ; i < word.size() ; i++)
            d += ++freq[word[i] - 'a'] == 1;
       
        set<int>st;
        for(int i = 0 ; i < 26 ; i++)
        {
            freq[i]--;
            st.clear();
            
            for(int j = 0 ; j < 26 ; j++)
            {
                if(freq[j])
                    st.insert(freq[j]);
            }    

            if(st.size() == 1)
                return true;
            
            freq[i]++;
        }

        return false;
    }
};