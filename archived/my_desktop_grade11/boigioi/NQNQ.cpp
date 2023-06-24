#include <bits/stdc++.h>

using namespace std;
int n;
long long int a[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i =0 ; i < n; i++) cin >> a[i];
	
	sort(a,a+n);
	long long int x = 0;
	while (true){
		if (!binary_search(a,a+n,x*x)){
			cout << x*x;
			return 0;
		}
		x++;
	}
	return 0;
}
