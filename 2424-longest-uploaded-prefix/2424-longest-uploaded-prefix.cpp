class LUPrefix {
public:
    int nn;
    set<long long> st;
    unordered_map<int, int> mp;
    LUPrefix(int n) 
    {
        nn = n;    
        st.insert(1);
    }
    
    void upload(int video) 
    {
        if (!mp[video + 1])
           st.insert(video + 1);
        
        st.erase(video);
        mp[video]++;
               
    }
    
    int longest() 
    {
        return *st.begin() - 1;            
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */