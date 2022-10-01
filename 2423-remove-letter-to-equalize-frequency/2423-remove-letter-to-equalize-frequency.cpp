class Solution {
public:
    bool equalFrequency(string word) 
    {
        int n = word.size();
        vector<int> freq(26, 0);
        int d = 0;
        for(int i = 0 ; i < n ; i++)
        {
            freq[word[i] - 'a']++;
            if(freq[word[i] - 'a'] == 1)
                d++;
        }
       
        int cnt = 0;
        bool f = 0;
        for(int i = 0 ; i < 26 ; i++)
        {
            f = 1;
            freq[i]--;
            set<int>st;
            for(int j = 0 ; j < 26 ; j++)
            {
                if(freq[j]) st.insert(freq[j]);    
            }
            
            if(st.size() == 1)
                return true;
            st.clear();
            freq[i]++;
        }
        
        return false;
        
    }
};