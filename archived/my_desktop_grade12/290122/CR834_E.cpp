#include<bits/stdc++.h>

using namespace std;
int n, h, a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> h;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1,a+n+1);
		vector<int> v = {2,2,3};
		int res = 0;
		do {
			long long int cur = h;
			int ans = 0;
			for (int i = 1, j = 0; i <= n; i++){
				while (cur<=a[i]&&j<3) cur *= v[j++];
				if (cur<=a[i]) break;
				cur += a[i]/2;
				ans++;
			}
			res = max(res,ans);
		} while (next_permutation(v.begin(),v.end()));
		cout << res << "\n";
	}
	
	return 0;
}

/* lon de
#include<bits/stdc++.h>

using namespace std;
int f[200005][3][2];
int n, h, a[200005];
int main(){
//	int t; cin >> t;
	int t = 1;
	while (t--){
		cin >> n >> h;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1,a+n+1);
		for (int i = 0; i <= n; i++) for (int g = 0; g <= 2; g++) for (int b = 0; b <= 1; b++) f[i][g][b] = 0;
		f[0][0][0] = h;	//2*h, 3*h
		for (int i = 1; i <= n; i++){
			for (int g = 0; g <= 2; g++) for (int b = 0; b <= 1; b++){
				f[i][g][b] = f[i-1][g][b];
				if (g) f[i][g][b] = max(f[i][g][b],f[i-1][g-1][b]*2);
				if (b) f[i][g][b] = max(f[i][g][b],f[i-1][g][b-1]*3);
				if (g&&b) f[i][g][b] = max(f[i][g][b],f[i-1][g-1][b-1]*6);
				if (f[i][g][b]>a[i]) f[i][g][b] += f[i][g][b]/2;
			}
			cout << f[i][2][0] << "\n";
		}
		cout << f[n][2][1];
	}
	
	return 0;
}
*/


