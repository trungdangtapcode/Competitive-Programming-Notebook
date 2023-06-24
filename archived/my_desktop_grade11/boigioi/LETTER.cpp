#include <bits/stdc++.h>

using namespace std;
long long int a[15][15];
int n, k;
bool choosed[15], res[15];
long long int mmin = 1e10;

long long int f(){
	long long int mmin = 1e10;
	for (int i = 0; i < n; i++) if (!choosed[i]){
		for (int j = 0; j < n; j++) if (choosed[j]){
			mmin = min(mmin,a[i][j]);
		}
	}
	return mmin;
}

void dequy(int x, int pos){
	//if (pos>=n) return;
	if (x>k){
		if (f() < mmin){
			mmin = f();
			for (int i = 0; i < n; i++) res[i] = choosed[i];
		}
		//for (int i = 0; i < n; i++) if (choosed[i]) cout << i << " - "; cout << f() << endl;
		return;
	}
	//if (n-1-pos<k-x) return;
	for (int i = pos; i < n; i++){
		choosed[i] = true;
		dequy(x+1,i+1);
		choosed[i] = false;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 0 ; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	dequy(1,0);
	cout << mmin << '\n';
	for (int i = 0; i < n; i++) if (res[i]) cout << i+1 << ' ';
	
	return 0;
}
