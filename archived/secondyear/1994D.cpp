#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 5005;
int n, a[maxN], c[maxN], f[maxN];
void solve(){
	cin >> n; 
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) c[i] = 1;
	vector<ii> res;
	for (int i = n-1; i >= 1; i--){
		for (int j = 0; j < i; j++) f[j] = -1;
		for (int j = 1; j <= n; j++) if (c[j]){
			int x = a[j]%i;
			if (f[x]!=-1){
				c[j] = 0;
				res.push_back({f[x],j});
				break;
			}
			f[x] = j;
		}
	}
	cout << "YES\n";
	reverse(res.begin(),res.end());
	for (auto it: res){
		cout << it.first << " " << it.second << "\n";
	}
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

