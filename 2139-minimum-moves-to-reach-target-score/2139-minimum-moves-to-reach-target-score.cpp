class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        int cnt = 0;
        while(target>1)
        {
            if(target&1) 
                target--, cnt++;
            else
            {
                if(maxDoubles) target /= 2, cnt++ , maxDoubles--;
                else cnt += (target - 1), target = 0;
            }
        }
        
        return cnt;
    }
};


