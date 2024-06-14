#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], b[maxN], c[maxN], res[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]] = i;
		c[i] = 1;
		res[i] = 0;
	}
	int pos = b[1], s = n+2;
	for (int i = pos-1; i > 1; i -= 2){
		res[i] = s-a[i];
		c[s-a[i]] = 0;
	}
	for (int i = pos+1; i < n; i += 2){
		res[i] = s-a[i];
		c[s-a[i]] = 0;
	}
//	for (int i = 1; i <= n; i++) cout << res[i] << " "; cout << "\n";
	vector<int> v1,v2;
	for (int i = 1; i <= n; i++) if (c[i]) v2.push_back(i);
	for (int i = 1; i <= n; i++) if (!res[i]) v1.push_back(a[i]);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	reverse(v2.begin(),v2.end());
	for (int i = 0; i < v1.size(); i++) res[b[v1[i]]] = v2[i];
	for (int i = 1; i <= n; i++) cout << res[i] << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

