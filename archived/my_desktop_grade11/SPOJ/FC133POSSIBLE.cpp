#include <stdio.h>
int main(){
	int n, a;
	bool sum = false;
	scanf("%d", &n);
	while (n--) scanf("%d", &a), sum ^= (a&1);
	printf((sum?"NO":"YES"));
	return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//int n, a;
//bool sum = false; //true la le
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a, sum ^= (a&1);
//	cout << (sum?"NO":"YES");
//	
//	return 0;
//}
