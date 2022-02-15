class Solution {
public:
    int clumsy(int n)
    {
        int sum;
        vector<int>v;
        for(int i=n ; i>=1 ; i-=4)
        {
            if(i>=4)
            {
                sum = i*(i-1)/(i-2);
                v.push_back(sum);
                v.push_back(i-3);
            }
            else
            {
                if(i==3) sum = i*(i-1)/(i-2);
                if(i==2) sum = i*(i-1);
                if(i==1) sum = i;
            
                v.push_back(sum);
                break;
            }
        }
        
        sum = 0;
        bool f = 0; 
        for(int i=0 ; i<v.size() ; i++ , f=!f)
        {
            if(i<2 || f) sum += v[i];
            else if(!f) sum -= v[i]; 
            cout << v[i] << " ";
        }
        
        return sum;
        
    }
};