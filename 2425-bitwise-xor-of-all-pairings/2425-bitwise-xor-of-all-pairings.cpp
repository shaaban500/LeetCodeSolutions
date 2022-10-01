class Solution {
public:
    int xorAllNums(vector<int>& num1, vector<int>& num2) 
    {
        int n = num1.size();
        int m = num2.size();
        int XOR = 0;

        if(m & 1)
        {
            for(int i = 0 ; i < n ; i++)
            {
               XOR = XOR ^ num1[i];
            }
        }
        if(n & 1)
        {
            for(int i = 0 ; i < m ; i++)
            {
               XOR = XOR ^ num2[i];
            }
        }
        
        return XOR;
    }
};