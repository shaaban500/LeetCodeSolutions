// this sol can also be right without partail sum 
// just count +1 if current char is 'c' and -1 if it is 'k'
// Feel free to ask me for help or clarifications
class Solution
{
public:
	int minNumberOfFrogs(string s) 
	{
		int n = s.size();
		queue<int> c, r, o, a;
		vector<int> partialSum(n + 2, 0);

		for(int i = 0 ; i < n ; i++)      
		{
			if(s[i] == 'c') c.push(i);
			if(s[i] == 'r') r.push(i);
			if(s[i] == 'o') o.push(i);
			if(s[i] == 'a') a.push(i);
			if(s[i] == 'k')
			{
				if(c.empty() || r.empty() || o.empty() || a.empty())
					return -1;

				int topC = c.front(); c.pop();
				int topR = r.front(); r.pop();
				int topO = o.front(); o.pop();
				int topA = a.front(); a.pop();

				if(!(topC < topR && topR < topO && topO < topA))
					return -1;

				partialSum[topC] += 1;
				partialSum[i + 1] -= 1;
			}
		}

		if(!c.empty() || !r.empty() || !o.empty() || !a.empty())
			return -1;

		for(int i = 1 ; i < n ; i++)
			partialSum[i] += partialSum[i - 1];    

		int ans = -1;
		for(int i = 0 ; i < n ; i++)
			ans = max(ans, partialSum[i]);

		return ans;
	}
};