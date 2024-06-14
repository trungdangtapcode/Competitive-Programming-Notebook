#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, p[maxN], vec[maxN], sz;//, sza;
vector<int> ans[maxN];
typedef pair<int,int> ii;
ii f(int x, int y){
	int res = 1, cnt = 0;
	while (res*x<=y){
		cnt++;
		res *= x;
	}
	return {res,cnt};
}
int g(int x, int y){
	int cnt = 0;
	while (y%x==0) y /= x, cnt++;
	return cnt;
}
int main(){
	cin >> n;
	for (int i = 2; i <= n; i++) p[i] = 1;
	for (int i = 2; i*i <= n; i++) if (p[i]){
		for (int j = i*i; j <= n; j += i) p[j] = 0;
	}
	for (int i = 2; i <= n; i++) if (p[i]) vec[sz++] = i;
	int cnt = 0;
	for (int i = 0, j = sz-1; i <= j ; j--){
		int cur = vec[j];
		vector<int> tmp;
		while (i<j&&cur*vec[i]<=n) cur *= vec[i++], tmp.push_back(vec[i-1]);
		tmp.push_back(vec[j]);
		ans[tmp[0]] = tmp;
//		cout << cur << "..\n";
		cnt++;
	} 
	cout << cnt << endl;
	int res = 1;
//	for (int i = 2; i <= n; i++) if (p[i]){
//		int p;
//		for (p = 1; p*i <= n; p*= i);
//		cout << "? " << p << endl;
//		cin >> p;
//		res *= p;
//	}
	for (int i = 2; i <= n; i++) if (ans[i].size()){
//		cout << res << "ss\n";
		if (p[i]&&res*i>n) break;
		int prod = 1, gcd;
		for (int x: ans[i]) prod *= x;
		cout << "? " << prod << endl;
		cin >> gcd;
		for (int x: ans[i]){
			auto it = f(x,n/res);
			int y2 = it.second, y1 = g(x,gcd);
			if (y1==0) continue;
//			cout << y1 << ".." << y2 << "\n";
			if (y2==1){
				for (int i = 0; i < y1; i++) res *= x;
				continue;
			}
			cout << "? "<< it.first << endl;
			int tmp;
			cin >> tmp;
			res *= tmp;
		}
	}
	cout << "! "<< res << endl;
	
	return 0;
}
