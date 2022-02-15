class Solution {
public:
    int minDeletions(string s)
    {
      
        int f[26]={};
	for(int i=0 ; i<s.size() ; i++)
		f[s[i]-'a']++;


	sort(f,f+26,greater<int>());
	int ans = 0;
	int mx = f[0]-1;
	for(int i=1 ; i<26 ; i++)
	{
		if(!f[i]) break;
		if(f[i]>mx) {
			ans += (f[i]-mx);
			f[i] = mx;
		}
			mx = max(f[i]-1,0);
	}
        return ans;
    }
};