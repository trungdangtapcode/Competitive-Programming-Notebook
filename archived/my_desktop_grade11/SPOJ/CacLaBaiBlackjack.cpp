#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[10005];
bool f[20005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(f,false,sizeof(f));
	
	cin >> n >> m;
	for (int i =0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	for (int i = 0; i <n-1; i++) for (int j = i+1; j < n; j++) f[a[i]+a[j]] = true; //sort/bucket
	
	int j = 20000, res = 0;
	for (int i = 0; i < n-2; i++){
		while (!f[j]||a[i]+j>m) j--;
		if (j<0) break;
		//cout << " "<< j << endl;
		res = max(res, a[i]+j);
	}
	cout << res;
	
	return 0;
}

//	cin >> n;
//	for (int i =1; i <= n; i++) cin >> a[i];
//	sort(a+1,a+n+1);
//	for (int i = 1; i <=n-1; i++) for (int j = i+1; j <= n; j++) f[a[i]+a[j]] = true; //sort/bucket
//	
//	a[0] = a[1];
//	for (int i = 1; i <= n; i++){
//		j = j - a[i-1] + a[i]; //
//		if (m<a[i]) break;
//		while (!f[m-a[i]]||m) m--;
//	}
