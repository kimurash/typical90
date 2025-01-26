// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MOD 1000000007

using namespace std;

using mint = atcoder::modint1000000007;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint64_t ui64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

ui64 pow10[20];

i64 calc_sum(ui64 n);
i64 power(i64 a, i64 b, i64 m);

int main(){
    cin.tie(nullptr);

    ui64 L, R;
    cin >> L >> R;

    pow10[0] = 1;
    rep(i, 1, 19){
        pow10[i] = pow10[i-1] * 10;
    }

    mint ans = 0;
    rep(i, 1, 19){
        ui64 l = max(pow10[i - 1], L);
        ui64 r = min(pow10[i] - 1, R);
        if(r < l){
            continue;
        }
        i64 n = calc_sum(r) - calc_sum(l - 1);
        ans += i * n;
    }

    cout << ans.val() << endl;

    return(0);
}

i64 calc_sum(ui64 n){
    i64 a = n % MOD;
    i64 b = (n + 1) % MOD;
    i64 ans = (a * b) % MOD;
    ans *= power(2, MOD - 2, MOD);
    return(ans);
}

// aのb乗をmで割った余りを返す
int64_t power(int64_t a, int64_t b, int64_t m){
    // p[i] = aの2^i乗 (mod m)
    int64_t p[61];
    p[0] = a;
    for(int i = 1; i <= 60; i++){
        p[i] = (p[i-1] * p[i-1]) % m;
    }
    int64_t ans = 1;
    int32_t exp = 0;
    while(0 < b){
        if(b % 2 == 1){
            ans = (ans * p[exp]) % m;
        }
        b /= 2;
        exp++;
    }
    return(ans);
}
