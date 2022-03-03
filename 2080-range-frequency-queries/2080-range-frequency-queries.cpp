class RangeFreqQuery {
public:
    vector<vector<int>> v;
    RangeFreqQuery(vector<int>& a)
    {
        int n = a.size();
        v.resize(100005);
        for(int i = 0 ; i < n ; i++)
            v[a[i]].push_back(i);    
    }
    
    int query(int left, int right, int value) 
    {
        int l = lower_bound(v[value].begin(), v[value].end(), left) - v[value].begin();
        int r = lower_bound(v[value].begin(), v[value].end(), right) - v[value].begin();    
        if(r==v[value].size() || v[value][r] > right) r--;
        if(l == v[value].size() || v[value][l] > right) return 0;
        cout << l << " "<<r<<endl;
        
        return r - l  + 1;
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */