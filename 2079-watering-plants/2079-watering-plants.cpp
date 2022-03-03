class Solution
{
public:
    int wateringPlants(vector<int>& plants, int capacity) 
    {
        int steps = 0;
        int c = capacity;
        int n = plants.size();
        
        for(int i = 0 ; i < n ; i++)
        {
            if(capacity >= plants[i])
            {
                capacity -= plants[i];
                steps++;
            }
            else
            {
                steps += i * 2 + 1;
                capacity = c;
                capacity -= plants[i];
            }          
        }
        
        return steps;
    }
};
    