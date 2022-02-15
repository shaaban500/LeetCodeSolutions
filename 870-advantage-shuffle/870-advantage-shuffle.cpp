class Solution 
{
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) 
    {
            int n = nums1.size();
            vector<int>v,c(n);
            priority_queue<int>p1;
            priority_queue<pair<int,int>>p2;

            for(int i=0 ; i<n ; i++)
            {
                p1.push(-nums1[i]);
                p2.push({-nums2[i] , i});
            }

            while(!p1.empty())
            {
                int t1 = -p1.top();
                int t2 = -p2.top().first;
                int idx = p2.top().second;
                if(t1>t2)
                {
                    c[idx] = t1;
                    p1.pop();
                    p2.pop();
                }
                else
                {
                    v.push_back(t1);
                    p1.pop();
                }
            }

            for(int i=0 ; i<n ; i++)
            {
                if(!c[i])
                {
                    c[i] = v.back();
                    v.pop_back();
                }
            }

            return c;
    }
};