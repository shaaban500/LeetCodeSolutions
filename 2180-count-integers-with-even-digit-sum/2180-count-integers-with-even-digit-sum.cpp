class Solution {
public:
    int sumOfDigits(int x)
    {
        int sum = 0;
        while(x > 0)
        {
            sum += (x % 10);
            x /= 10;
        }
        
        return sum;
    }
    
    int countEven(int num) 
    {
        int ans = 0;
        for(int i = 1 ; i <= num ; i++)
        {
            if(sumOfDigits(i) % 2 == 0)
                ans++;
        }
        
        return ans;
    }
};