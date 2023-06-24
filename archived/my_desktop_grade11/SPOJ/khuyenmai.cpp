#include <bits/stdc++.h>
#define fix cout << "fixed "  << endl;

using namespace std;
int n, f[1001][1001], soPhieu = 0;
vector<int> a;
int main(){
	cin >> n;
	a.push_back(0);
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	//memset(f,1,sizeof(f));
	for (int i = 0; i <= n; i++) for (int j = 0; j <=n; j++) f[i][j] = 4e6;
	f[0][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= soPhieu; j++){
			f[i][j] = min(f[i-1][j+1],f[i-1][j]+a[i]);
			//cout << f[1][0] << endl;
			//cout << f[i][] << endl;
			//cout << i<<" "<< j<< " " <<a[2]<< endl;
			//cout << f[1][0]<<"("<<i-1<<","<<j+1<<<<") = "<<f[i-1][j+1] <<"("<<i-1<<","<<j+1<< ") vs " << f[i-1][j] <<"("<<i-1<<","<<j<< ") +a[i]->" <<f[i-1][j] + a[i] << endl;
		}
		if (a[i]>100) {
			soPhieu++;
			f[i][soPhieu] = f[i][soPhieu-1]; //at least, un-INF it
		}
	}
//	for (int i = 0; i <= n; i++){
//		for (int j = 0; j <= n; j++)
//			cout << f[i][j] << " ";
//		cout << endl;
//	}
	cout << f[n][0];
	return 0;
}
