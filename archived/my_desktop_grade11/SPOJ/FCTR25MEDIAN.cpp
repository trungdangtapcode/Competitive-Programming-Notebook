#include <bits/stdc++.h>

using namespace std;
int val[400005], d[100005], f[100005];
int n, a[100005], b[100005];

void reset(){
	memset(val,0,sizeof(val));
}
void update(int x, int y){
	while (x<=4e5){
		val[x] += y;
		x += (x&-x);
	}
}
int getSum(int x){
	int res = 0;
	while (x>0){
		res += val[x];
		x -= (x&-x);
	}
	return res;
}

long long int check(int x){
	d[0] = (x>=a[0]);
	for (int i = 1; i < n; i++) d[i] = d[i-1] + (x>=a[i]);
	for (int i = 0; i < n; i++) f[i] = 2*d[i] - i;
	
	reset();
	update(+1+n,+1);
	long long int res = 0;
	for (int i = 0; i < n; i++){
		res += getSum(f[i]-1+n);
//		cout << " f[i] = " << f[i] << "   " << getSum(f[i]-1+n) << endl;
		update(f[i]+n,+1);
	}
	return res;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
	sort(b,b+n);
	int l = 0, h = n-1, m, res = -1;
	long long int checked, need = (1ll*n*(n+1)/2+1)/2;;
	while (l<=h){
		m = (l+h)/2;
		checked = check(b[m]);
//		if (checked==need) break;
		if (checked>=need){
			res = m;
			h = m - 1;
		} else l = m + 1;
	}
	cout << b[res];
}


//#include <bits/stdc++.h>
//
//using namespace std;
//int n, a[100005];
//long long int check(int x){
//	long long int res = 0;
//	for (int i = 0, j = 0; i < n; i++){
//		while (a[(i+j+1)/2]<=x&&j<=i) j++;
//		cout << i << " " << j << endl;
//		res += j;
//	}
//	return res;
//}
//
//int main(){
//	
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	a[n] = 1e9+5;
//	sort(a,a+n);
//	
//	int need = (n*(n+1)/2+1)/2;
//	int l = 0, h = n-1, m, res = -1;
//	long long int checked;
////	while (l<=h){
////		m = (l+h)/2;
////		checked = check(a[m]);
////		if (checked==need) break;
////		if (checked>need){
////			h = m - 1;
////		} else l = m + 1;
////	}
//	cout << check(a[2]);
////	cout << check(a[6]);
//	
//	return 0;
//}
