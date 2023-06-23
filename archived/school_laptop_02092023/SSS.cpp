#include<bits/stdc++.h>

using namespace std;
int n, s;
int main(){
	cin >> n >> s;
	bitset<100001> mask;
	mask[0] = 1;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		mask = mask|(mask<<a);
	}
	int res = 0;
	for (int i = 0; i <= s; i++) res += mask[i];
	cout << res;
	
	return 0;
}
