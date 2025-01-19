// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

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

    i32 n;
    i32 A[46], B[46], C[46];
    rep(i, 0, 45){
        A[i] = 0;
        B[i] = 0;
        C[i] = 0;
    }
    rep(i, 1, N){
        cin >> n;
        A[n % 46]++;
    }
    rep(i, 1, N){
        cin >> n;
        B[n % 46]++;
    }
    rep(i, 1, N){
        cin >> n;
        C[n % 46]++;
    }

    i64 ans = 0;
    rep(i, 0, 45){
        rep(j, 0, 45){
            rep(k, 0, 45){
                if((i + j + k) % 46 == 0){
                    ans += 1LL * A[i] * B[j] * C[k];
                }
            }
        }
    }

    cout << ans << endl;

    return(0);
}
