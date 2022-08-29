class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        string alphabet = "";
        for(char c = 'a' ; c <= 'z' ; c++)
            alphabet += c;
        
        int n = 100000;
        vector<long long> prefixSum(n, 0);
        for(int i = 0 ; i < shifts.size() ; i++)
        {
            int l = shifts[i][0];
            int r = shifts[i][1];
            
            if(shifts[i][2] == 0)
            {
                prefixSum[l]--;
                prefixSum[r + 1]++;
            }
            else
            {
                prefixSum[l]++;
                prefixSum[r + 1]--;
            }
        }
        
        for(int i = 1 ; i < n ; i++)
        {
            prefixSum[i] += prefixSum[i - 1];
        }

        for(int i = 0 ; i < s.size() ; i++)
        {
            long long ascii = s[i] - 'a';
            ascii = ((ascii + prefixSum[i]) % 26 + 26) % 26;
            s[i] = alphabet[ascii];
        }
        
        return s;
    }
};