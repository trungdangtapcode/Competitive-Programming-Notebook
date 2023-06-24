#include <bits/stdc++.h>

using namespace std;
typedef pair<double,double> ii; //doc nham de
vector<ii> a;
int n;
stack<int> s;
bool cmp1(ii x, ii y){
	if (x.second==y.second) return (x.first < y.first);
	return (x.second < y.second);
}
bool cmp2(ii x, ii y){
	return (atan2(x.second-a[0].second,x.first-a[0].first)<atan2(y.second-a[0].second,y.first-a[0].first));
}
bool check(ii x, ii y){
	if (abs(x.first*y.second-x.second*y.first) <= 1e-9){ //chua thu, doan dai cx dung
		return (x.first*y.first+x.second*y.second<0); //product of 2 vectors
	}
	return (x.first*y.second-x.second*y.first > +1e-6); //ok
}
ii makeline(ii x, ii y){
	return {y.first-x.first,y.second-x.second};
}

int main(){
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(),a.end(),cmp1); //find beginning
	a.resize(unique(a.begin(),a.end())-a.begin());
	n = a.size();
	sort(a.begin()+1,a.end(),cmp2); //sieve then sort
	a.push_back(a[0]); //a[n] = a[0]. ko can n++
	
	s.push(0);
	for (int i = 1; i <= n; i++){
		while (s.size()>=2){ //Graham
			int tmp1 = s.top(); s.pop();
			int tmp2 = s.top(); 
			if (check(makeline(a[tmp2],a[tmp1]),makeline(a[tmp1],a[i]))){
				s.push(tmp1);
				break;
			}
		}
		s.push(i);
	}
	
	cout << s.size()-1 << " ";
	double sum = 0;
	while (s.size()>=2){
		int tmp1 = s.top(); s.pop();
		int tmp2 = s.top();
		sum += 1.0*a[tmp1].first*a[tmp2].second-1.0*a[tmp1].second*a[tmp2].first;
	}
	if (abs(sum)/2<=1e6)cout << fixed << setprecision(2) << abs(sum)/2;
	else cout << fixed << setprecision(0) << abs(sum)/2;
	
//	cout << a[8].first << ", " << a[8].second << endl;
//	while (!s.empty()){
//		cout << s.top() <<" "<<  a[s.top()].first << "," <<  a[s.top()].second << endl;
//		s.pop();
//	}
//	for (int i = 0; i < n; i++) cout << a[i].first << "," << a[i].second << '\n';
	
	return 0;
}
