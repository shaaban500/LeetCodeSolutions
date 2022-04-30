class Solution {
public:
    int maximumProduct(vector<int>& nums, int k)
    {
        int mod = 1e9 + 7;
        int n = nums.size();
        priority_queue <int, vector<int>, greater<int>> q;
        
        for(int i = 0 ; i < n ; i++)
            q.push(nums[i]);
        
        while(k--)
        {
            int min = q.top();
            q.pop();
            q.push(++min);
        }
        
        long long product = 1;
        while(!q.empty())
        {
            int num = q.top(); q.pop();
            product = (product * num) % mod;
        }
        
        return product;
    }
};