class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) 
    {
        unordered_map<int,int> curPlace;
        
        for(int i = 0 ; i < nums.size() ; i++)
            curPlace[nums[i]] = i;
        
        for(int i = 0 ; i < operations.size() ; i++)
        {
            int num = operations[i][0];
            int toBeNum = operations[i][1];
            int lastPlace = curPlace[num];
            nums[lastPlace] = toBeNum;
            curPlace[toBeNum] = lastPlace;
        }
        
        return nums;
    }
};