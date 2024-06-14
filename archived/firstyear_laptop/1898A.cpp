#include<bits/stdc++.h>

using namespace std;
int k, n;
string s;
void solve(){
	cin >> n >> k >> s;
	for (int i =0; i < n; i++){
		if (s[i]=='B') k--;
	}
	if (k==0){
		cout << 0 << "\n";
		return;
	}
	cout << 1 << "\n";
	if (k>0){
		for (int i = 0; i < n; i++){
			if (s[i]=='A') k--;
			if (k==0){
				cout << i+1 << " B\n";
				return;
			}
		}
	} else {
		for (int i = 0; i < n; i++){
			if (s[i]=='B') k++;
			if (k==0){
				cout << i+1 << " A\n";
				return;
			}
		}
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
