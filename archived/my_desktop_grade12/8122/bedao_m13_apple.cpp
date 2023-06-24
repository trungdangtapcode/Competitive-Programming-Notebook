#include<bits/stdc++.h>

using namespace std;
long long int n, m;
int f[1005][5];
vector<bool> v;

int dp(int x, bool player){
	if (x>=v.size()) return 0;
	if (f[x][player]!=-1) return f[x][player];
	int res = !dp(x+1,!player);
	if (v[x]) res |= dp(x+1,player);
	return f[x][player] = res;
}

void solve(){
	cin >> n >> m;
	if (n<m) swap(n,m);
	
	memset(f,-1,sizeof(f));
	v.clear();
	while (m){
		if (n/m==1) v.push_back(false); else v.push_back(true);
		n %= m;
		if (n<m) swap(n,m);
	}
	cout << (dp(0,1)?"copium\n":"illya\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int q; cin >> q;
//	q = 1;
	while (q--) solve();
	
	return 0;
}


//	long long int res = 0;
//	while (m){
//		res += n/m;
//		n %= m;
//		if (n<m) swap(n,m);
//		res = !res;
//	}
//	cout << (res%2?"copium\n":"illya\n");

//	if (n/m==1) cout << "illya\n"; else cout << "copium\n";
