#include <bits/stdc++.h>

using namespace std;
long long int n, k, maxN = 1, maxK = 1e18, f[100];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	f[1] = 1; f[2] = 1;
	for (int i = 3; f[i-1] < maxK; i++) f[i] = f[i-1] + f[i-2], maxN++;
	
	int t;
	cin >> t;
	while (t--){
		cin >> n >> k;
		//cout << n << "+" << k << "=="; continue;
		if (n>maxN) {
			cout << "no" << endl;
			continue;
		}
		//cout << k << " " << f[n] << endl;
		if (k >= f[n]) cout << "yes" << endl; else cout << "no" << endl;
	}
	
	return 0;
}
