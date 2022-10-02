class Solution {
public:
    int xorAllNums(vector<int>& num1, vector<int>& num2) 
    {
        int XOR = 0;
        
        if(num2.size() & 1)
            for(int i = 0 ; i < num1.size() ; i++)
               XOR = XOR ^ num1[i];

        if(num1.size() & 1)
            for(int i = 0 ; i < num2.size() ; i++)
               XOR = XOR ^ num2[i];
        
        return XOR;
    }
};