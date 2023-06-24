#include<bits/stdc++.h>

using namespace std;

int n;
struct BIT{
	int val[1505];
	int gett(int i){
		if (i==0) return -1e9;
		int res = 0;
		for (; i > 0; i -= i&-i) res += val[i];
		return res;
	}
	void update(int i, int x){
		for (; i <= n; i += i&-i) val[i] += x;
	}
	void update(int l, int r, int x){
		assert(l<=r);
		update(l,x);
		update(r+1,-x);
	}
	BIT(){
		memset(val,0,sizeof(val));
	}
};
int a[1505][1505];
BIT b[1505];
long long res =0;
int main(){
//	n = 100;
//	b[0].update(1,1,-1e9);
//	cout << b[0].gett(1);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	b[0].update(1,n,-1e9);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			int tmp = -1e9;
			if (i>1) tmp = max(tmp,b[i-1].gett(j)+a[i][j]);
			if (j>1) tmp = max(tmp,b[i].gett(j-1)+a[i][j]);
			if (i==1&&j==1) tmp = a[i][j];
			b[i].update(j,j,tmp);
			res += b[i].gett(j);
		}
	}
	cout << res << "\n";
	for (int i = 1; i <= n; i++){
		int x, y;
		char c;
		cin >> c >> x >> y;
		a[x][y] += (c=='U'?1:-1);
		for (int i = x, l = y, r = y+1; i <= n; i++){
			while (l<=n&&b[i].gett(l)==max(b[i-1].gett(l),b[i].gett(l-1))+a[i][l]) l++; 
			if (l>=r) break;
			while (r<=n&&b[i].gett(r)!=max(b[i-1].gett(r),b[i].gett(r-1)+(c=='U'?1:-1))+a[i][r]) r++;
			b[i].update(l,r-1,(c=='U'?1:-1));
			res += (c=='U'?1:-1)*(r-l);
		}
		cout << res << "\n";
	}
	
	
	return 0;
}
