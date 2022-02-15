class Solution
{
public:
    vector<int> prevPermOpt1(vector<int>& arr)
    {
        stack<int>st;
        st.push(arr.size()-1);
        vector<int>v(arr.size() , -1);

        
        for(int i = arr.size() - 2 ; i >= 0 ; i--)
        {
            if(!st.empty() && arr[i] == arr[st.top()])
            {
                st.pop();
                st.push(i);
            }
            else if(!st.empty() && arr[i] < arr[st.top()])
            {
                st.push(i);
            }
            else
            {
                bool f = 0; 
                while(!st.empty() && arr[i] > arr[st.top()])
                {
                    int t = st.top(); st.pop();
                    v[t] = i;
                    f = 1;
                }
                st.push(i);
            
                if(f) break;
            
            }
        }
        
        for(int i = v.size()-1 ; i>=0 ; i--)
        {
            if(v[i] != -1)
            {
                swap(arr[i] , arr[v[i]]);    
                break;
            }
        }
        
        return arr;
        
    }
};