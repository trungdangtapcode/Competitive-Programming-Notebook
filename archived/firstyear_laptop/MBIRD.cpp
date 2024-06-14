#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 1e6+5;
int n, a[maxN];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	long long res = 0;
	stack<int> s;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		res += a[i];
		while (s.size()&&s.top()>=a[i]) s.pop();
		if (s.size()) res += s.top(); 
		s.push(a[i]);
	}
	while (s.size()) s.pop();
	for (int i = n; i >= 1; i--){
		while (s.size()&&s.top()>a[i]) s.pop();
		if (s.size()) res += s.top();
		s.push(a[i]);
	}
	cout << res;
	
	return 0;
}

/*
	for (int i = 1; i <= n; i++){
		int u = -b[i].second;
		res += a[prv[u]];
		res += a[nxt[u]];
		res += a[u];
		nxt[prv[u]] = nxt[u];
		prv[nxt[u]] = prv[u];
	}
	cout << res*0+25;
*/
