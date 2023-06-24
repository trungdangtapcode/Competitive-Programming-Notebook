#include<bits/stdc++.h>

using namespace std;
long long int k;

int main(){
	int t; cin >> t;
	while (t--){
		cin >> k;
		k = 4*k-1;
		int res = -1;
		for (int i = 3; 1ll*i*i <= k; i += 2) if (k%i==0&&(k/i-1)%2==0){
			res = i;
		}
		if (res!=-1) cout << (res-1)/2 << " " << (k/res-1)/2 << "\n";
		else cout << "-1 -1\n"; 
	}
	
	return 0;
}
