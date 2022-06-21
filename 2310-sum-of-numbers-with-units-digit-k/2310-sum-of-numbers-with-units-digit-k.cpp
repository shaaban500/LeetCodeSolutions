class Solution {
public:
    int minimumNumbers(int num, int k) 
    {
        int x = -1;
        
        if(!num)
            return 0;
        
        for(int i = 1 ; i <= 10 ; i++)
        {
            if(num % 10 == (i * k) % 10)
            {
                x = i;
                break;
            }
        }
        
        int ret = num - (x * k);
        if(x == -1 || ret % 10 || ret + x * k != num || ret < 0)
            return -1;
            
        return x;
    }
};
    