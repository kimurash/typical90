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

    i32 A[N];
    rep(i, 0, N - 1){
        cin >> A[i];
    }

    sort(A, A + N);

    i32 Q;
    cin >> Q;

    i32 B;
    rep(i, 1, Q){
        cin >> B;

        i32 idx = lower_bound(A, A + N, B) - A;

        i32 ans;
        if(idx == 0){
            ans = abs(A[0] - B);
        } else if(idx == N){
            ans = abs(A[N - 1] - B);
        } else{
            ans = min(
                abs(A[idx]     - B),
                abs(A[idx - 1] - B)
            );
        }
        cout << ans << endl;
    }

    return(0);
}
