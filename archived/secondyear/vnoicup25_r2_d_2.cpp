#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 205, inf = 1e18;
typedef pair<int,int> ii;
int n, s, l[3], c[3][maxN], sm[3][maxN], r[3][maxN];
ii f[maxN][maxN][maxN];

ii calc(int time, int cost, int current, int income){
	if (current>=cost) return {time,-(current-cost)};
	int need = cost - current;
	int time_need = (need +  income-1)/income;
	int time2 = time + time_need;
	return {time2, -(current+income*time_need-cost)};
}

void solve(){
	cin >> n >> s;
	for (int i = 0; i < 3; i++){
		cin >> l[i];
		for (int j = 1; j <= l[i]; j++){
			cin >> c[i][j];
		}
		for (int j = 1; j <= l[i]; j++){
			cin >> r[i][j];
			sm[i][j] = r[i][j]+sm[i][j-1];
		}
	}
	for (int i = 0; i <= l[0]; i++) for (int j = 0; j <= l[1]; j++) for (int k = 0; k <= l[2]; k++){
		f[i][j][k] = {inf,-inf};
	}
	f[0][0][0] = {0, 0};
	for (int i = 0; i <= l[0]; i++) for (int j = 0; j <= l[1]; j++) for (int k = 0; k <= l[2]; k++){
		int t = f[i][j][k].first, p = -f[i][j][k].second;
		if (t>n) continue;
		int income = s + sm[0][i] + sm[1][j] + sm[2][k];
		if (i<l[0]){
			auto it2 = calc(t, c[0][i+1], p, income);
			f[i+1][j][k] = min(f[i+1][j][k], it2);
		}
		if (j<l[1]){
			auto it2 = calc(t, c[1][j+1], p, income);
			f[i][j+1][k] = min(f[i][j+1][k], it2);
		}
		if (k<l[2]){
			auto it2 = calc(t, c[2][k+1], p, income);
			f[i][j][k+1] = min(f[i][j][k+1], it2);
		}
	}
	
	int res = 0;
	for (int i = 0; i <= l[0]; i++) for (int j = 0; j <= l[1]; j++) for (int k = 0; k <= l[2]; k++){
		int t = f[i][j][k].first, p = -f[i][j][k].second;
		if (t>n) continue;
		int income = s + sm[0][i] + sm[1][j] + sm[2][k];
		int money = (n-t)*income+p;
		res = max(res, money);
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

