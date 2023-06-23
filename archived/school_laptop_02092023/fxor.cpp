#include<bits/stdc++.h>

using namespace std;
int n, a;
int to[5000005][2], cnt = 1; //10^5*32

void them(int x){
	stack<int> s;
	while (x) s.push(x%2), x/=2;
	while (s.size()<32) s.push(0);
	int u = 1;
	while (!s.empty()){
		int v = s.top(); s.pop();
		if (to[u][v]==-1) to[u][v] = ++cnt;
		u = to[u][v];
	}
}
int tim(int x){
	stack<int> s;
	while (x) s.push(x%2), x/=2;
	while (s.size()<32) s.push(0);
	int u = 1, res = 0;
	while (!s.empty()){
		int v = s.top(); s.pop();
//		cout << u << " tag " << (to[u][!v]!=-1?!v:v) << endl;
		if (to[u][!v]!=-1) u = to[u][!v], res = res*2 + !v;
		else u = to[u][v], res = res*2 + v;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	memset(name,-1,sizeof(name));
//	memset(to,-1,sizeof(to));
	for (int i = 0; i <= 5e6; i++) to[i][0] = to[i][1] = -1;
	cin >> n;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		them(a);
	}
	int q, x; cin >> q;
	while (q--){
		cin >> x;
		cout << tim(x) << " ";
	}
	
	
	
	
	return 0;
}
