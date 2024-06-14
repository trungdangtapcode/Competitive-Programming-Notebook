#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	int x = a[(n-1)/2];
	int res = n;
	for (int i = 0; i < n; i++){
		if (a[i]>x){
			res = i;
			break;
		}
	}; 
	cout << res-(n-1)/2 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

