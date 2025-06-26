#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
using namespace std;

#define ll long long
#define ld long double
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define pp pop_back
#define nn "\n"
#define mod 1000000007
#define N 200005
#define PI 2 * acos(0.0)

#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define rall(v) v.rbegin(), v.rend()
#define rsrt(v) sort(v.rbegin(), v.rend())
#define grtsrt(v) sort(v.begin(), v.end(), greater<int>())
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define dbg(x) cerr << (#x) << " = " << (x) << "\n"
// #define cerr if (false) cerr

void puzzleout()
{
    ll a, x, y;
    cin >> a >> x >> y;
    ll mx = max(x, y);
    ll mn = min(x, y);
    if (mn > a || mx < a)
    {
        cout << "YES" << nn;
        return;
    }
    cout << "NO" << nn;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC = 1;
    cin >> TC;
    while (TC--)
    {
        puzzleout();
    }
    return 0;
}
/* input
p1 0 12
p2 1 3
p3 2 5
p4 3 8
p5 4 2
*/
