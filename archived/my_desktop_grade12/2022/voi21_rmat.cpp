#include<bits/stdc++.h>

using namespace std;

typedef pair<long long,int> ii;
int n, m;
int idx(int i, int j){
	return i*m+j;
}
ii converter(long long x){
	if (x==0) return {0,0};
	int res = 0;
	while (x%2==0){
		x >>= 1;
		res++;
	}
	return {x,res};
}
int calc(vector<int> a, int key){
	int n = a.size();
	if (n==0) return 0;
	if (key==0) return 1; 
	vector<vector<int>> dp(n+1,vector<int>(40,-1));
	for (int i = 0; i < n; i++) dp[i][a[i]] = i;
	for (int j = 1; j < 40; j++) for (int i = 0; i < n; i++){
		if (dp[i][j-1]!=-1) dp[i][j] = dp[dp[i][j-1]+1][j-1];
	}
	vector<int> f(n+1,0);
	for (int i = n-1; i >= 0; i--){
		f[i] = 1e9;
		for (int j = 0; j < 40; j++) if (dp[i][j]!=-1) f[i] = min(f[i],f[dp[i][j]+1]+1);
	}
//	for (auto it: a) cout << it << " "; cout << "=> " <<f[0] << endl;
	return f[0];
}
int solve(vector<long long> a){
	int n = a.size();
	vector<int> vec;
	int res = 0;
	long long last = -1e9;
	for (int i = 0; i < n; i++){
		ii x = converter(a[i]);
		if (last!=x.first) res += calc(vec,last), vec.clear();
		last = x.first;
		vec.push_back(x.second);
		if (i==n-1) res += calc(vec,last), vec.clear();
	}
	return res;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	cout << calc({1,1,2},1);
//	cout << solve({10,5,5,5,8});
	cin >> n >> m;
	vector<long long> sumrow(n), sumcol(m);
	for (int i = 0, a; i < n; i++) for (int j = 0; j < m; j++){
		cin >> a;
		sumrow[i] += a;
		sumcol[j] += a;
	}
	cout << solve(sumrow)*solve(sumcol);
	
	return 0;
}
