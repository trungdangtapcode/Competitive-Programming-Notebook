#include<bits/stdc++.h>

using namespace std;
int f[2005][2005], n, b, a[2005];
const int p = 1e9+7;
int main(){
	freopen("GRAPH.INP","r",stdin);
	freopen("GRAPH.OUT","w",stdout);
	cin >> n >> b;
	for (int i = 0; i <= b; i++) f[0][i] = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		for (int j = 0; j <= b; j++){
			if (a[i]!=-1){
				if (a[i]&&a[i]+j<=b) (f[i][j] += f[i-1][j+1])%=p;
				if (a[i]==0) (f[i][j] += f[i-1][j])%=p;
			} else {
				(f[i][j] += f[i-1][j])%=p;
				(f[i][j] += 1ll*min(b-j,i-1)*f[i-1][j+1]%p)%=p; 
			}
		}
	}	
	cout << f[n][0] << "\n";
	
	return 0;
}
