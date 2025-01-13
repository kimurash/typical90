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

    i32 N, L, K;
    cin >> N >> L >> K;

    i32 A[N + 2];
    A[0] = 0;
    rep(i, 1, N){
        cin >> A[i];
    }
    A[N + 1] = L;

    i32 low = 0;
    i32 high = L;
    while(low + 1 < high){
        i32 mid = (low + high) / 2;

        i32 cnt = 0;
        i32 len = 0;
        rep(i, 1, N + 1){
            len += A[i] - A[i - 1];
            if(mid <= len){
                len = 0;
                cnt++;
            }
        }

        if(K + 1 <= cnt){
            low = mid;
        } else{
            high = mid;
        }
    }

    cout << low << endl;
    return(0);
}
