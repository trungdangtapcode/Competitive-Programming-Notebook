#include<bits/stdc++.h>

using namespace std;
int n, k;
void solve(){
	cin >> n >> k;
	vector<int> res;
	int h = 1<<(int)__lg(k);
	int base = 1, sum = 0;;
	while (base<h){
		sum += base;
		res.push_back(base);
		base *= 2;
	}
	base /= 2;
	if (k-1-sum>0) res.push_back(k-1-sum);
	res.push_back(k+1);
	res.push_back(2*k+1);
	int cur = 2*k+1;
	base = 2;
	while (cur<n){
		res.push_back(base*(k+1));
		cur = base*(k+1)+k;
		base *= 2;
	}
	cout << res.size() << "\n";
	for (int x: res) cout << x << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

