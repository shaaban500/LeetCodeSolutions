class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        string word = "";
        vector<vector<string>> ans(searchWord.size());
        sort(products.begin(), products.end());
        
        for(int i = 0 ; i < searchWord.size() ; i++)
        {
            word += searchWord[i];
           
            auto it = lower_bound(products.begin(), products.end(), word);
            
            for (; it != end(products) && it->substr(0, i + 1) == word && ans[i].size() < 3; ++it)
                ans[i].push_back(*it);
        }
        
        return ans;
    }
};