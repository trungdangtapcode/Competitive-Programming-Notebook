#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;	
int n, l, r, cnt;
#define li pair<long long, int>
#define ordered_set tree<li, null_type, less<li>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set s;
long long sum, res;
int main(){
	cin >> n >> l >> r;
	s.insert({0,cnt++});
	for (int i = 0, a; i < n; i++){
		cin >> a;
		sum += a;
		res += s.order_of_key({sum-l,1e9})-s.order_of_key({sum-r,-1});
//		res += distance(s.lower_bound({sum-r,0}),s.upper_bound({sum-l,1e9}));
		s.insert({sum,cnt++});
	}
	cout << res;
	
	return 0;
}
