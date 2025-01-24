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

    i32 X[N], Y[N];
    rep(i, 0, N - 1){
        cin >> X[i] >> Y[i];
    }

    sort(X, X + N);
    sort(Y, Y + N);

    i64 fx, fy;
    if(N % 2 == 0){
        fx = (X[N / 2 - 1] + X[N / 2]) / 2;
        fy = (Y[N / 2 - 1] + Y[N / 2]) / 2;
    } else{
        fx = X[N / 2];
        fy = Y[N / 2];
    }

    i64 ans = 0;
    rep(i, 0, N - 1){
        ans += abs(X[i] - fx) + abs(Y[i] - fy);
    }

    cout << ans << endl;

    return(0);
}
