class Solution 
{
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        int n = special.size();

        sort(special.begin(), special.end());

        int maxConsecutive = special[0] - bottom;
        
        for(int i = 1 ; i < special.size() ; i++)
            maxConsecutive = max(maxConsecutive, special[i] - special[i - 1] - 1);
        
        maxConsecutive = max(maxConsecutive, top - special[n - 1]);

        return maxConsecutive;
    }
};