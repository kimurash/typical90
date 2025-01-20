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

    i16 N;
    cin >> N;

    i32 A[N + 1];
    rep(i, 1, N){
        A[i] = 0;

        i32 a;
        rep(j, 1, 6){
            cin >> a;
            A[i] += a;
        }
    }

    mint ans = 1;
    rep(i, 1, N){
        ans *= A[i];
    }

    cout << ans.val() << endl;

    return(0);
}
