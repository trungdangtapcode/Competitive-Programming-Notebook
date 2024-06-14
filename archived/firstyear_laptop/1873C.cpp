#include<bits/stdc++.h>

using namespace std;
//string s;
//long long a[100005];
void solve(){
	int res = 0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			char c;
			cin >> c;
			if (c=='X'){
				res += 5-max(min(abs(i-4),abs(i-5)),min(abs(j-4),abs(j-5)));
			}
		}
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

