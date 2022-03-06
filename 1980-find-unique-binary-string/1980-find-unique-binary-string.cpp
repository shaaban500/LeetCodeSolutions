class Solution {
public:
    
    string findDifferentBinaryString(vector<string>& nums) 
    {
        map<string,int>mp;
        int m = nums.size();
        int n = nums[0].size();

        for(int i = 0 ; i < m ; i++)   
            mp[nums[i]] = 1;
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                string t = nums[i];
                t[j] = (t[j] == '1')? '0' : '1';
                if(!mp[t])
                    return t;
            }
        }
       
        return "";
    }
};
