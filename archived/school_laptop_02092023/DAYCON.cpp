#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, x, a[200005], t[200005], pref[200005], f[200005], g[200005];
main(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i+n] = a[i];
	}
	for (int i = 1; i <= 2*n; i++){
		t[i] = a[i] + t[i-1];
		pref[i] = t[i] + pref[i-1];
	}
	for (int i = 1, j = 0; i <= n; i++){
		while (t[j]-t[i-1]<=x&&j<=2*n) j++;
		j--;
		f[i] = j;
	}
	for (int i = 1, j = 1; i <= 2*n; i++){
		while (t[i]-t[j-1]>x&&j<=i) j++;
		g[i] = j;
	}
//	cout << "a[] = "; for (int i = 1; i <= 2*n; i++) cout << a[i] << " "; cout << endl;
//	cout << "t[] = "; for (int i = 1; i <= 2*n; i++) cout << t[i] << " "; cout << endl;
//	cout << "pref[] = "; for (int i = 1; i <= 2*n; i++) cout << pref[i] << " "; cout << endl;
	int sum = 0, cnt = 0;
	for (int i = 1, j = 0; i <= n; i++){
		while (j<i+n-1){
			j++;
			int tmp = max(g[j],i);
			sum += (j-tmp+1)*t[j] - (pref[j-1]-(tmp>1?pref[tmp-2]:0));//sumOf(tmp,j);
			cnt += (j-tmp+1);
//			cout << " + " << tmp << " " << j << " = " << (j-tmp+1)*t[j] - (pref[j] -pref[tmp-1]) << endl;
		}
//		cout << i << " " << j <<" => " << sum << endl;
//		break;
		cout <<sum << " " << cnt << "\n";
		int tmp = min(f[i],i+n-1);
		sum -= (pref[tmp]-pref[i-1]) - (tmp-i+1)*t[i-1];//sumOf(i,tmp);
		cnt -= tmp-i+1;
	}
	
	return 0;
}
