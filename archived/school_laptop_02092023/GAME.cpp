#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

using namespace std;
int n, k, f, a, b, m;
long long x[10000005], d[10000005];
deque<int> q;
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k >> f >> a >> b >> m;
	x[1] = f;
	for (int i = 2; i <= n; i++) x[i] = (a*x[i-1]+b)%m;
	
	for (int i = 1; i <= k; i++){
		d[i] = x[i];
		while (q.size()&&x[q.back()]>=x[i]) q.pop_back();
		q.push_back(i);
	};
	
	for (int i = k+1; i <= n+1; i++){
		d[i] = d[q.front()] + x[i];
		while (q.size()&&d[q.back()]>=d[i]) q.pop_back();
		q.push_back(i);
		if (q.front()+k<=i) q.pop_front(); 
	}
//	for (int i = 1; i <= n; i++) cout << d[i] << " "; cout << endl;
	
//	for (int i = 1; i <= n; i++) cout << d[i] << " "; cout << endl;
	
	cout << d[n+1];
//	for (int i = 1; i <= n; i++){
//		d[i] = 1e9;
//		for (int j = i; i-j<=k; j--) if (j>=0) d[i] = min(d[i],d[j]+x[i]);
//		cout << d[i] << " ";
//	}
//	
	return 0;
}
