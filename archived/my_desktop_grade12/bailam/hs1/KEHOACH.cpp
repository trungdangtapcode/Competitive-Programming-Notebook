#include<bits/stdc++.h>

using namespace std;
int n, q;
vector<int> a;
int main(){
	freopen("KEHOACH.INP","r",stdin);
	freopen("KEHOACH.OUT","w",stdout);
	cin >> n;
	a.assign(n,0);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(),a.end());
	cin >> q;
	while (q--){
		int x; cin >> x;
		cout << upper_bound(a.begin(),a.end(),x)-a.begin() << '\n';
	}
	return 0;
}
