#include<bits/stdc++.h>

using namespace std;
int n, a;
int to[5000005][2], cnt = 1, d[5000005]; 

void them(int x){
	stack<int> s;
	while (x) s.push(x%2), x/=2;
	while (s.size()<32) s.push(0);
	int u = 1;
	d[u]++;
	while (!s.empty()){
		int v = s.top(); s.pop();
		if (to[u][v]==-1) to[u][v] = ++cnt;
		u = to[u][v];
		d[u]++;
	}
}
int tim(int x){
	stack<int> s;
	while (x) s.push(x%2), x/=2;
	while (s.size()<32) s.push(0);
	int u = 1, res = 0;
	d[u]--;
	while (!s.empty()){
		int v = s.top(); s.pop();
		if (to[u][!v]!=-1&&d[to[u][!v]]>0) u = to[u][!v], res = res*2 + !v;
		else u = to[u][v], res = res*2 + v;
		d[u]--;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i <= n*32; i++) to[i][0] = to[i][1] = -1, d[i] = 0;
		cnt = 1;
		for (int i = 0, a; i < n; i++){
			cin >> a;
			them(a);
		}
		int pref = 0;
		for (int i = 0; i < n; i++){
			int tmp =  tim(pref);
			cout << tmp << " ";
			pref |= tmp;
		}
		cout << "\n";
	}
	
	
	
	
	return 0;
}
