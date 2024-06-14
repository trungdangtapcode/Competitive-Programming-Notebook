#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5;
int n, a[maxN], val[maxN], val2[maxN];
void rs(){
	for (int i = 1; i <= n; i++) val[i] = val2[i] = 0;
}
void add(int x){
	for (; x <= n; x += x&-x) val[x] |= 1;
}
int gett(int x){
	int res = 0;
	for (; x > 0; x -= x&-x) res |= val[x];
	return res;
} 
void add2(int x){
	for (; x <= n; x += x&-x) val2[x] |= 1;
}
int gett2(int x){
	int res = 0;
	for (; x > 0; x -= x&-x) res |= val2[x];
	return res;
} 

void solve(){
	cin >> n;
	rs();
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 0;
	for (int i = 1; i <= n; i++){
		int x = gett(a[i]-1)||!gett2(a[i]-1);
		res += x==0;
		if (x==0) add(a[i]);
		add2(a[i]);
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

