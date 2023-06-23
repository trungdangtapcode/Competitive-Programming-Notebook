#include<bits/stdc++.h>

using namespace std;
int a, b, c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> a >> b >> c;
		b = abs(b-c)+c;
		cout << (a==b?3:(a>b?2:1)) << "\n";
	}
	return 0;
}
