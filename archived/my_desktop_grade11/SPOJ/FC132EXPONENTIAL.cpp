#include <bits/stdc++.h>
using namespace std;
int x;
bool a[3000000] = {false};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> x;
	a[1] = true;
	for (long long int i = 2; i <= x; i++){
		//cout << i << endl;
		for (long long int p = i*i; p <= x; p*=i){
			//cout << i << " "<< p << endl;
			a[p] = true;
		}
	}
	//for (int i = 0; i <= x; i++) cout << i << " " << a[i] << endl;
	for (int i = x; i >= 1; i--){
		if (a[i]){
			cout << i;
			return 0;
		}
	}
	
	return 0;
}
