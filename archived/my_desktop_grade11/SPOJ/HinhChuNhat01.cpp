#include <bits/stdc++.h>

using namespace std;
int n, m, h[1005], prv[1005], nxt[1005], res;

int main(){
	
	h[0] = -1;
	cin >> n >> m;
	for (int i = 1, x; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> x;
			h[j] = (x?h[j]+1:0); 
		}
		for (int j = 1; j <= m; j++){
			int p = j-1;
			while (p>=1&&h[p]>=h[j]) p = prv[p];
			prv[j] = p; 
		}
		for (int j = m; j >= 1; j--){
			int p = j+1;
			while (p<=m&&h[p]>=h[j]) p = nxt[p];
			nxt[j] = p;
		}
		for (int j = 1; j <= m; j++) res = max(res,h[j]*(nxt[j]-prv[j]-1));
	}
	cout << res;
	return 0;
}
