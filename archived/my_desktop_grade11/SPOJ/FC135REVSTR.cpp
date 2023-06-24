#include <bits/stdc++.h>

using namespace std;
string s, res;
int n, sweep[200005], m;
bool isReverse[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s >> m;
	n = s.length();
	res.resize(n);
	for (int i = 0, x; i < m; i++){
		cin >> x; x--;
		sweep[x]++; sweep[n-1-x+1]--;
	}
	for (int i = 1; i < n; i++) sweep[i] += sweep[i-1];
	for (int i = 0; i < n; i++) isReverse[i] = (sweep[i]%2==1);
	for (int i = 0; i < n; i++){
		if (isReverse[i]){
			res[i] = s[n-1-i];
		} else res[i] = s[i];
	}
	cout << res;
	
	return 0;
}
