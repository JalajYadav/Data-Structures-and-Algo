// Link: https://codeforces.com/contest/670/problem/D1

// D1. Magic Powder - 1

// Waking up in the morning, Apollinaria decided to bake cookies. To bake one cookie, she needs n ingredients, and for each ingredient she knows the value ai — how many grams of this ingredient one needs to bake a cookie. To prepare one cookie Apollinaria needs to use all n ingredients.

// Apollinaria has bi gram of the i-th ingredient. Also she has k grams of a magic powder. Each gram of magic powder can be turned to exactly 1 gram of any of the n ingredients and can be used for baking cookies.

// Your task is to determine the maximum number of cookies, which Apollinaria is able to bake using the ingredients that she has and the magic powder.

// Input
// The first line of the input contains two positive integers n and k (1 ≤ n, k ≤ 1000) — the number of ingredients and the number of grams of the magic powder.

// The second line contains the sequence a1, a2, ..., an (1 ≤ ai ≤ 1000), where the i-th number is equal to the number of grams of the i-th ingredient, needed to bake one cookie.

// The third line contains the sequence b1, b2, ..., bn (1 ≤ bi ≤ 1000), where the i-th number is equal to the number of grams of the i-th ingredient, which Apollinaria has.

// Output
// Print the maximum number of cookies, which Apollinaria will be able to bake using the ingredients that she has and the magic powder.

// Examples
// inputCopy
// 3 1
// 2 1 4
// 11 3 16
// outputCopy
// 4
// inputCopy
// 4 3
// 4 3 5 6
// 11 12 14 20
// outputCopy
// 3

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

int n, k;
vector<int> a(1000);
vector<int> b(1000);

int extraGrams(int x)
{
    int ans = 0;
    int i = 0;
    rep(i, n)
    {
        if (((x * a[i]) - b[i]) >= 0)
            ans += ((x * a[i]) - b[i]);
    }
    return ans;
}

void solve()
{
    cin >> n;
    cin >> k;

    int i = 0;
    rep(i, n)
    {
        cin >> a[i];
    }
    i = 0;
    rep(i, n)
    {
        cin >> b[i];
    }

    int low(0), high(2000), z, mid;

    int res = 0;
    while (low <= high)
    {
        mid = (high + low) / 2;

        z = extraGrams(mid);
        if (z == k)
        {
            cout << mid << endl;
            return;
        }
        else if (z < k)
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << res << endl;
    return;
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
