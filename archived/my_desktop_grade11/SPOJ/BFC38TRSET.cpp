#include <bits/stdc++.h>

using namespace std;
int n, u, v, l , r, res, resL;
int main(){
	
	cin >> n >> u >> v;
	
	res = 1; resL = l = r = u; //[u
	while (r<v){
		r = min(v,n/(n/l));//v]
		if (r-l+1>res){
			res = r-l+1;
			resL = l;
		};
		l = r+1;
	}
	cout << resL << " " << resL+res-1;
	
	return 0;
}
