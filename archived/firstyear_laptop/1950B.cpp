#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	for (int i = 0, r = 1; i < 2*n; i+= 2){
		for (int j  = 0, c = r; j < 2*n; j += 2){
			if (c) cout << "##";
			else cout << "..";
			c ^= 1;	
		}
		cout << "\n";
		for (int j  = 0, c = r; j < 2*n; j += 2){
			if (c) cout << "##";
			else cout << "..";
			c ^= 1;	
		}
		cout << "\n";
		r ^= 1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

