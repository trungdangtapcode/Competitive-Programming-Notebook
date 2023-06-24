#include <bits/stdc++.h>

using namespace std;
int n;
long long int a[100005], f[100010];
int main(){
	memset(f,1,sizeof(f));
	
	ifstream fi("daykg.inp");
	ofstream fo("daykg.out");
	
	fi >> n;
	int res = 0;
	for (int i = 0; i < n; i++) fi >> a[i];
	f[0] = -1e15;
	for (int i = 0; i < n; i++) {
		int pos = upper_bound(f,f+n+5,a[i])-f;
		f[pos] = a[i];
		res = max(res,pos);
	}
	//for (int i = 0; i <= 10; i++) cout << f[i] << " ";
	fo << res;
	fi.close();
	fo.close();
	
	return 0;
}
