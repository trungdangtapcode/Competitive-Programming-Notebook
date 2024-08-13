#include<bits/stdc++.h>

using namespace std;
#define int long long
int n;
void solve(){
	cin >> n;
	int cnt =0;
	vector<pair<int,int>> res;
	string s = to_string(n);
	for (int b = 1; b <= 1e4; b++){
		for (int a = max(b/n+1,b/((int)log10(n)+1)+1); a <= 1e4; a++){
			int x = a*n-b;
			if ((int)log10(x)+1<((int)log10(n)+1)*a-b){
				break;
			}
//			cout << a << " " << b << " " << ((int)log10(n)+1)*a-b << "\n";
			int sum = 0;
			for (int p = 0; p < ((int)log10(n)+1)*a-b; p++){
				sum = 10*sum + s[p%s.length()]-'0';
			}
//			cout << a << " " << b << " " << x << " " << res << "\n";
//			continue;
			if (sum==x){
//				cout << a << " " << b << " " << "" << " " << res << "\n";	
//				cout << a << " " << b << "\n";
				res.push_back({a,b});
			}
		}
	}
	sort(res.begin(),res.end());
	cout << res.size() << "\n";
	for (auto it: res){
		cout << it.first << " " << it.second << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

