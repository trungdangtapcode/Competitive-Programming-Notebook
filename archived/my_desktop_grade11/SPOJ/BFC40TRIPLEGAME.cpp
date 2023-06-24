#include <bits/stdc++.h>

using namespace std;
int s, cnt, res = 1;
const int p = 1e9 + 7;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> s;
	int cnt = __builtin_popcount(s);
	for (int i = 0; i < cnt; i++) res = (3ll*res)%p;
	cout << res;
	return 0;
}
