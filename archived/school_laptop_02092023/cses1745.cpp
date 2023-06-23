#include<bits/stdc++.h>

using namespace std;
int n;
bool f[100005];
int main(){
	cin >> n;
	
	f[0] = true;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		for (int j = 1e5; j >= a; j--){
			f[j] |= f[j-a];
		}
	}
	
	int dem = 0; for (int i = 1; i <= 1e5; i++) if (f[i]) dem++; cout << dem << "\n";
	for (int i = 1; i <= 1e5; i++) if (f[i]) cout << i << " ";
	
	return 0;
}
