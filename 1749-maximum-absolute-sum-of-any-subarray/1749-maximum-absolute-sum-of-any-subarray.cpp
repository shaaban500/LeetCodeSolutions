class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int maxPos = 0 , maxNeg = 0 , curSum = 0;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            curSum += nums[i];
            if(curSum<0) curSum = 0;
            maxPos = max(maxPos , curSum); 
        }
       
        curSum = 0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            curSum += nums[i];
            if(curSum>0) curSum = 0;
            maxNeg = min(maxNeg , curSum); 
        }
        return max(maxPos , abs(maxNeg));

    }
};