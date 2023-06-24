#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

using namespace std;
int n, k, res, f[151][26*150+1], max2, max5;
main(){
	cin >> n >> k;
	for (int i = 0; i <= k; i++) for (int t5 = 0; t5 <= 26*k; t5++) f[i][t5] = -1e9;
	f[0][0] = 0;
	
	for (int i = 0; i < n; i++){
		long long int x;
		cin >> x;
		int cnt2 = 0, cnt5 = 0;
		while (x%2==0) x/=2, cnt2++;
		while (x%5==0) x/=5, cnt5++, max5++;
//		cout << cnt2 << "-" << cnt5 << " max " << max5 << endl;
		for (int j = i+1; j > 0; j--) for (int t5 = max5; t5 >= cnt5; t5--) f[j][t5] = max(f[j][t5],f[j-1][t5-cnt5]+cnt2);
//		for (int j = i+1; j > 0; j--){
//			for (int t5 = 0; t5 <= max5; t5++) cout << f[j][t5] << " ";
//			cout << endl;
//		}
	}
	int res = 0;
	for (int i = 1; i <= k; i++) for (int t5 = 0; t5 <= 26*k; t5++) res = max(res,min(t5,f[i][t5]));
	cout << res;
	
	return 0;
}
