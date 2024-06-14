#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
class Solution {
public:
    int specialPerm(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> f(n,vector<int>((1<<n)+1,-1));
        function <int(int,int)> dfs = [&] (int i, int mask)
	    {
	    	if (mask==(1<<n)-1) return 1;
	        if (f[i][mask]!=-1) return f[i][mask];
	        f[i][mask] = 0;
	        for (int j = 0; j < n; j++){
	        	if ((mask>>j)&1) continue;
	        	if (a[i]%a[j]&&a[j]%a[i]) continue;
	        	(f[i][mask] += dfs(j,mask^(1<<j)))%=mod;
			} 
			return f[i][mask];
	    };
	    int res = 0;
	    for (int i = 0; i < n; i++) (res += dfs(i,1<<i))%=mod;
	    return res;
    }
};

main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	Solution x;
	cout << x.specialPerm(a);	
}
