#include <bits/stdc++.h>

using namespace std;
int n;
long long int res, cnt1, cnt2, cnt3;
int main(){
	cin >> n;
	for (int i = 1; i*i*i <= n; i++){
		for (int j = i; j <= n; j++){
			int k = n/(i*j);
			if (k<j) break;
			res += k-j+1;
			if (i==j) cnt1 += k-j+1;
			cnt2 ++;
			if (i==j) cnt3++;
		}
	}
	cout << res*6-cnt1*3-cnt2*3+cnt3;
	
	return 0;
}
