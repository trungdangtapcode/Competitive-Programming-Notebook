#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		if (n==1){
			cout << "-1\n";
			continue;
		}
		if (n==2){
			cout << "2 1\n";
			continue;
		}
		if (n==3){
			cout << "-1\n";
			continue;
		}
		for (int i = n/2+1; i <= n; i++) cout << i << " ";
		for (int i = 1; i <= n/2; i++) cout << i << " ";
		cout << "\n";
	}
	
	return 0;
}
