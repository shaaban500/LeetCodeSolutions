class Solution {
public:
    int minDifference(vector<int>& nums)
    {
        sort(nums.begin() , nums.end());
        /*
            0 3
            1 2
            2 1
            3 0
        */
        
        if(nums.size()<=3){
            return 0;
        }
        
        int ans = INT_MAX;
        int a=0,b=3;
        for(int i=a ; i<4 ; i++)
        {
            for(int j=b ; j>=0 ; j--)
            {
                if(i+j!=3) continue;
                ans = min(ans,nums[nums.size()-j-1]-nums[i]);
                
            }
        }
        return ans;
    }
};