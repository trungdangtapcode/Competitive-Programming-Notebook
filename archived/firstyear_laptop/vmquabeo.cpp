#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;
int n, l, d, a[maxN];
multiset<int> ms;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long res = 0;
	cin >> n >> l >> d;
	for (int i = 1, j = 1; i <= n; i++){
		cin >> a[i];
		ms.insert(a[i]);
		while (*ms.rbegin()-*ms.begin()>d) ms.erase(ms.find(a[j++]));
		int jj = i-l;
		res += max(0,jj-j+1);
	}
	cout << res;
	
	return 0;
}
