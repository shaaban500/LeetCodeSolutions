class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        int equal = 0;
        vector<int>left,right;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] < pivot)
                left.push_back(nums[i]);

            if(nums[i] > pivot)
                right.push_back(nums[i]);
            
            if(nums[i] == pivot)
                equal++;
        }
        
        vector<int>ans;
        
        for(int i=0 ; i<left.size() ; i++)
            ans.push_back(left[i]);
        
        for(int i=0 ; i<equal ; i++)
            ans.push_back(pivot);
        
        for(int i=0 ; i<right.size() ; i++)
            ans.push_back(right[i]);
        
        return ans;
        
    }
};