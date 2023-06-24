#include <bits/stdc++.h>

using namespace std;
int n;
long long int res =0;
long long int a1[50], a2[50];
long long int x;
map<long long int, long long int> cnt1, cnt2;

void dequy1(int k, int n, long long int sum){
	if (k>n){
		//cout << sum << endl;
		cnt1[sum]++;
		return;
	} else {
		dequy1(k+1,n,sum);
		dequy1(k+1,n,sum+a1[k]);
	}
}
void dequy2(int k, int n, long long int sum){
	if (k>n){
		//cout << sum << endl;
		cnt2[sum]++;
		return;
	} else {
		dequy2(k+1,n,sum);
		dequy2(k+1,n,sum+a2[k]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> x;
	a1[0] = -1; a2[0] = -1;
	for (int i = 1; i <= n/2; i++) cin >> a1[i], a1[i] -= x;
	for (int i = n/2+1; i <= n; i++) cin >> a2[i-n/2], a2[i-n/2] -= x;
	dequy1(1,n/2,0);
	//cout << cnt1[0-x];
	//cout << a2[1] << " " << a2[2] << endl;
	dequy2(1,n-n/2,0);
	for (auto& it: cnt1){
		//cout << it.first << " " << it.second << endl;
		res += it.second*(cnt2[-it.first]);
	}
	cout << --res; //truong hop k = 0 no van dem khi sinh day nhi phan (000000000). Nhung k = 0 math error cmnr
	
	return 0;
}

//	a[0] = 0;
//	for (int i = 1; i <= n; i++) cin >> a[i], a[i] -= x;;//, a[i] += a[i-1];
//	
//	int res = 0;
//	for (int k = 1; k <= n; k++){
//		for (int i = 1; i <= n-k+1; i++){
//			if (a[i+k-1]-a[i-1]==x*k) res++;
//		}
//	}
//	cout << res;
