#include <bits/stdc++.h>

using namespace std;
int n;
bool b;

int main(){
	
	cin >> n;
	b = true;
	for (int i = 2; i <= n; i++){
		while (n%i==0){
			n /= i;
			if (b){
				cout << i;
				b = false;
			} else {
				cout << "*"<< i;
			}
		}
	}
	
	return 0;
}
