class Solution {
public:
    int countOperations(int a, int b) 
    {
        int op = 0;
        while(a>0 &&  b>0)
        {
            a >= b ? a -= b : b -= a;
            op++;
        }
        return op;
    }
};