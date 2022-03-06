class Solution {
public:
    
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums[0].size();
        int m = nums.size();
        map<string,int>mp;
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
/*
    111
    000
        
    010
    101 
        
    100
    011
        
    001  
    110
        
        
     1010
     0101
     
     
     1011
     0100
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
   */