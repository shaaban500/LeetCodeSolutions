class Solution {
public:
    int minimumSum(int num)
    {
        vector<int>v;
        while(num>0)
        {
            v.push_back(num%10);
            num /= 10;
        }
        
        sort(v.begin(), v.end());
        
        int ans = 0;
        if(v.size()==3)
            ans = v[0]*10 + v[1] + v[2];
        
        else
            ans = v[0]*10 + v[1]*10 + v[2] + v[3];
        
        return ans;
    }
};