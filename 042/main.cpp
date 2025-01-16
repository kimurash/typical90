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

    i32 K;
    cin >> K;

    if(K % 9 != 0){
        cout << 0 << endl;
        return(0);
    }

    // dp[i]: 各桁の和がiになる数の個数
    mint dp[K + 1];
    dp[0] = 1;
    rep(i, 0, K - 1){
        rep(j, 1, 9){
            if(i + j <= K){
                dp[i + j] += dp[i];
            }
        }
    }

    cout << dp[K].val() << endl;

    return(0);
}
