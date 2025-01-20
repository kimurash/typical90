// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

using mint = atcoder::modint1000000007;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N, L;
    cin >> N >> L;

    mint dp[N + 1];
    dp[0] = 1;
    rep(i, 1, N){
        dp[i] = 0;
    }

    rep(i, 0, N - 1){
        dp[i + 1] += dp[i];
        if(i + L <= N){
            dp[i + L] += dp[i];
        }
    }

    cout << dp[N].val() << endl;

    return(0);
}
