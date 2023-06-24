#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, chan = 0, le = 0; long long int a, res;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		if (a%2==0) res += chan, chan++; else res += le, le++;
	}
	cout << res;
	
	return 0;
}
