class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int n = colors.size(), i = 0, j = n - 1;
        while(colors[i] == colors[n - 1]) i++;
        while(colors[0] == colors[j]) j--;
        return max(j, n - i - 1);        
    }
};