class Solution 
{
public:
    bool isRobotBounded(string instructions) 
    {
        int curDirection = 0;
        int curX = 0 , curY = 0;    
        int n = instructions.size();
        for(int i = 0 ; i < instructions.size()*4 ; i++)
        {
            if(instructions[i%n] == 'G')
            {
                int direction = (((curDirection%4)+4)%4);
                
                if(direction == 0) curY++;
                else if(direction == 1) curX--;
                else if(direction == 2) curY --;
                else curX++;
                
            }
            else if(instructions[i%n] == 'R')
                curDirection--;
            
            else if(instructions[i%n] == 'L')
                curDirection++;
            
        }
        if(curX==0 && curY==0)
            return true;
       
        return false;
    }
    
};