#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;
int n, d;//, cn;
//vector <int> a;
//check(int m){
//	for (int i = 0; i < n-1; i++){
//		int x = (a[i+1]-a[i]-1)/d;
//	}
//	return x;
//}

int main(){
	cin >> n >> d;
	int j = -1; int res = 0; bool x;
	for (int i = 0; i < n; i++){
		cin >> x;
		//cout << x;
		if (x){
			//cout << j << " " << i  << " -> " << (i-j-1)<< endl;
			res += (i-j-1)/d;
			j = i;
		}
//		if (x){
//			a.push_back(i);
//			cn++;
//		}
	}
	cout << res;
	
}
