#include<bits/stdc++.h>

using namespace std;
const int mn = 302;
bool f[mn][mn][mn], pref[mn][mn][mn], pref2[mn][mn][mn][3];
int n, a[4];
const string s[] = {"BitLGM","BitAryo"};
main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = 0; i <= a[1]; i++){
//		for (int j = 0; j <= a[2]; j++){
//			for (int k = 0; k <= a[3]; k++){
//				f[i][j][0] = f[i][0][k] = f[0][j][k] = 1;		
//			}
//		}
//	}
	if (n==3){
		f[0][0][0] = pref[0][0][0] = pref2[0][0][0][0] = pref2[0][0][0][1] = pref2[0][0][0][2]= 1;
		for (int i = 0; i <= a[1]; i++){
			for (int j = 0; j <= a[2]; j++){
				for (int k = 0; k <= a[3]; k++){
					if (i==0&&j==0&&k==0) continue;
	//				f[i][j][k] = !(pref2[i-1][j][k][0]||pref2[i][j-1][k][1]||pref2[i][j][k-1][2]);
					bool tmp = 0;
					if (i) tmp |= pref2[i-1][j][k][0];
					if (j) tmp |= pref2[i][j-1][k][1];
					if (k) tmp |= pref2[i][j][k-1][2];
					if (i&&j&&k) tmp |= pref[i-1][j-1][k-1];
	//				if (i&&j&&k) tmp |= pref[];
					f[i][j][k] = !tmp;
					pref[i][j][k] = f[i][j][k];
					if (i&&j&&k) pref[i][j][k] |= pref[i-1][j-1][k-1];
					pref2[i][j][k][0] = pref2[i][j][k][1] = pref2[i][j][k][2] = f[i][j][k];
					if (i) pref2[i][j][k][0] = pref2[i-1][j][k][0]||f[i][j][k];
					if (j) pref2[i][j][k][1] = pref2[i][j-1][k][1]||f[i][j][k];
					if (k) pref2[i][j][k][2] = pref2[i][j][k-1][2]||f[i][j][k];
				}
			}
		}
		cout << s[f[a[1]][a[2]][a[3]]];
	} else if (n==2){
		f[0][0][0] = pref[0][0][0] = pref2[0][0][0][0] = pref2[0][0][0][1] = pref2[0][0][0][2]= 1;
		for (int i = 0; i <= a[1]; i++){
			for (int j = 0; j <= a[2]; j++){
				if (i==0&&j==0) continue;
//				f[i][j][k] = !(pref2[i-1][j][k][0]||pref2[i][j-1][k][1]||pref2[i][j][k-1][2]);
				bool tmp = 0;
				if (i) tmp |= pref2[i-1][j][0][0];
				if (j) tmp |= pref2[i][j-1][0][1];
				if (i&&j) tmp |= pref[i-1][j-1][0];
//				if (i&&j&&k) tmp |= pref[];
				f[i][j][0] = !tmp;
				pref[i][j][0] = f[i][j][0];
				if (i&&j) pref[i][j][0] |= pref[i-1][j-1][0];
				pref2[i][j][0][0] = pref2[i][j][0][1]  = f[i][j][0];
				if (i) pref2[i][j][0][0] = pref2[i-1][j][0][0]||f[i][j][0];
				if (j) pref2[i][j][0][1] = pref2[i][j-1][0][1]||f[i][j][0];
			}
		}
		cout << s[f[a[1]][a[2]][0]];// << " " << pref[0][1][0];
	} else {
		cout << s[(a[1]==0)];
	}
	
	


	return 0;
}
