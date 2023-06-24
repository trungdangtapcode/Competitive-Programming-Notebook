#include<bits/stdc++.h>

using namespace std;
int n, cnt1, cnt2;

int main(){
	cin >> n;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		if (a>0) cnt1++;
		if (a<0) cnt2++;
		if (a==0){
			cout << -1;
			return 0;
		}
	}
	cout << min(cnt1,cnt2);
	return 0;
}
