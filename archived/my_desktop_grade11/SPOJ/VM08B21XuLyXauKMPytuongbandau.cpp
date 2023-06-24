#include <bits/stdc++.h>

using namespace std;

int n;
string S, T, xuli;
int nxt[400005], prv[400005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> S >> T;
	n = S.length();
	
	xuli =  T + "$" + S + S.substr(0,n-1) + "^" + T; 
	//cin >> xuli;
	//cout << xuli << endl;
	nxt[0] = -1;
	for (int i = 1; i < 3*n; i++){
		int j = nxt[i-1];
		while (j>=0&&xuli[j+1]!=xuli[i]) j = nxt[j];
		if (xuli[j+1]==xuli[i]){
			nxt[i] = j+1;
		} else {
			nxt[i] = -1;
		}
	}
	prv[4*n] = 4*n+1;
	for (int i = 4*n-1; i > n; i--){
		int j = prv[i+1];
		while (j<=4*n&&xuli[j-1]!=xuli[i]) j = prv[j];
		if (xuli[j-1]==xuli[i]){
			prv[i] = j-1;
		} else {
			prv[i] = 4*n+1;
		}
	}
	for (int i = 4*n; i > n; i--) prv[i] = 4*n-prv[i] ;//n-(prv[i]-3*n) //n-1-(prv[i]-3*n-1);
	for (int i = 0; i <= 4*n; i++) nxt[i]++, prv[i]++; //doi vi tri tro thanh dem
	//for (int i = 0; i <= 4*n; i++) cout << nxt[i]<<"-"<<prv[i] << "(" <<xuli[i] << ") "; cout << endl;
	int res = 0;
	for (int i = n+1; i < 3*n; i++){
		//cout << nxt[i-1]+prv[i+1] << " " << n-2<< endl;
		if (nxt[i] == n) {res += n; continue;}
		if (nxt[i]+prv[i]==n+1); else if (nxt[i-1] == n-1||prv[i+1] == n-1) {res++; continue;}
		if (nxt[i]+prv[i]==n+1); else if (nxt[i-1]+prv[i+1]==n-1) res++;// cout << xuli[i] << endl;;
	}
	cout << res;
	
	
	return 0;
}



