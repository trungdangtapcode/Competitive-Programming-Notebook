#include<bits/stdc++.h>

using namespace std;
#define ll long long
void solve(){
	ll x;
	cin >> x;
	string s;
	for (ll i = 2; i*i <= x; i++) if (x%i==0){
		s.push_back((char)('A'+i%26));
		while (x%i==0) x /= i;
	}
	if (x>1) s.push_back((char)('A'+x%26));
	sort(s.begin(),s.end());
	cout << s << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
//	int t; cin >> t;
//	while (t--)
	solve();
}

