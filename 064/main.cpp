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

    i32 N, Q;
    cin >> N >> Q;

    i32 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    i64 E = 0;
    i64 B[N + 1] = { 0 };
    rep(i, 1, N - 1){
        B[i] = A[i + 1] - A[i];
        E += abs(B[i]);
    }

    i32 L, R, V;
    rep(i, 1, Q){
        cin >> L >> R >> V;
        i64 before = abs(B[L - 1]) + abs(B[R]);
        if(1 < L){
            B[L - 1] += V;
        }
        if(R < N){
            B[R] -= V;
        }
        i64 after = abs(B[L - 1]) + abs(B[R]);
        E += after - before;
        cout << E << endl;
    }

    return(0);
}
