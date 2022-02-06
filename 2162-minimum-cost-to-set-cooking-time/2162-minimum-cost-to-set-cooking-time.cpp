class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) 
    {
        int mn = 1e9;
        for(int i=0 ; i<=9 ; i++)
            for(int j=0 ; j<=9 ; j++)
                for(int k=0 ; k<=9 ; k++)
                    {
                        int x = (i * 10 + j) * 60 + k * 10;
                        int l = targetSeconds - x; 
                        if(l >= 0 && l <= 9) 
                        {
                            int ans = 0;
                    
                            ans += (!i)? 0 : (i == startAt)? pushCost : pushCost + moveCost;
                            ans += (!i && !j)? 0 : (!i && j)? ((j==startAt)? pushCost : moveCost+pushCost) : (i==j)?pushCost : moveCost+pushCost;
                            ans += (!i && !j && !k)? 0 : (!i && !j && k)? ((k==startAt)? pushCost : moveCost+pushCost) : (k==j)?pushCost : moveCost+pushCost;
                            ans += (!i && !j && !k && !l)?0: (!i&&!j&&!k&&l)?((l==startAt)? pushCost : moveCost+pushCost) : (k==l)?pushCost : moveCost+pushCost;
                            
                            mn = min(mn, ans);
                        }
                        
                    }
        
        return mn;
    }
};