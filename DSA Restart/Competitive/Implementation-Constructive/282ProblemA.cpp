// Link: https://codeforces.com/problemset/problem/282/A

// A. Bit++

// Examples
// inputCopy
// 1
// ++X
// outputCopy
// 1
// inputCopy
// 2
// X++
// --X
// outputCopy
// 0

#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define pb push_back
#define mk make_pair
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int chkr(string stmt)
{
    int j = 0;
    rep(j, stmt.length())
    {
        if (stmt[j] == '+')
        {
            return 1;
        }
        if (stmt[j] != '+' and stmt[j] != '-' and stmt[j] != 'X')
        {
            return 0;
        }
    }
    return -1;
}

void solve()
{
    int n;
    cin >> n;

    int i = 0;
    int res = 0;
    rep(i, n)
    {
        string stmt;
        cin >> stmt;
        res += chkr(stmt);
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
