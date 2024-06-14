#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, d, a[maxN];
int f(int x){
	return (x-1)/2;
}

void solve(){
	cin >> n >> d;
	multiset<int> ms;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		ms.insert(a[i]-a[i-1]-1);
	}
	int lastd = d-a[n];
	ms.erase(ms.find(a[n]-a[n-1]-1));
	int res = min(*ms.begin(), d-a[n-1]-1);
	ms.insert(a[n]-a[n-1]-1);
	for (int i = 1; i < n; i++){
		ms.erase(ms.find(a[i]-a[i-1]-1));
		ms.erase(ms.find(a[i+1]-a[i]-1));
		ms.insert(a[i+1]-a[i-1]-1);
		
		int x = -1;
		if (ms.size()==1){
			x = min(*ms.begin(),max(lastd-1,f(*ms.begin())));
		} else {
			x = min(*ms.begin(),max(f(*ms.rbegin()),lastd-1));
		}
//		cout << i << ": " << x << "\n";
		res = max(res,x);
		
		ms.insert(a[i]-a[i-1]-1);
		ms.insert(a[i+1]-a[i]-1);
		ms.erase(ms.find(a[i+1]-a[i-1]-1));
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

