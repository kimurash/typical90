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

    i32 N, K;
    cin >> N >> K;

    i32 A[N + 1], B[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }
    rep(i, 1, N){
        cin >> B[i];
    }

    i64 diff = 0;
    rep(i, 1, N){
        diff += abs(A[i] - B[i]);
    }

    if(diff == K){
        cout << "Yes" << endl;
    } else{
        if(diff < K){
            i64 rem = K - diff;
            if(rem % 2 == 0){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        } else{
            cout << "No" << endl;
        }
    }

    return(0);
}
