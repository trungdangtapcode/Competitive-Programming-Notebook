#include<bits/stdc++.h>

using namespace std;
int m, k, a, b;
void solve(){
	cin >> m >> k >> a >> b;
	m -= min(m/k,b)*k;
	//m-res*k <= a => res*k >= m-a
	//m-res*k >= 0 => res*k <= m
//	cout << ((m-a+k-1)/k>m/k?m/k << "\n";
	int res = max((m-a)/k,0);
	m -= res*k;
	if (m>a){
		if (m-k>=0) res++;
		else res += m-a;
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

