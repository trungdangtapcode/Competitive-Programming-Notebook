#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;
int n, m;
string s;
int t[100005], tt[105];
int f[10005], r[10005], a[10005];

int main(){
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> r[i];
	cin >> s;
	s = "0" + s + "0";
	for (int k = 1; k <= 100; k++){
		int j = 0;
		t[0] = 0;
		for (int i = 1; i <= m+1; i++){
			while (s[j]=='1'||j+k<i) j++;
			//if (s[i]=='0') t[i] = t[j]+1; else t[i] = 100;
			t[i] = t[j] + 1;
			//cout << j << " " << i << endl;
		}
		tt[k] = t[m+1];
	}
	for (int i = 0; i < n; i++) a[i] = tt[r[i]];

	sort(a,a+n);
	//cout << " = " << tt[4] << endl;
	
	f[0] = a[0]; f[1] = a[1];
	f[2] = f[1] + a[0] + a[2]; //
	for (int i = 3; i < n; i++){
		f[i] = min(f[i-1]+a[0]+a[i],f[i-2]+a[0]+a[i]+a[1]+a[1]);
	}
	cout << f[n-1];
	
	
	return 0;
}
