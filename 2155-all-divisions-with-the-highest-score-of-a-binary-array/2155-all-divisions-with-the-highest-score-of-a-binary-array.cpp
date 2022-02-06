class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) 
    {
        int n = nums.size();
        int a[100005]={}, b[100005]={};
       
        if(nums[0]==0) 
            a[0] =1;
        
        for(int i=1 ; i<n ; i++)
        { 
            a[i] = a[i-1];
            if(nums[i]==0) 
                a[i]++;
        }
        
        if(nums[n-1]==1)  
            b[n-1]=1;    
        
        for(int i=n-2 ; i>=0 ; i--)
        {       
            b[i] = b[i+1];
            if(nums[i]==1) 
                b[i]++;
        }
        
        vector<int>v;
        int mx = 0, mxa = 0, mxb = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            mxa = a[i];
            mxb = b[i+1];
            mx = max(mxa+mxb, mx);
        }
        
        mx = max(a[n-1], mx);
        mx = max(b[0], mx);
        
        if(b[0]==mx) 
            v.push_back(0);
        
        for(int i=0 ; i<n ; i++)
        {
            mxa = a[i];
            mxb = b[i+1];
            if(mxa+mxb == mx)
                v.push_back(i+1);
        }
        
        return v;

    }
};