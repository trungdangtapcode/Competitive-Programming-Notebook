#include <bits/stdc++.h>

using namespace std;

int n;
long long int p = 1e9 + 3, base = 31;
string S, T, xuli;
long long int hashS[200005],hashT[100005], powBase[200005];
//int nxt[100000];

long long int getHashS(int i, int j){
	return (hashS[j]-hashS[i-1]*powBase[j-i+1]+p*p)%p;
}
long long int getHashT(int i, int j){
	return (hashT[j]-hashT[i-1]*powBase[j-i+1]+p*p)%p;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> S >> T;
	n = S.length();
	T = " " + T;
	S = " " + S + S.substr(0,n-1);
	
	hashS[0] = 0; powBase[0] = 1;
	for (int i = 1; i <= 2*n-1; i++){
		hashS[i] = (hashS[i-1]*base+S[i]-'a'+1)%p;
		powBase[i] = powBase[i-1]*base%p;
	}
	hashT[0] = 0;
	for (int i = 1; i <= n; i++){
		hashT[i] = (hashT[i-1]*base+T[i]-'a'+1)%p;
	}
	//cout << S << endl << T << endl;
	
	long long int ans = 0;
	for (int i = 1; i <= n; i++){
		int l = 1, h = n, m, res = 0;
		while (l <= h){
			m = (l+h)/2;
			//cout << l<<" "<<h << " " << m << endl;
			if (getHashT(1,m)==getHashS(i,i+m-1)){
				res = m;
				l = m+1;
			} else {
				h = m-1;
			}
		}
		//cout << i << " " << res  << "  - " << ans<< endl;
		if (res==n){
			ans += n;
		} else {
			//if (getHashT(m+2,n)==getHashS(i+m+1,i+n-1)) ans++;
			//cout << m+2<<"-" <<n<<"("<<  getHashT(m+2,n) << ") " << i+m+1 << "-" <<i+n-1<<"("<< getHashS(i+m+1,i+n-1) << ")" << endl;
			if (getHashT(res+2,n)==getHashS(i+res+1,i+n-1)) ans++;
		}
	}
	//if (ans==1) {cout << T; return 0;}
	cout << ans << endl;
	//cout << getHashS(4,n+3) << " " << getHashT(1,n);
	
	
	return 0;
}


//xuli =  T + "$" + S + S.substr(0,n-1); 
//	//cin >> xuli;
//	cout << xuli << endl;
//	nxt[0] = -1;
//	for (int i = 1; i < 3*n; i++){
//		int j = nxt[i-1];
//		while (j>=0&&xuli[j+1]!=xuli[i]) j = nxt[j];
//		if (xuli[j+1]==xuli[i]){
//			nxt[i] = j+1;
//		} else {
//			nxt[i] = -1;
//		}
//	}
//	for (int i = 0; i < 3*n; i++) cout << nxt[i] << "(" <<xuli[i] << ") ";
////	for (int i = n+1; i < 3*n; i++){
////		
////	}
