class Solution {
public:

   bool canReach(string s, int minJump, int maxJump) {
        int n=s.size(),l=0,u; 
        vector<bool> dp(n,false);
        dp[0]=true;
     
        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            u=min(i+maxJump,n-1);   
           for(int j=max(l,i+minJump);j<=u;j++) 
            if(s[j]=='0') dp[j]=true;
           l=u+1; 
         }
        return dp[n-1];
    }
};