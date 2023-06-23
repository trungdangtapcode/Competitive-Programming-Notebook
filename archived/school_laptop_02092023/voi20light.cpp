#include<bits/stdc++.h>
//[1]: cac cach chon co thu tu khong quan trong
//[2]: khong chon qua 2 lan
//[3]: cac cong tac PHAN BIET
//[1]+[3] => duyet tu (1,1) den (n,m) => frefix
//[2] => need => val = {0,1,2} => change

using namespace std;
int n, m, k, u[100005], v[100005], x[100005], y[100005];
vector<vector<int>> f, a, op;
int solve(int d){
	int res = 0;
	f.assign(n+2,vector<int>(m+2));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1]; //+= not = fuckkkk
			((f[i][j] %= 3) += 3) %= 3;
			if ((a[i][j]+f[i][j])%3!=d){
				if (!op[i][j]) return 1e9;
				int t = op[i][j], val = ((d-a[i][j]-f[i][j])%3+3)%3;
				res += val;
				f[u[t]][v[t]]+=val;
				f[u[t]][y[t]+1]-=val;
				f[x[t]+1][v[t]]-=val;
				f[x[t]+1][y[t]+1]+=val;
			}
		}
	}
	return res;
}

int main(){
	cin >> n >> m >> k;
	a.assign(n+1,vector<int>(m+1));
	op.assign(n+1,vector<int>(m+1));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		cin >> a[i][j];
	}
	for (int i = 1; i <= k; i++){
		cin >> u[i] >> v[i] >> x[i] >> y[i];
		op[u[i]][v[i]] = i;
	}
	int res = min(solve(1),solve(2));
	cout << (res==1e9?-1:res) << "\n";
	
	return 0;
}
