#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;	
	if (n%4==0){
		cout << "YES\n";
		cout << n/2 << "\n";
		for (int i = 1; i <= n; i++) if (i%4==2||i%4==3) cout << i << " "; cout << "\n";
		cout << n/2 << "\n";
		for (int i = 1; i <= n; i++) if (i%4==1||i%4==0) cout << i << " "; cout << "\n";
	} else if (n%4==3){
		cout << "YES\n";
		cout << n/2+1 << "\n";
		for (int i = 1; i <= n; i++) if (i%4==1||i%4==2) cout << i << " "; cout << "\n";
		cout << n/2 << "\n";
		for (int i = 1; i <= n; i++) if (i%4==3||i%4==0) cout << i << " "; cout << "\n";
	} else cout << "NO\n";
	
	return 0;
}
