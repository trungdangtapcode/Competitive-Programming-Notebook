#include <bits/stdc++.h>

using namespace std;
const long double pi = 4*atan(1);
long double x1, x2, r1, r2, y1, y2, a1, a2, o1o2;
long double findAngle(long double AB, long double AC, long double BC){
	return acos((AB*AB+AC*AC-BC*BC)/(2*AB*AC));
};
long double calcArea(long double r, long double angle){
	return (angle*r*r/2-sin(angle)*r*r/2);
}
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(9);
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	o1o2 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if (r1+r2<=o1o2){
		cout << 0 << '\n';
		return 0;
	}
	//if (x1==x2&&y1==y2){
	if (o1o2<=abs(r1-r2)){
		cout << min(r1,r2)*min(r1,r2)*pi << '\n';
		return 0;
	}
	a1 = 2*findAngle(r1,o1o2,r2);
	a2 = 2*findAngle(r2,o1o2,r1);
	cout << calcArea(r1,a1)+calcArea(r2,a2) << '\n';
	
	return 0;
}
