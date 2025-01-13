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

    i32 N;
    cin >> N;

    string S;
    cin >> S;

    string T = "atcoder";

    // dp[i][j] = i文字目までの文字列でTのj文字目までの文字列が作れる通り数
    mint dp[N + 1][8];
    rep(i, 0, N){
        rep(j, 0, 7){
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    rep(i, 1, N){
        rep(j, 0, 7){
            dp[i][j] += dp[i - 1][j];
            if(j < 7 && S[i - 1] == T[j]){
                dp[i][j + 1] += dp[i - 1][j];
            }
        }
    }

    cout << dp[N][7].val() << endl;

    return(0);
}
