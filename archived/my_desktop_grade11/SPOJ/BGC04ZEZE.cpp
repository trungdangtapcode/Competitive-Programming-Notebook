#include <bits/stdc++.h>

using namespace std;
int m,n, cnt2 = 0, cnt5 = 0; 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	while (n--){
		cin >> m; //m khac 0
		while (m%2==0) m /= 2, cnt2++;
		while (m%5==0) m /= 5, cnt5++;
	}
	cout << min(cnt2,cnt5);
	return 0;
}
