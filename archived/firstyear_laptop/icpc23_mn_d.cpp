#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> i3;
int n, g, f[505][505], a[505][505];
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
void task1(){
    cin >> n >> g;
//    for (int i = 2; i<= n; i++) f[i][0] = f[0][i] = 1e9;
    priority_queue<i3, vector<i3>, greater<i3>> pq;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            f[i][j] = 1e9;
        }
    }
    f[1][1] = a[1][1]<g;
    pq.push({f[1][1],{1,1}});
    while (pq.size()){
        auto it = pq.top().second; pq.pop();
        int ux = it.first, uy = it.second;
        for (int i = 0; i < 4; i++){
            int vx = ux + dx[i], vy = uy + dy[i];
            if (vx>n||vy>n||vx<1||vy<1) continue;
            if (f[vx][vy]>f[ux][uy]+(a[vx][vy]<g)){
                f[vx][vy]=f[ux][uy]+(a[vx][vy]<g);
                pq.push({f[vx][vy],{vx,vy}});
            }
        }
    }
//    for (int i = 1; i <= n; i++){
//        for (int j = 1; j <= n; j++){
//            cout << f[i][j] << " ";
//        }
//        cout << "\n";
//    }
    cout << f[n][n];

}
void task2(){
    cin >> n;
//    cout << "\n";
    priority_queue<i3> pq;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            f[i][j] = -1e9;
        }
    }
    f[1][1] = a[1][1];
    pq.push({f[1][1],{1,1}});
    while (pq.size()){
        auto it = pq.top().second; pq.pop();
        int ux = it.first, uy = it.second;
        for (int i = 0; i < 4; i++){
            int vx = ux + dx[i], vy = uy + dy[i];
            if (vx>n||vy>n||vx<1||vy<1) continue;
            if (f[vx][vy]<min(f[ux][uy],a[vx][vy])){
                f[vx][vy]=min(f[ux][uy],a[vx][vy]);
                pq.push({f[vx][vy],{vx,vy}});
            }
        }
    }
    cout << f[n][n];
}

main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    if (t==1) task1();
    else task2();

    return 0;
}
