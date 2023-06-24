#include <bits/stdc++.h>

using namespace std;
int n, res, cnt1, cnt2;
long long int c, cnt; 
string t;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> c >> t;
	for (int i = 0, j = 0; i < n; i++){
		if (t[i]=='a') cnt1++;
		if (t[i]=='b') cnt2++, cnt += cnt1;
		while (cnt>c){
			if (t[j]=='a') cnt1--, cnt -= cnt2;
			if (t[j]=='b') cnt2--;
			j++;
		}
		res = max(res,i-j+1);
	}
	cout << res;
	
	return 0;
}


//	t = t + " ";
//	for (int i = 0, j = 0; i < n; i++){
//		if (i>0) if (s[i-1]=='a') cnt1--;
//		if (i>0) if (s[i-1]=='b') cnt2--;
//		while (j<=n&&cnt1*cnt2<=c) {
//			j++;
//			if (s[j]=='a') cnt1++;
//			if (s[j]=='b') cnt2++;
//			res = max(res,j-i+1);
//		}
//	}
