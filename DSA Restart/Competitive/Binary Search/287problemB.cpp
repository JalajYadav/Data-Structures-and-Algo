//Link: https://codeforces.com/contest/287/problem/B

// B. Pipeline
// time limit per test0.4 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Vova, the Ultimate Thule new shaman, wants to build a pipeline. As there are exactly n houses in Ultimate Thule, Vova wants the city to have exactly n pipes, each such pipe should be connected to the water supply. A pipe can be connected to the water supply if there's water flowing out of it. Initially Vova has only one pipe with flowing water. Besides, Vova has several splitters.

// A splitter is a construction that consists of one input (it can be connected to a water pipe) and x output pipes. When a splitter is connected to a water pipe, water flows from each output pipe. You can assume that the output pipes are ordinary pipes. For example, you can connect water supply to such pipe if there's water flowing out from it. At most one splitter can be connected to any water pipe.

// The figure shows a 4-output splitter
// Vova has one splitter of each kind: with 2, 3, 4, ..., k outputs. Help Vova use the minimum number of splitters to build the required pipeline or otherwise state that it's impossible.

// Vova needs the pipeline to have exactly n pipes with flowing out water. Note that some of those pipes can be the output pipes of the splitters.

// Input
// The first line contains two space-separated integers n and k (1 ≤ n ≤ 1018, 2 ≤ k ≤ 109).

// Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

// Output
// Print a single integer — the minimum number of splitters needed to build the pipeline. If it is impossible to build a pipeline with the given splitters, print -1.

// Examples
// inputCopy
// 4 3
// outputCopy
// 2
// inputCopy
// 5 5
// outputCopy
// 1
// inputCopy
// 8 4
// outputCopy
// -1

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

ll n, k;

ll sumA(ll x)
{
    return (x * (x + 1)) / 2;
}

ll sumA(ll mid, ll end)
{
    if (mid <= 1)
        return sumA(end);

    return (sumA(end) - sumA(mid - 1));
}

void solve()
{
    cin >> n;
    cin >> k;

    if (n == 1)
    {
        cout << 0;
        return;
    }

    if (n <= k)
    {
        cout << 1;
        return;
    }

    --k;
    --n;

    if (sumA(k) < n)
    {
        cout << -1 << "\n";
        return;
    }

    ll st = 1, en = k;

    while (st < en)
    {
        ll md = (st + en) / 2;
        ll s = sumA(md, k);

        if (s == n)
        {
            cout << (k - md + 1);
            return;
        }
        if (s > n)
            st = md + 1;
        else
            en = md;
    }

    cout << (k - st + 2);
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
