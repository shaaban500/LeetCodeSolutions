class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        int n = tasks.size();
        unordered_map<int, int> mp;
        
        for(int i = 0 ; i < n ; i++)
            mp[tasks[i]]++;
    
        int minimumRounds = 0;
        for(auto it : mp)
        {
            int count = it.second;
            
            if(count == 1)
                return -1;   
            
            minimumRounds += (count / 3) + (count % 3 != 0);
        }
        return minimumRounds;
    }
    
};