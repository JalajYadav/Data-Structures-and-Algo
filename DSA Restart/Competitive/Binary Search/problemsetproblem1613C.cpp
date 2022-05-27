// Link: https://codeforces.com/problemset/problem/1613/C

// C. Poisoned Dagger
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Monocarp is playing yet another computer game. In this game, his character has to kill a dragon. The battle with the dragon lasts 100500 seconds, during which Monocarp attacks the dragon with a poisoned dagger. The i-th attack is performed at the beginning of the ai-th second from the battle start. The dagger itself does not deal damage, but it applies a poison effect on the dragon, which deals 1 damage during each of the next k seconds (starting with the same second when the dragon was stabbed by the dagger). However, if the dragon has already been poisoned, then the dagger updates the poison effect (i.e. cancels the current poison effect and applies a new one).

// For example, suppose k=4, and Monocarp stabs the dragon during the seconds 2, 4 and 10. Then the poison effect is applied at the start of the 2-nd second and deals 1 damage during the 2-nd and 3-rd seconds; then, at the beginning of the 4-th second, the poison effect is reapplied, so it deals exactly 1 damage during the seconds 4, 5, 6 and 7; then, during the 10-th second, the poison effect is applied again, and it deals 1 damage during the seconds 10, 11, 12 and 13. In total, the dragon receives 10 damage.

// Monocarp knows that the dragon has h hit points, and if he deals at least h damage to the dragon during the battle — he slays the dragon. Monocarp has not decided on the strength of the poison he will use during the battle, so he wants to find the minimum possible value of k (the number of seconds the poison effect lasts) that is enough to deal at least h damage to the dragon.

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases.

// The first line of the test case contains two integers n and h (1≤n≤100;1≤h≤1018) — the number of Monocarp's attacks and the amount of damage that needs to be dealt.

// The second line contains n integers a1, a2, ..., an (1≤ai≤109;ai<ai+1), where ai is the second when the i-th attack is performed.

// Output
// For each test case, print a single integer — the minimum value of the parameter k, such that Monocarp will cause at least h damage to the dragon.

// Example
// inputCopy
// 4
// 2 5
// 1 5
// 3 10
// 2 4 10
// 5 3
// 1 2 4 5 7
// 4 1000
// 3 25 64 1337
// outputCopy
// 3
// 4
// 1
// 470

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

ll calcCst(ll x, vector<ll> &vec, ll n)
{
    ll i = 0;
    ll answer = 0;
    rep(i, n)
    {
        if (i == n - 1)
        {
            answer += x;
            break;
        }
        answer += min(x, vec[i + 1] - vec[i]);
    }
    return answer;
}

void solve()
{
    ll n, h;
    vector<ll> vec;

    cin >> n;
    cin >> h;

    ll i = 0;

    rep(i, n)
    {
        ll temp;
        cin >> temp;
        vec.push_back(temp);
    }

    ll low(1), high(h), mid, cst;

    while (low <= high)
    {
        mid = (low + high) / 2;

        cst = calcCst(mid, vec, n);

        if (cst == h)
        {
            cout << mid << endl;
            return;
        }
        else if (cst > h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
