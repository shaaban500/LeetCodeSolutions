class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int m = flowerbed.size();
        
        if(m==1)
            return (n == 1 && !flowerbed[0]) || (!n && flowerbed[0]) ||(!n && !flowerbed[0]);
        
            
        if(!flowerbed[0] && !flowerbed[1] && n) 
            n--, flowerbed[0] = 1;
        
        for(int i = 1 ; i < m - 2 && n ; i++)
            if(!flowerbed[i] && !flowerbed[i + 1] && !flowerbed[i - 1] && n)
                n--, flowerbed[i] = 1;
            
        if(!flowerbed[m - 1] && !flowerbed[m - 2] && n) 
            n--, flowerbed[m - 2] = 1;
            
        return !n;    
        
    }
};