class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        int a = 0 , b = 0;
        for(int i=0 ; i<colors.size() ; )
        {
            int x = 0 , y = 0;
            
            if(i<colors.size() && colors[i] == 'A')
            {
               while(colors[i] == 'A') x++,i++; 
            }
            if(i<colors.size() && colors[i] == 'B')
            {
               while(colors[i] == 'B') y++,i++; 
            }
            
            a += max(0 , x - 2);
            b += max(0 , y - 2);
        }
        
        return a>b;
        
    }
};