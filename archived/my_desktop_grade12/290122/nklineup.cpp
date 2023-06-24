#include<bits/stdc++.h>

using namespace std;

int rmq1[50005][20], rmq2[50005][20], n, q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> rmq1[i][0];
		rmq2[i][0] = rmq1[i][0];
	}
	for (int i = 1; i < 20; i++){
		for (int j = 1; j+(1<<i)-1 <= n; j++){
			rmq1[j][i] = max(rmq1[j][i-1],rmq1[j+(1<<(i-1))][i-1]);
			rmq2[j][i] = min(rmq2[j][i-1],rmq2[j+(1<<(i-1))][i-1]);
		}
	}
	while (q--){
		int l, r, h;
		cin >> l >> r;
		h = __lg(r-l+1);
		cout << max(rmq1[l][h],rmq1[r-(1<<h)+1][h]) - min(rmq2[l][h],rmq2[r-(1<<h)+1][h]) << "\n";
	}
	
	
	return 0;
}
