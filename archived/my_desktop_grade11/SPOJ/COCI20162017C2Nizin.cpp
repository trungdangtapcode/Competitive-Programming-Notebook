#include <bits/stdc++.h>

using namespace std;
int n;
long long int a[1000005];
long long int sumL[1000005],sumR[1000005]; 
//sum[iL...jL] = sum[jR...iR] ==>> sum[jL...kL] = sum[kR...jR]. Find smalleset (iL-jL)(iR-jR)...//=> sum[1...n/2] = sum[n/2...n]
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	a[0] = 0; a[n+1] =0;
	sumL[0] = 0; sumL[n+1] = 0;
	sumR[0] = 0; sumR[n+1] = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sumL[i] = sumL[i-1] + a[i];
	}	
	for (int i = n; i >= 1; i--) sumR[i] = sumR[i+1] + a[i];
	
	int iL = 1, iR = n, res = 0, jL = 1, jR = n; 
	while (jL<jR){
		if (jL<jR&&sumL[jL]-sumL[iL-1]==sumR[jR]-sumR[iR+1]) {
			//if (iL!=jL||iR!=jR) cout << "founded " << iL << " " << jL <<" " << jR << " " << iR<< endl; else cout << "xem roi" << endl; 
			//if (iL!=jL||iR!=jR) res++;
			//res += abs(jL-iL)+abs(jR-iR);
			iL = ++jL; 
			iR = --jR;
			continue;
		}
		//cout <<  iL << " " << jL <<" " << jR << " " << iR << " - " << sumL[jL]-sumL[iL-1] << " " <<sumR[jR]-sumR[iR+1] << endl;
		if (jL<jR&&sumL[jL]-sumL[iL-1]<sumR[jR]-sumR[iR+1]) jL++;
		else if (jL<jR&&sumL[jL]-sumL[iL-1]>sumR[jR]-sumR[iR+1]) jR--;
//		if (jL<jR&&sumL[jL]-sumL[iL-1]==sumR[jR]-sumR[iR+1]) {
//			if (iL!=jL||iR!=jR) cout << "founded " << iL << " " << jL <<" " << jR << " " << iR<< endl; else cout << "xem roi" << endl; 
//			//if (iL!=jL||iR!=jR) res++;
//			//res += abs(jL-iL)+abs(jR-iR);
//			iL = ++jL; 
//			iR = --jR;
//			continue;
//		}
		res++;
	}
	//if (res==0) {
	//	if (sumL[jL]!=sumR[jR]) res = n-1;
	//}
	//if (binary_search(sumR+1,sumR+n+1,sumL[n]/2)&&sumL[n]%2==0) res = n-1;
	///!binary_search moi dung :))
	cout << res;
	
	return 0;
}
