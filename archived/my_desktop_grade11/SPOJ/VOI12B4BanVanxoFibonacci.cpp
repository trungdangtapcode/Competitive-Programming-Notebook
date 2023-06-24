#include <bits/stdc++.h>

using namespace std;
int f[16] = { 1, 2, 3, 5, 1, 6, 0, 6, 6, 5, 4, 2, 6, 1, 0, 1};
int k;
long long int u, v;

int main(){
	
	cin >> k;
	for (int i = 0; i <k; i++){
		cin >> u >> v;
		long long int l = v - u + 1;
		if (l >= 32) {
			cout << l/16*16 << endl;
			continue;
		}
		int res = -1;
		for (int i = u; i < v-1; i++) if (f[i%16]==f[(i-1+16*16)%16]) res = 2; 
		cout << res << endl;
	}
		
	
	return 0;
}
