#include<bits/stdc++.h>

using namespace std;
int n, a, b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> a >> b >> n;
		int res = 0;
		for (int i = 0; i < 30; i++){
			if (a&b&(1<<i)&&n%3!=2||a&~b&(1<<i)&&n%3!=1||~a&b&(1<<i)&&n%3!=0) res|= (1<<i);
		}
		cout << res << "\n";
	}	
	return 0;
}
