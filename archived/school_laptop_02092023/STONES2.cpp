#include<bits/stdc++.h>

using namespace std;
int p[1000005], n, m;
int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> m; 
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		if (p[i]==-1) p[i] = p[i-1] + m;
		if (p[i]-p[i-1]<m){
			cout << -1;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) cout << p[i] - p[i-1] << " ";
	
	return 0;
}
