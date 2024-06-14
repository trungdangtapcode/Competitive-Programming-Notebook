#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], p[maxN];
int main(){
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i]++;
		p[a[i]] = i;
		res += a[i]==i;
//		cout << a[i] << " ";
	}
//	cout << "\n";
	int cur = 0;
	for (int i = 1; i <= n; i++){
		int x = p[i];
//		cout <<i << " " << x << "\n";
		if (x==i) continue;
		if (a[x]!=x) cur = max(cur,1);
		if (a[i]==x) cur = max(cur,2);
//		cout << cur<<"\n";
	}
	cout << res + cur;
	
	return 0;
}
