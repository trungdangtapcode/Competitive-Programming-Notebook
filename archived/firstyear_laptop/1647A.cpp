#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	if (n%3==1){
		cout << 1;
		n--;
	}
	for (; n > 0;){
		cout << 2;
		n -= 2;
		if (n>0){
			cout << 1;
			n--;
		}
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

