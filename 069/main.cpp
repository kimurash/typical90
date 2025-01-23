// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MOD 1000000007

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

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

int main(){
    cin.tie(nullptr);

    i64 N, K;
    cin >> N >> K;

    i64 ans;
    if(N == 1){
        ans = K;
    } else{
        ans = K * (K - 1) % MOD;
        if(2 < N){
            ans = (ans * power(K - 2, N - 2, MOD)) % MOD;
        }
    }

    cout << ans << endl;

    return(0);
}
