#include<bits/stdc++.h>

using namespace std;
long long n;
void solve(){
	cin >> n;
	n -= 1;
	if (n==0){
		cout << 0 << "\n";
		return;
	}
	vector<int> v;
	while (n>0){
		v.push_back(n%5);
		n /= 5;
	}
	reverse(v.begin(),v.end());
	for (int x: v){
		cout << 2*x;
	}
}

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

