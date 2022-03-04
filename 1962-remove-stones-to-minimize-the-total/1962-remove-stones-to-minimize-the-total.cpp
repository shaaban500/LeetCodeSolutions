class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        int n = piles.size();
        priority_queue<int> q;
        
        for(int i = 0 ; i < n ; i++)
            q.push(piles[i]);
        
        
        while(k)
        {
            if(q.empty()) break;
            int t = q.top();
            q.pop();
            t = t / 2 + (t % 2 != 0);
            q.push(t);
            k--;
        }
        
        int ans = 0;
        while(!q.empty())
        {
            ans += q.top();
            q.pop();
        }
        
        return ans;
    }
};