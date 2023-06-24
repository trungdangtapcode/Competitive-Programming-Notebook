#include <bits/stdc++.h>

using namespace std;
typedef pair<int,long long int> ll; //2^x*y
int n, m;
//int dp[1000005][25], f[1000005];
int x[1000005];

vector<int> v; //input vector
int calc(vector<int> x){
//	memset(dp,-1,sizeof(dp));
	vector<vector<int>> dp(x.size()+5,vector<int>(45,-1));
	for (int i = 0; i < x.size(); i++) dp[i][x[i]] = i;
	for (int i = 1; i < 40; i++)
		for (int j = 0; j < x.size(); j++){
			if (dp[j][i]!=-1) continue;
			if (dp[j][i-1]==-1) continue;
			dp[j][i] = dp[dp[j][i-1]+1][i-1];
		}

//	memset(f,1,sizeof(f));
	vector<int> f(x.size()+5,1000005);
	f[x.size()] = 0;
	for (int i = x.size()-1; i >= 0; i--){
		f[i] = x.size()-i;
		for (int j = 0; j < 40; j++) if (dp[i][j]!=-1){
			f[i] = min(f[i],f[dp[i][j]+1]+1);
		}
	}
	return f[0];
}

ll converter(long long int x){
	if (x==0) return {0,0};
	int a = 0; long long int b;
	while (x%2==0){
		a++;
		x /= 2;
	}
	b = x;
	return {a,b};	
}
int idx(int a, int b){
	return a*m+b;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> x[idx(i,j)];
	
	int res1 = 0, res2 = 0;
	long long int last;
	for (int i = 0; i < n; i++){
//		cout << i << ": "; for (int i: v) cout << i << " "; cout << endl;
		long long int sum = 0;
		for (int j = 0; j < m; j++) sum += x[idx(i,j)];
		ll tmp = converter(sum);
		if (!v.empty()&&last!=tmp.second) res1 += (last==0?1:calc(v)), v.clear(); //cuoi chac lay, dau ko lam
		v.push_back(tmp.first);
		if (i==n-1) res1 += (tmp.second==0?1:calc(v)), v.clear();
		last = tmp.second;
	}
//	cout << "passed";
	for (int i = 0; i < m; i++){
		long long int sum = 0;
		for (int j = 0; j < n; j++) sum += x[idx(j,i)];
		ll tmp = converter(sum);
		if (!v.empty()&&last!=tmp.second) res2 += (last==0?1:calc(v)), v.clear(); //cuoi chac lay, dau ko lam
		v.push_back(tmp.first);
		if (i==m-1) res2 += (tmp.second==0?1:calc(v)), v.clear();
		last = tmp.second;
	}
	cout << res1*res2 << '\n';
		
	return 0;
}

/*

#include <bits/stdc++.h>

using namespace std;
typedef pair<int,long long int> ll; //2^x*y
int n, m;
int dp[1000005][25], f[1000005], x[1000005];

vector<int> v; //input vector
int calc(vector<int> x){
//	for (int i = 0; i < x.size(); i++) cout << x[i] << " "; cout << endl;
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i < x.size(); i++) dp[i][x[i]] = i;
	for (int i = 1; i < 21; i++)
		for (int j = 0; j < x.size(); j++){
			if (dp[j][i]!=-1) continue;
			if (dp[j][i-1]==-1) continue;
			dp[j][i] = dp[dp[j][i-1]+1][i-1];
		}
//	for (int i = 0; i < 5; i++){
//		cout << i << ": \n";
//		for (int j = 0; j < x.size(); j++) cout << dp[j][i] << " ";
//		cout << endl;
//	}
	
	memset(f,1,sizeof(f));
	f[x.size()] = 0;
	for (int i = x.size()-1; i >= 0; i--){
		f[i] = x.size()-i;
		for (int j = 0; j < 21; j++) if (dp[i][j]!=-1){
			f[i] = min(f[i],f[dp[i][j]+1]+1);
		}
	}
//	for (int i = 0; i < 4; i++) cout << f[i] << " ";
	return f[0];
}

ll converter(long long int x){
	int a = 0; long long int b;
	while (x%2==0){
		a++;
		x /= 2;
	}
	b = x;
	return {a,b};	
}
int idx(int a, int b){
	return a*m+b;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> x[idx(i,j)];
//	solve({3,1,1,2});
	
	int res1 = 0, res2 = 0;
	long long int last;
	for (int i = 0; i < n; i++){
		long long int sum = 0;
		for (int j = 0; j < m; j++) sum += x[idx(i,j)];
		ll tmp = converter(sum);
		if (!v.empty()&&last!=tmp.second) res1 += calc(v), v.clear(); //cuoi chac lay, dau ko lam
		v.push_back(tmp.second);
		if (i==n-1) res1 += calc(v), v.clear();
		last = tmp.second;
	}
	for (int i = 0; i < m; i++){
		long long int sum = 0;
		for (int j = 0; j < n; j++) sum += x[idx(j,i)];
		ll tmp = converter(sum);
//		cout << sum << " " << tmp.first << " " << tmp.second << endl;
		if (!v.empty()&&last!=tmp.second) res2 += calc(v), v.clear(); //cuoi chac lay, dau ko lam
		v.push_back(tmp.first);
		if (i==m-1) res2 += calc(v), v.clear();
		last = tmp.second;
//		for (int it: v) cout << i <<". "<< it << " "; cout << endl;
	}
	cout << res1*res2 << '\n';
//	cout << calc()
		
	return 0;
}

*/
