#include <bits/stdc++.h>

using namespace std;
int n, m, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while (t--){
		cin >> n >> m;
		vector <int> a(n), resA(n,0), b(m), resB(m,0);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		for (int i = 0; i < n; i++){
			for (int j = 0, mmax = 0; j < m; j++){
				int prev_resBj = resB[j]; //before update. prev/old/undo
				if (a[i]==b[j]) resA[i] = max(resA[i],mmax+1), resB[j] = max(resB[j],mmax+1);
				if (a[i]>=2*b[j]) mmax = max(mmax,prev_resBj);
			}
		}
		cout << *max_element(resA.begin(),resA.end()) << '\n'; //resB
	}
	
	return 0;
}


//				int prev_mmax = mmax; //before update at next line
//				if (a[i]>=2*b[j]) mmax = max(mmax,resB[j]);
//				if (a[i]==b[j]) resA[i] = max(resA[i],prev+1), resB[j] = max(resB[j],prev+1);
