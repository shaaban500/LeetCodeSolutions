class Solution
{
public:
    vector<int> ans;
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < numbers.size() ; i++)
        {
            if(mp[target - numbers[i]] != 0)
            {
                ans.push_back(mp[target - numbers[i]]);
                ans.push_back(i + 1);
            }
            mp[numbers[i]] = i + 1;
        }
        return ans;
    }
};