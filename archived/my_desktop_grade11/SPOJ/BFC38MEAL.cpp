#include <bits/stdc++.h>

using namespace std;
int val[4*100005], a[100005], n, k, t;
void update(int k, int l, int r, int x, int y){
	if (x>r||l>x) return; 
	if (l==r){
		val[k] += y;
		return;
	}
	int m = (l+r)/2;
	update(2*k,l,m,x,y);
	update(2*k+1,m+1,r,x,y);
	val[k] = max(val[2*k],val[2*k+1]);
}
int getT(){
	return val[1];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while (t--){
		memset(val,0,sizeof(val));
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i]; a[n] = -1;//danh cho truong hop j=n (x<l)
		int res = 1; //default
		update(1,1,1e5+1,a[0],1);
		for (int i = 0, j = 0; i < n; i++){
//			update(1,1,1e5+1,a[i],1);
			while (j<n&&j-i+1-getT()<=k) res = max(res,j-i+1), update(1,1,1e5+1,a[++j],1);
//			cout << i+1 << " " <<j+1 << "  " << getT() << "   " << j-i+1-getT() << endl;
			update(1,1,1e5+1,a[i],-1);
		}
		cout << res << '\n';
	}
	
	
	return 0;
}
