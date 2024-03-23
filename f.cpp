#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
int N, A[100];

mint dp[101][1 << 11];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    dp[0][1] = 1;

    for (int i = 0; i < N; ++i)
        for (int x = 1; x < 1 << 11; ++x)
        {
            mint A_inv = mint(A[i]).inv();
            for (int a = 1; a < 11; ++a)
            {
                int y = (x | x << a) & ((1 << 11) - 1);
                dp[i + 1][y] += dp[i][x] * (a <= A[i] ? A_inv : 0);
            }
            dp[i + 1][x] += dp[i][x] * max(0, A[i] - 10) * A_inv;
        }
    mint ans = 0;
    for (int i = 1 << 10; i < 1 << 11; ++i)
        ans += dp[N][i];
    cout << ans << '\n';
}
