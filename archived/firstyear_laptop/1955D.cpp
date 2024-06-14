#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, m, k, a[maxN], b[maxN];
void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	multiset<int> sb, sa;
	for (int i = 1; i <= m; i++){
		cin >> b[i];
		sb.insert(b[i]);
	} 
	int res = 0;
	for (int i = 1, j = 0; i <= n-m+1; i++){
		while (j < i+m-1){
			j++;
			if (sb.find(a[j])!=sb.end()){
				sb.erase(sb.find(a[j]));
			} else sa.insert(a[j]);
		}
		if (m-sb.size()>=k) res++;
		if (sa.find(a[i])!=sa.end()){
			sa.erase(sa.find(a[i]));
		} else sb.insert(a[i]);
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

