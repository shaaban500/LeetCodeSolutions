class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int l = lower_bound(nums,nums.size() , target);
        int u = upper_bound(nums,nums.size() , target);
    
        vector<int>v;
        
        if(l==nums.size() || nums[l]!=target){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }

        v.push_back(l);
        v.push_back(u-1);
        return v;
        
    }
    
    
    
    int lower_bound(vector<int> arr , int N, int X)
    {
        int mid,low = 0, high = N;
        while (low < high) 
        {
            mid = low + (high - low) / 2;
            if (X <= arr[mid]) high = mid;
            else low = mid + 1;
        }
        if(low < N && arr[low] < X) low++;

        return low;
    }

    int upper_bound(vector<int>arr, int N, int X)
    {
        int mid,low = 0,high = N;

        while (low < high)
        {
            mid = low + (high - low) / 2;

            if (X >= arr[mid]) low = mid + 1;
            else high = mid;	
        }

        if(low < N && arr[low] <= X) low++;

      return low;
    }
    
    
    
    
};