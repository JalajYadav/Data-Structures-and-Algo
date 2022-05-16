// C. Hamburgers

//Link: https://codeforces.com/contest/371/problem/C

// Examples
// inputCopy
// BBBSSC
// 6 4 1
// 1 2 3
// 4
// outputCopy
// 2
// inputCopy
// BBC
// 1 10 1
// 1 10 1
// 21
// outputCopy
// 7
// inputCopy
// BSC
// 1 1 1
// 1 1 3
// 1000000000000
// outputCopy
// 200000000001

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

int nb, ns, nc;
int pb, ps, pc;
ll rubles;
int b_cnt = 0;
int s_cnt = 0;
int c_cnt = 0;

ll priceHamb(ll cnt)
{
    ll a, b, c;
    a = max(cnt * b_cnt - nb, (ll)0);
    b = max(cnt * s_cnt - ns, (ll)0);
    c = max(cnt * c_cnt - nc, (ll)0);

    return ((a * pb) + (b * ps) + (c * pc));
}

void solve()
{
    int i;
    ll result(0);
    string burger = "";
    cin >> burger;

    cin >> nb;
    cin >> ns;
    cin >> nc;

    cin >> pb;
    cin >> ps;
    cin >> pc;

    cin >> rubles;

    rep(i, burger.length())
    {
        if (burger[i] == 'B')
        {
            b_cnt++;
        }
        else if (burger[i] == 'S')
        {
            s_cnt++;
        }
        else
        {
            c_cnt++;
        }
    }

    ll low(0), high(1e14), mid, z;
    while (low <= high)
    {
        mid = (high + low) / 2;
        z = priceHamb(mid);

        if (z == rubles)
        {
            cout << mid;
            return;
        }
        if (z < rubles)
        {
            low = mid + 1;
            result = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << result << endl;
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
    return 0;
}
