#include <bits/stdc++.h>
int n;
long long int a[300005];
double x, y, xy;
using namespace std;int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	a[0] = 0; a[n+1] = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = n; i >= 1; i--) a[i] += a[i+1];
	//for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	
	double res = 0;
	for (int i = 1; i <= n; i++){
		xy = (double)a[i]/a[1] - (double)(n-i+1)/n; 
		//cout  <<  (double)a[i]/a[n] << " "  << ((double)1/2==0) << endl;
		//cout << (double)a[i]/a[1] << " - " << (double)(n-i+1)/n<< endl;
		if (xy > res){
			res = xy;
			y = (double)a[i]/a[1];
			x = (double)(n-i+1)/n;
		}
	}
	cout << 100*x << endl << 100*y;
	
	return 0;
}
