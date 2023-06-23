#include<bits/stdc++.h>

using namespace std;
int n;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		vector<int> v(n);
		for (int i = 0; i < n; i++) v[i] = s[i]-'0';
		int res = 0;
		for (int i = 1, cur = 0; i < n; i++){
			v[i]^=cur;
			if (v[i]<v[i-1]){
				cur^= 1;
				res++;
				v[i]^= 1;
			}
		}
		cout << res << "\n";
	}
	return 0;
}
