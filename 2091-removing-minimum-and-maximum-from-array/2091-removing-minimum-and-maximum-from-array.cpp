class Solution
{
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int n = nums.size();
        int idxMin, idxMax;
        int mn = 1e9, mx = -1e9;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] > mx) 
                mx = nums[i], idxMax = i;

            if(nums[i] < mn) 
                mn = nums[i], idxMin = i;
        }
        
        int choice1 = max(idxMin, idxMax) + 1;
        int choice2 = n - min(idxMin, idxMax);
        int choice3 = min(idxMin, idxMax) + 1 + n - max(idxMin, idxMax);
        
        return min(choice1, min(choice2, choice3));
        
    }
};