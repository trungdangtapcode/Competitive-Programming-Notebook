#include<bits/stdc++.h>

using namespace std;
int n, r, x1, x2;
int main(){
	cin >> n >> r >> x1 >> x2;
	while (n--){
		int p; cin >> p;
		if (p+r<=x1&&x1<x2||p-r>=x1&&x1>x2){
			cout << "GOAL";
			return 0;
		}
	}
	cout << "NO GOAL";
	
	return 0;
}
