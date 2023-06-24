#include<bits/stdc++.h>

using namespace std;
int a1, b1, a2, b2, a3, b3;
const int T = 2e6;
int main(){
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

	long long res = 0;
	if (a1==0){
		if (a3==0) res += (b2-a2+1);
		a1 = 1;
	}
	if (a2==0){
		if (a3==0) res += (b1-a1+1);
		a2 = 1;
	}
	
	if (b1-a1>b2-a2) swap(a1,a2), swap(b1,b2);
	for (int i = a1; i <= min(b1,T); i++){
		int x = (a3+i-1)/i, y = b3/i;
//		cout << x << " " << y << "\n";
		x = max(x,a2), y = min(y,b2);
		res += max(0,y-x+1);
	}
	for(int i = a2; i <= min(T,b2); i++){
		int x = (a3+i-1)/i, y = b3/i;
		x = max(x,max(a1,T+1)), y = min(y,b1);
		res += max(0,y-x+1);
	}
	
	cout << res;
	
	
	return 0;
}
