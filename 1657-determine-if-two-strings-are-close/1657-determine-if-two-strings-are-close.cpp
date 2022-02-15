class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        int freq1[26] = {} , freq2[26] = {};
        
        for(int i=0 ; i<word1.size() ; i++)
            freq1[word1[i]-'a']++;
        
        for(int i=0 ; i<word2.size() ; i++)
            freq2[word2[i]-'a']++;

        
        for(int i=0 ; i<26 ; i++)
            if((!freq1[i] && freq2[i]) || (!freq2[i] && freq1[i])) 
                return false;
        
        sort(freq1 , freq1+26);
        sort(freq2 , freq2+26);
        
        for(int i=0 ; i<26 ; i++)
            if(freq1[i] != freq2[i]) 
                return false;
        
        return true;
    }
};