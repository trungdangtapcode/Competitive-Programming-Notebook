#include <bits/stdc++.h>

using namespace std;
double a, h;

double getPerformance(double x){
	if (x>=h/3) return 100;
	if (x>=h/6) return (100-a)/(h/6)*(x-h/6) + a;
	return a/(h/6)*x;
}

int main(){
	
	cin >> a >> h;
	double res = 0;
	for (int i = 0; i <= 10e7; i++){
		double x = i*(1e-7)*h;
		res = max(res,getPerformance(x)*(h-x));
		//cout << fixed << setprecision(8) << x/h << " -> " << getPerformance(x) << endl;
	}
	cout << fixed << setprecision(7) << res;
	
	return 0;
}
