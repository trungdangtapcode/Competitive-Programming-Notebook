#include<bits/stdc++.h>

using namespace std;
int a, b, c;
void solve(){
	cin >> a >> b >> c;
	if (a<b&&b<c){
		cout << "STAIR\n";
		return;
	}
	if (a<b&&b>c){
		cout << "PEAK\n";
		return;
	}
	cout << "NONE\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

