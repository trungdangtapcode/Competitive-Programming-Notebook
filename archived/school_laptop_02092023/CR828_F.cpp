#include<bits/stdc++.h>

using namespace std;
int p[200005], a[200005], n;

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			p[a[i]] = i;
		}
		long long int res = 0;
		for (int len = 1, l = p[0], r = p[0]; len <= n; len++){
			//len: doan dang xet phai <= mex*2
			//[l..r]: doan thoa man bat buoc bao gom du [0..mex-1]
			//=> nhung doan con lai co the duoc them vao ket qua
			int mex = (len+1)/2-1;
			l = min({l,p[mex],n+1-len});
			r = max({r,p[mex],len});
//			cout << len << ": " << l <<" " << r << endl; 
			res += max(0,len-(r-l+1)+1);
		}
		cout << res << "\n";
	}
	return 0;
}
