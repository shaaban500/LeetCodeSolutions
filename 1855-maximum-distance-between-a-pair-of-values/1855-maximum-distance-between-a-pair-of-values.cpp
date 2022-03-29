class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) 
    {
        int mx = 0;
        int n = a.size();
        int m = b.size();
        reverse(b.begin(), b.end());
        for(int i = 0 ; i < n ; i++)
        {
            int l = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            int position = m - 1 - l;
            if(position <= i || l == m) continue;
            mx = max(mx, position - i);
        }
        return mx;
    }
};