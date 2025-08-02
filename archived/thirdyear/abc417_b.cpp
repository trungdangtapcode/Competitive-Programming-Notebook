#include<bits/stdc++.h>

using namespace std;
int n, m;
void solve(){
	cin >> n >> m;
	multiset<int> ms;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		ms.insert(x);	
	}
	for (int i = 1; i <= m; i++){
		int x;
		cin >> x;
		if (ms.count(x)){
			ms.erase(ms.find(x));
		}
	}
	for (int x: ms){
		cout << x << " ";
	}
	cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

