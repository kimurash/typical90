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

    i64 sum = 0;
    i32 A[2 * N + 1];
    rep(i, 1, N){
        cin >> A[i];
        A[i + N] = A[i];

        sum += A[i];
    }

    bool ans = false;
    i64 part = sum / 10;

    i32 l = 1;
    i64 len = 0;
    for(i32 r = 1; r <= 2 * N; r++){
        len += A[r];
        if(len == part){
            ans = true;
            break;
        }

        while(part < len){
            len -= A[l];
            l++;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;

    return(0);
}
