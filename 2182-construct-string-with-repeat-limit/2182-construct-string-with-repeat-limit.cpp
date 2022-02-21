class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        string t = "";
        int n = s.size();
        int freq[200] = {};
        bool again[200] = {};
        priority_queue <char>pq;

        for(int i = 0 ; i < n ; i++)
        {
            freq[s[i]]++;
            if(!again[s[i]]) pq.push(s[i]);
            again[s[i]] = 1;
        }
                 
        while(!pq.empty())
        {
            char top = pq.top();
            
            int a = freq[top];
            int b = repeatLimit;
            int c = min(a,b);
            
            for(int i = 0 ; i < c ; i++)
            {
                t += top;
                freq[top]--;
            }
            
            if(a <= b || !freq[top]) 
                pq.pop();
            else
            {
                if(pq.size() == 1) break;
                
                char prev = pq.top(); pq.pop();
                char cur = pq.top();
                
                if(!freq[cur]) break;
                
                freq[cur]--;
                if(!freq[cur]) pq.pop();
                t += cur;
                pq.push(prev);
            }
        }
        
        return t;
    }
};