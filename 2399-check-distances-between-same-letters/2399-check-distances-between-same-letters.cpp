class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
        vector<int> last(26, -1);
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(last[s[i] - 'a'] == -1)
            {
                last[s[i] - 'a'] = i;
            }
            else if(distance[s[i] - 'a'] != i - last[s[i] - 'a'] - 1)
            {
                return false;
            }
        }
        return true;
   
    }
};