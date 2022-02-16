class Solution {
public:
    long long smallestNumber(long long num) 
    {
        int zero = 0;
        vector<long long>v;
        long long x = abs(num);
        
        while(x > 0)
        {
            if(x % 10 == 0) zero++;
            else v.push_back(x % 10);
            x /= 10;
        }
                
        long long ans = 0;
        long long power = 1;

        if(num < 0 && v.size())
        {
            sort(v.begin(), v.end());
            for(int i = 0 ; i < v.size() ; i++, power *= 10)
                ans += v[i] * power;
            
            while(zero) power *= 10, zero--, ans *= 10;
            ans *= -1;
        }
        else if(v.size())
        {
            sort(v.rbegin(), v.rend());
            for(int i = 0 ; i < v.size() - 1 ; i++, power *= 10)
                ans += v[i] * power; 
            
            while(zero) power *= 10, zero--;
            ans += v[v.size() - 1] * power;
        }
        
        return ans;
    }
};