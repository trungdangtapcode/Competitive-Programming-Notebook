#include<bits/stdc++.h>

using namespace std;
int n;
bool p[200005];
vector<int> prime, v;

int main(){
	
	cin >> n;
	for (int i = 2; i <= n; i++) p[i] = 1;
	for (int i = 2; i*i <= n; i++) if (p[i]){
		for (int j = i*i; j <= n; j+=i) p[j] = 0;
	}
	for (int i = 2; i <= n; i++) if (p[i]) prime.push_back(i);
	for (int i = 0; i < prime.size(); i++){
		int j = 0;
		for (j = i+1; j < prime.size(); j++) if (1ll*prime[i]*prime[j]>n)break;
		j--;
		for (;j>i; j--) v.push_back(1ll*prime[i]*prime[j]);
	}
	sort(v.begin(),v.end());
	bitset<100005> mask0, mask1, mask2, mask3;
	mask0[0] = 1;
//	for (int x: v) cout << x << " ";
	for (int x: v) mask1[x] = 1;
	for (int x: v) mask2 |= ((mask1&~(mask0<<x))<<x);
	for (int x: v) mask3 |= ((mask2&~(mask1<<x))<<x);
	int res = 0;
	for (int i = 1; i <= n; i++) res += mask3[i];
	cout << res;
	
	return 0;	
}



/*
#include<bits/stdc++.h>

using namespace std;
int n;
bool p[100005];
vector<int> prime;

int main(){
	
	cin >> n;
	for (int i = 2; i <= n; i++) p[i] = true;
	for (int i = 2; i*i <= n; i++) if (p[i]){
		for (int j = i*i; j <= n; j += i) p[j] = false;
	}
	for (int i = 2; i <= n; i++) if (p[i]) prime.push_back(i);
	
	vector<int> v;
	for (int i = 2; i*i < n; i++) if (p[i]){
		int pos = upper_bound(prime.begin(),prime.end(),n/i)-prime.begin()-1;
		for (int j = 0; j <= pos; j++) if (prime[j]!=i) v.push_back(i*prime[j]);
	}
	bitset<105> mask1, mask2, mask3;
//	sort(v.begin(),v.end());
//	v.erase(unique(v.begin(),v.end()),v.end());
//	for (int i = 0; i < v.size(); i++) for (int j = i+1; j < v.size(); j++) for (int k = j+1; k < v.size(); k++) mask1[v[i]+v[j]+v[k]] = 1;
//	cout << endl;
	for (int x: v) mask1[x] = 1;
//	cout << mask1;
//	for (int x: v) mask2 |= (mask1<<x);
	for (int x: v){
		bitset<105> tmp = mask1;
		tmp[x] = 0;
		mask2|= (tmp<<x);
	}
	for (int x: v) mask3 |= (mask2<<x);
	for (int i = 1, dem = 0; i <= 50; i++) if (mask3[i]) cout << i << "(" << ++dem << ") ";
//	for (int i = 1, dem = 0; i <= 50; i++) if (mask2[i]) cout << i << "(" << ++dem << ") ";
		
	return 0;
}
*/
