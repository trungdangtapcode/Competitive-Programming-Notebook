#include <bits/stdc++.h>

using namespace std;
const long long int p1 = (1<<31)-1, p2 = (1<<17)-1; // p2 = (1<<13)-1 van ok
long long int a[100005], ans[100005];
int n;

long long int AmuB(long long int x, long long int y){
	long long int res = 1;
	while (y>0){
		if (y%2==1) res = (res*x)%p1;
		x = (x*x)%p1;
		y /= 2;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = (a[i]*AmuB(p2,a[i]))%p1;
		if (i>0) a[i] = (a[i]+a[i-1])%p1;
	}	
	ans[0] = 0;
	for (long long int baseP2 = 1, i = 1; i <= n; i++){
		baseP2 = (baseP2*p2)%p1;
		ans[i] = (ans[i-1]+i*i*baseP2%p1)%p1;
	}
	long long int res = 0;
	for (int i = 1; i*i <= 10*n; i++){ //vua khoc vua cuoi an muoi cuc cut
		for (int j1 = 0, j2 = i*(i+1)/2-1; j2 < n; j1++, j2++){
			long long int low = (j1>0?a[j1-1]:0);
			long long int high = a[j2];
			if ((high-low+p1*p1)%p1==ans[i]) res++;
		}
	}
	cout << res << '\n';

	
//	for (int i = 0; i < n; i++) cout << (i>0?a[i]-a[i-1]:a[i]) << " "; cout << endl;
//	for (int i = 0; i < n; i++) cout << (i>0?ans[i]-ans[i-1]:ans[i]) << " "; cout << endl;
	
	return 0;
}
