#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> a;

bool check(int d){
	int last_pos = -1e9, res = 0;
	for (int i = 0; i < n; i++){
		if (a[i]-last_pos>=d) last_pos = a[i], res++;
	}
	return (res>=m);
}

int main(){
	freopen("TRAIBO.INP","r",stdin);
	freopen("TRAIBO.OUT","w",stdout);
	
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		a.assign(n,0);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(),a.end());
		int h = a[n-1], l = 0, m, res = 0;
		while (l<=h){
			m = (l+h)/2;
			if (check(m)){
				l = m + 1;
				res = m;
			} else h = m - 1;
		}
		cout << res << "\n";
	}
	
	return 0;
}
