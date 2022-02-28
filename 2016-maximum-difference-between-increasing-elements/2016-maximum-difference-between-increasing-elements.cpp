class Solution 
{
public:
    // O(n)time , O(1) space memory
    int maximumDifference(vector<int>& nums) 
    {
        int maxDif = -1;
        int mn = nums[0];
        int n = nums.size();

        for(int i = 1 ; i < n ; i++)
        {
            maxDif = max(maxDif, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        
        return maxDif == 0 ? -1 : maxDif;
    }    
};


/*
// O(n) time , O(n) space memory
int maximumDifference(vector<int>& nums) 
{
    int maxDif = -1;
    int n = nums.size();
    vector<int> mn(n), mx(n);

    mn[0] = nums[0];
    for(int i = 1 ; i < n ; i++)
        mn[i] = min(mn[i - 1], nums[i]);

    mx[n - 1] = nums[n -1];
    for(int i = n - 2 ; i >= 0 ; i--)
        mx[i] = max(mx[i + 1], nums[i]);


    for(int i = 0 ; i < n ; i++)
        if(mx[i] != mn[i])
            maxDif = max(maxDif, mx[i] - mn[i]);            

    return maxDif;
}



// Brute Force Solution
// O(n^2) time, O(1) space memory
int maximumDifference(vector<int>& nums) 
{
    int mx = -1;
    int n = nums.size();
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j ++)
        {
           if(nums[j] > nums[i])
               mx = max(mx, nums[j] - nums[i]);
        }
    }

    return mx;
}

*/













