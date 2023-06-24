#include <bits/stdc++.h>

using namespace std;
int a[20][100005];
int n, res;

bool checkSpt(int x, int y){
	int lg = log2(y-x+1);
	int tmp = min(a[lg][x],a[lg][y-(1<<lg)+1])+x-1;
	return (tmp>=0);
}

int main(){
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[0][i];
		a[0][i] -= i;
	}
	for (int i = 1; i <= log2(n); i++){
		for (int j = 0; j + (1<<i) < n; j++){
			a[i][j] = min(a[i-1][j],a[i-1][j+(1<<(i-1))]);
		}
	}
	for (int i = 0, j = 0; i < n; i++){
		while (j<=i&&!checkSpt(j,i)) j++;
//		cout << j << " " << i << endl;
		res = max(res,i-j+1);
	}
	cout << res;
	
	
	return 0;
}
