class WordFilter {
public:
    unordered_map<string, int> dictionary;

    WordFilter(vector<string>& words) 
    {
        for(int i = 0 ; i < words.size() ; i++)
        {
            string word = words[i];
            for(int j = 0 ; j < word.size() ; j++)
            {
                string prefix = word.substr(0, j + 1);
                for(int k = word.size() - 1 ; k >= 0 ; k--)
                {
                    string suffix = word.substr(k);
                    string key = prefix + '+' + suffix;
                    dictionary[key] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
        string key = prefix + '+' + suffix;
        return (dictionary.count(key)) ? dictionary[key] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */