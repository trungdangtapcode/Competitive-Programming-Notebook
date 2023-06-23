#include<bits/stdc++.h>

using namespace std;
int n, g[4][4], cnt;
//vector<pair<int,int>> res;
//int res[50000005];
string res;

void build(int k, int s, int t, int tmp){
	if (k==1){
		if (g[s][t]){
//			res[3*cnt] = s;
//			res[3*cnt+1] = t; 
//			res[3*cnt+2] = '\n';
			res.push_back(s-1+'A');
			res.push_back(t-1+'A');
			res.push_back('\n');
			cnt++;
		} else {
//			res[3*cnt] = s;
//			res[3*cnt+1] = t;
//			res[3*cnt+2] = '\n';
			res.push_back(s-1+'A');
			res.push_back(tmp-1+'A');
			res.push_back('\n');
			res.push_back(tmp-1+'A');
			res.push_back(t-1+'A');
			res.push_back('\n');
			cnt+=2;
		}
		return;
	}
	if (g[s][t]){
		build(k-1,s,tmp,t);
		build(1,s,t,tmp);
		build(k-1,tmp,t,s);
	} else {
		build(k-1,s,t,tmp);
		build(1,s,tmp,t);
		build(k-1,t,s,tmp);
		build(1,tmp,t,s);
		build(k-1,s,t,tmp);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) cin >> g[i][j];
	if (n==1){
		if (g[1][3]) cout << "1\nAC";
		else cout << "2\nAB\nBC";
		return 0;
	}
	build(n,1,3,2);
	cout << cnt << "\n";
	cout << res;
//	cout << res.size() << "\n";
//	for (auto it: res){
//		cout << (char)(it.first-1+'A') << (char)(it.second-1+'A') << '\n';
//	}
	return 0;
}
