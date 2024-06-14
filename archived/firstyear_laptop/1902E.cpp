#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e6+5;
int to[maxN][26], ntrie = 1, suml[maxN], sumc[maxN];
int n;
string s[maxN];

void add(string &x){
	int u = 1;
//	suml[u] += x.length();
	sumc[u]++;
	for (char& c: x){
		if (!to[u][c-'a']) to[u][c-'a'] = ++ntrie;
		u = to[u][c-'a'];
//		suml[u] += x.length();
		sumc[u]++;
	}
}
int query(string &x){
	int u = 1;
	int res = 0;
	for (char& c: x){
		if (!to[u][c-'a']) return res;
		u = to[u][c-'a'];
		res += sumc[u];
	}
	return res;
}


main(){
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		add(s[i]);
		sum += s[i].length();
	}
	int res = 0;
	for (int i = 1; i <= n; i++){
		reverse(s[i].begin(),s[i].end());
		res += s[i].length()*n + sum - 2*query(s[i]);
	}
	cout << res << "\n";
}
