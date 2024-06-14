#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5+5, maxNs = (int)sqrt(maxN);
int a[maxN], n, q;
struct Range{
	int l = -1, r = -1, sum = 0;
	bool rev = 0;
	Range(int l, int r){
		this->l = l;
		this->r = r;
	}
	void calc_sum(){
		sum = 0;
		for (int i = l; i <= r; i++) sum += a[i];
	}
	void calc_rev(){
		if (rev==0) return;
		for (int ll = l, rr = r; ll < rr; ll++, rr--){
			swap(a[ll],a[rr]);
		}
	}
};
vector<Range> v;
int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i += maxNs){
		v.push_back(Range(i,min(i+maxNs-1,n)));
		v.back().calc_sum();
	}
	while (q--){
		int t, l, r;
		cin >> t >> l >> r;
		if (t==1){
			int blockL = -1, blockR = -1;
			for (int i = v.size()-1; i >= 0; i--) if (v[i].l<=r){
				if (v[i].r>r){
					v[i].calc_rev();
					Range tmp1 = Range(v[i].l,r), tmp2 = Range(r+1,v[i].r);
					tmp1.calc_sum(), tmp2.calc_sum();
					v.erase(v.begin()+i);
					v.insert(v.begin()+i,tmp2);
					v.insert(v.begin()+i,tmp1);
				}
				break;
			}
			for (int i = 0; i < v.size(); i++) if (v[i].r>=l){
				if (v[i].l<l){
					v[i].calc_rev();
					Range tmp1 = Range(v[i].l,l-1), tmp2 = Range(l,v[i].r);
					tmp1.calc_sum(), tmp2.calc_sum();
					v.erase(v.begin()+i);
					v.insert(v.begin()+i,tmp2);
					v.insert(v.begin()+i,tmp1);	
				}
				break;
			}
			for (int i = 0; i < v.size(); i++) if (v[i].r>=l){
				blockL = i;
				break;
			}
			for (int i = v.size()-1; i >= 0; i--) if (v[i].l<=r){
				blockR = i;
				break;
			}
			for (int i = blockL; i <= blockR; i++){
				v[i].rev ^= 1;
			}
			for (; blockL<blockR; blockL++, blockR--){
				swap(v[blockL],v[blockR]);
			}
			vector<Range> vtmp;
			vtmp.push_back(v[0]);
			for (int i = 1; i < v.size(); i++){
				if (v[i].r-vtmp.back().l+1<3*maxNs&&v[i].rev==vtmp.back().rev){
					Range tmp = Range(vtmp.back().l,v[i].r);
					tmp.sum = vtmp.back().sum + v[i].sum;
					tmp.rev = v[i].rev;
					vtmp.back() = tmp;
				} else vtmp.push_back(v[i]);
			}
			v = vtmp;
		}
		else {
			
		}
	}
	
	return 0;
}

//https://onlinegdb.com/7XxzrjpC_
