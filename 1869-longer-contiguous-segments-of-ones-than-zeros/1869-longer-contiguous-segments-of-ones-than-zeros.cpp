class Solution {
public:
    bool checkZeroOnes(string s) 
    {
        int n = s.size();
        int one = 0, zero = 0;
        int mxOne = 0, mxZero = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '1')
            {
                one++;
                zero = 0;
            }
            else
            {    
                zero++;
                one = 0;
            }
            
            mxOne = max(mxOne, one);
            mxZero = max(mxZero, zero);
        }
        
        return mxOne > mxZero;
    }
};