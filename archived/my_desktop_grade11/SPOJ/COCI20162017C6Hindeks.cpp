#include <bits/stdc++.h>
#define fix cout <<"fixed" << endl;

using namespace std;
int n;
vector<int> a;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int result = 0;
	for (int h = n; h >= 1; h--){
		if (h <= a[n-h]) {
			result = h; break;
		}
	}
	cout << result; //h or 0
}
