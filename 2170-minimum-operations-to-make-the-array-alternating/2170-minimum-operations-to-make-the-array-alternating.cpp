class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n = nums.size();
        int freq1[100005] = {};
        int freq2[100005] = {};
        int mx11 = -1e9;
        int mx12 = -1e9;
        int mx21 = -1e9;
        int mx22 = -1e9;
        
        for(int i = 0 ; i < n ; i++)
            !(i&1)? freq1[nums[i]]++ : freq2[nums[i]]++;
    
        int a[2] = {}, b[2] = {};
        for(int i = 0 ; i < 100001 ; i++)
        {
            if(freq1[i] > mx11) 
            {
                if(mx11)mx12 = mx11; 
                mx11 = freq1[i];
                a[1] = a[0];
                a[0] = i;
            }
            else if(freq1[i] > mx12)
            {
                mx12 = freq1[i];
                a[1] = i;
            }
        }
        for(int i = 0 ; i < 100001 ; i++)
        {
            if(freq2[i] > mx21) 
            {
                if(mx21) mx22 = mx21; 
                mx21 = freq2[i];
                b[1] = b[0];
                b[0] = i;
            }
            else if(freq2[i] > mx22)
            {
                mx22 = freq2[i];
                b[1] = i;
            }
        }

        int mnAns = 1e9;
        int operations = 0;
        int first = (n&1)? (n+1) / 2 : n / 2;
        int second = n / 2;
        
        
        for(int i = 0 ; i < 2 ; i++)
        {
            for(int j = 0 ; j < 2 ; j ++)
            {
                if(a[i] != b[j])
                {
                    operations = first - freq1[a[i]];
                    operations += second - freq2[b[j]];
                    mnAns = min(mnAns, operations);
                }
            }
        }
        
        return mnAns;
        
    }
};