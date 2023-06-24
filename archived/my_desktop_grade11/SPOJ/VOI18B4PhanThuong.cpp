#include <bits/stdc++.h>

using namespace std;
struct rect{
	int x1, x2, y1, y2;
	rect(int a, int b, int c, int d){
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
};

int n, k, q, r;
long long int S[505][505];

long long int getS(rect a){
	if (a.x1>a.x2||a.y1>a.y2) return 0;
	return (S[a.x2][a.y2]-S[a.x1-1][a.y2]-S[a.x2][a.y1-1]+S[a.x1-1][a.y1-1]);
}
rect giao(rect a, rect b){
	rect res = rect(1,1,n,n);
	res.x2 = min(a.x2,b.x2);
	res.x1 = max(a.x1,b.x1);
	res.y2 = min(a.y2,b.y2);
	res.y1 = max(a.y1,b.y1);
	return res;
}

long long int solve(){
	vector<rect> a;
	for (int i = 0, x, y; i < q; i++){
		cin >> x >> y;
		rect tmp = rect((int)x,(int)y,x+r-1,y+r-1);
		a.push_back(tmp);
	}
//	for (auto it: a) cout << it.x1 << " " << it.y1 << " " << it.x2 << " " << it.y2 << endl;
	long long int sum = 0;
	for (int i = 1; i < (1<<q); i++){ //bitmask bat dau tu 1 vi ko the co tap giao 0 phan tu
		int sign = (__builtin_popcount(i)%2==0?-1:1);
		rect phanGiao = rect(1,1,n,n);
		for (int j = 0; j < q; j++) if (i&(1<<j)){
			phanGiao = giao(phanGiao,a[j]);
		}
//		cout << bitset<5>(i) << " " << phanGiao.x1 << " " << phanGiao.y1 << " " << phanGiao.x2 << " " << phanGiao.y2 << endl;
		sum += sign*getS(phanGiao);
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> k >> r >> q;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> S[i][j], S[i][j] += S[i-1][j]+S[i][j-1]-S[i-1][j-1];
//	for (int i = 1; i <= k; i++){
//		solve();
//	}

	long long int res = 0;
	for (int i = 0; i < k; i++)
		res = max(res,solve());
	cout << res;
	
	return 0;
}
