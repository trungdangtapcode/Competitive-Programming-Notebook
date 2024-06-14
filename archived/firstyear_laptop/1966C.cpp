#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	a.push_back(0);
	sort(a.begin(),a.end());
	int last = 0, f = 0;
	a.erase(unique(a.begin(),a.end()),a.end());
	for (int i = a.size()-2; i >= 0; i--){
		int x = a[i+1]-a[i];
//		cout <<x  << "\n";
		if (!f){
			f = 1;
		} else {
			f = x>1;
		}
//		cout << " " << f << "\n";
		last = x;
	}
	cout << (f?"Alice":"Bob") << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

