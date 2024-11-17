#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], x;
void solve(){
    cin >> n >> x;
    int mid = (n-1)/2, lef = 0, rig = 0, eq = 0;
    vector<int> pos;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i]==-1){
            pos.push_back(i);
        } else {
            if (a[i]<x){
                lef++;
            } else if (a[i]>x){
                rig++;
            } else {
                eq++;
            }
        }
    }
    int remainl = mid-lef, remainr = mid-rig;
    if (remainr<0||remainl<0){
        cout << "NO\n";
        return;
    }
    if (eq==0){
        //ko co x trong b
        //cout << "not implement\n";
        if (remainr==0&&remainl==0&&false){
            cout << "NO\n";
            return;
        }
        if (remainl>=remainr){
            //remainl--;
            int cur = pos.back(); pos.pop_back();
            a[cur] = x;
        } else {
            //remainr--;
            int cur = pos.back(); pos.pop_back();
            a[cur] = x;
        }
        for (int i = 1; i <= remainl; i++){
            int cur = pos.back(); pos.pop_back();
            a[cur] = 0;
        }
        for (int i = 1; i <= remainr; i++){
            int cur = pos.back(); pos.pop_back();
            a[cur] = 1e9;
        }
        cout << "YES\n";
        for (int i = 1; i<= n; i++) cout << a[i] << " "; cout << "\n";
        return;
    }
    //2 - dl + 0 = mid
    //remainl-dl+lef = mid
    //remainr-dr+rig = mid
    //dl + dr == eq-1
    int dl = min(remainl,eq-1);
    int dr = eq-1-dl;
    //if (dl+dr!=eq-1){
    //    cout << "NO\n";
    //    return;
    //}
    //int rhs = n-pos.length();
    remainl -= dl;
    remainr -= dr;
    if (remainr<0||remainl<0){
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= remainl; i++){
        int cur = pos.back(); pos.pop_back();
        a[cur] = 0;
    }
    for (int i = 1; i <= remainr; i++){
        int cur = pos.back(); pos.pop_back();
        a[cur] = 1e9;
    }
    assert(pos.size()==0);
    cout << "YES\n";
    for (int i = 1; i<= n; i++) cout << a[i] << " "; cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    //freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

