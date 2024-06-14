#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int specialPerm(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> f(n,vector<int>((1<<n)+1,-1));
        function <int(int,int)> dfs = [&] (int i, int mask)
	    {
	    	if (mask==(1<<n)-1) return a[i][0];
	        if (f[i][mask]!=-1) return f[i][mask];
	        f[i][mask] = 1e9;
	        for (int j = 0; j < n; j++){
	        	if ((mask>>j)&1) continue;
	        	f[i][mask] = min(f[i][mask],dfs(j,mask^(1<<j))+a[i][j]);
			} 
			return f[i][mask];
	    };
	    return dfs(0,1);
    }
};

main(){
	int n;
	cin >> n;
	vector<vector<int>> a(n,vector<int>(n));
	for (auto &x: a) for (auto &y: x) cin >> y;
	Solution x;
	cout << x.specialPerm(a);	
}
