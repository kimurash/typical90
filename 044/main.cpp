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

    i32 A[N];
    rep(i, 0, N - 1){
        cin >> A[i];
    }

    i32 T, X, Y;
    i32 shift = 0;
    rep(i, 1, Q){
        cin >> T >> X >> Y;
        X--; Y--;

        if(T == 1){
            i32 x = (X - shift + N) % N;
            i32 y = (Y - shift + N) % N;
            swap(A[x], A[y]);
        } else if(T == 2){
            shift++;
            shift %= N;
        } else if(T == 3){
            i32 x = (X - shift + N) % N;
            cout << A[x] << endl;
        }
    }

    return(0);
}
