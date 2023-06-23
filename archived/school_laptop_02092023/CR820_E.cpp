#include<bits/stdc++.h>

using namespace std;
#define int long long
int x, y;
main(){
	
	for (int i = 2;; i++){
		cout << "? " << 1 << " " << i << endl;
		cin >> x;
		if (x==-1) return cout << "! " << i-1, 0;
		cout << "? " << i << " " << 1 << endl;
		cin >> y;
		if (x!=y) return cout << "! " << x+y, 0;
	}
	
	return 0;
}
