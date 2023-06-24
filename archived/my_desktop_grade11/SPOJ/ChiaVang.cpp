#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

int n, n1, n2, res;
unordered_map<int,int> cnt1, cnt2; //unordered faster than ordered wtf
vector<int> a1, a2;
void calc1(int k, int sum1, int sum2){
	if (k==n1){
		cnt1[sum1-sum2] = max(cnt1[sum1-sum2],sum1+sum2);
		return;
	}
	calc1(k+1,sum1,sum2);
	calc1(k+1,sum1+a1[k],sum2);
	calc1(k+1,sum1,sum2+a1[k]);
}
void calc2(int k, int sum1, int sum2){
	if (k==n2){
		cnt2[sum1-sum2] = max(cnt2[sum1-sum2],sum1+sum2);
		return;
	}
	calc2(k+1,sum1,sum2);
	calc2(k+1,sum1+a2[k],sum2);
	calc2(k+1,sum1,sum2+a2[k]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	n1 = n/2;
	n2 = n - n/2;
	a1.assign(n1,0);
	a2.assign(n2,0);
	for (int i = 0; i < n1; i++){
		cin >> a1[i];
	}
	for (int i = 0; i < n2; i++){
		cin >> a2[i];
	}
//	n = 24;
//	n1 = n/2;
//	n2 = n - n/2;
//	a1.assign(n1,rand()%10000000);
//	a2.assign(n2,rand()%10000000);

	calc1(0,0,0);
	calc2(0,0,0);
	
	for (auto it: cnt1){
		if (cnt2.find(it.first)!=cnt2.end()){
			res = max(res,it.second+cnt2[it.first]);
		}
	}
	cout << res/2;
	
	return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

int n, n1, n2, res;
vector<ii> cnt1, cnt2; 
vector<int> a1, a2;
void calc1(int k, int sum1, int sum2){
	if (k==n1){
		cnt1.push_back({sum1-sum2,sum1+sum2});
		return;
	}
	calc1(k+1,sum1,sum2);
	calc1(k+1,sum1+a1[k],sum2);
	calc1(k+1,sum1,sum2+a1[k]);
}
void calc2(int k, int sum1, int sum2){
	if (k==n2){
		cnt2.push_back({sum1-sum2,sum1+sum2});
		return;
	}
	calc2(k+1,sum1,sum2);
	calc2(k+1,sum1+a2[k],sum2);
	calc2(k+1,sum1,sum2+a2[k]);
}

int main(){
	
	cin >> n;
	n1 = n/2;
	n2 = n - n/2;
	a1.assign(n1,0);
	a2.assign(n2,0);
	for (int i = 0; i < n1; i++){
		cin >> a1[i];
	}
	for (int i = 0; i < n2; i++){
		cin >> a2[i];
	}
	calc1(0,0,0);
	calc2(0,0,0);
	sort(cnt1.begin(),cnt1.end());
	sort(cnt2.begin(),cnt2.end());
	
	for (auto it: cnt1){
		auto x = *lower_bound(cnt2.begin(),cnt2.end(),ii{-it.first,-1});
		if (x.first==it.first){
//			res = max(res,*lower_bound(cnt2.begin(),cnt2.end(),-it.first));
//			res = 
		}
	}
	cout << res/2;
	
	return 0;
}
*/
