class Solution 
{
public:
    
    int minSwaps(string s) 
    {
        int cnt0 = 0, cnt1 = 0, cnt = 0,n = s.size();
        
        for(int i = 0 ; i < n ; i++)
            cnt += (s[i] == '1');
        
        if(cnt != n / 2 && cnt != (n + 1) / 2)
            return -1;
        
        bool x = 0;
        for(int i = 0 ; i < n ; i++, x = !x)
            if((s[i] == '1' &&  !x) || (s[i] == '0' &&  x)) 
                cnt0++;

        x = 1;
        for(int i = 0 ; i < n ; i++, x = !x)
            if((s[i] == '1' &&  !x) || (s[i] == '0' &&  x)) 
                cnt1++;
        
        if((cnt0 & 1) && (cnt1 & 1)) 
            return -1;
        
        if(cnt0 & 1) 
            return cnt1 / 2;
        
        if(cnt1 & 1) 
            return cnt0 / 2;
        
        return min(cnt0, cnt1) / 2;
        
    }
};