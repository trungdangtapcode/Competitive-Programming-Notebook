#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ldb;

/// 
///                *A
///               /|\
///              / | \
///             / d|  \                 a = BC
///            /   |   \                b = CA
///           /    O    \               c = AB
///        c /    / \    \ b            d = OA 
///         /   /     \   \             e = OB
///        /  /         \  \            f = OC
///       / / e         f \ \
///      //                 \\
///     /         a           \
///    *-----------------------*
///    B                       C
///

/// check if 3 edges form a triangle
bool isTri(ll a, ll b, ll c)
{
    return (a + b > c) && (b + c > a) && (c + a > b);
}

/// Tetrahedron Volumn 
ldb volumn(ll u, ll U, ll v, ll V, ll w, ll W)
{
    ldb X = (w * w + u * u - V * V);
    ldb Y = (v * v + w * w - U * U);
    ldb Z = (u * u + v * v - W * W);
    ldb T = (u * v * w);
    return sqrt(X * Y * Z + 2 * 2 * T * T - u * u * Y * Y - v * v * X * X - w * w * Z * Z) / 12;
}

bool query()
{
    ll x[6];
    for (int i = 0; i < 6; ++i)
        cin >> x[i];

    sort(x, x + 6);
    if (x[0] <= 0) return false;
	bool ch = false;
    do
    {
        ll BC = x[0];
        ll CA = x[1];
        ll AB = x[2];
        ll OA = x[3];
        ll OB = x[4];
        ll OC = x[5];
        bool ABC = isTri(BC, CA, AB);
        bool OBC = isTri(BC, OB, OC);
        bool OCA = isTri(CA, OC, OA);
        bool OAB = isTri(AB, OA, OB);
        ldb V_OABC = volumn(OA, BC, OB, CA, OC, AB);
        cout <<x[0] << " "<<x[1] <<" "<<x[2] <<" "<<x[3] <<" "<<x[4]<<" "<<x[5] <<" " << V_OABC<< endl;
        if (ABC && OBC && OCA && OAB && V_OABC > 0) ch = true;
    }
    while (next_permutation(x, x + 6));

    return ch;
}

int main()
{
    int q;
    cin >> q;

    while (q-->0) cout << (query() ? "Yes" : "No") << '\n';
    return 0;
}
