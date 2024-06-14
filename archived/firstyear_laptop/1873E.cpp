#include<bits/stdc++.h>

using namespace std;
//string s;
int n;
long long a[200005], x;
//int a[100005];
bool check(long long h){
	long long res = 0;
	for (int i = 1; i <= n; i++){
		res += max(0ll,h-a[i]);
	}
	return res<=x;
}
void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++){
		cin >> a[i];	
	}
	long long l = 0, h = 1e10+x, m, res = -1;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			l = m+1;
			res = m;
		} else h = m-1;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

