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

    i16 H, W;
    cin >> H >> W;

    i32 A[H + 1][W + 1];
    rep(i, 1, H){
        rep(j, 1, W){
            cin >> A[i][j];
        }
    }

    i32 B[H + 1][W + 1];
    rep(i, 1, H){
        rep(j, 1, W){
            cin >> B[i][j];
        }
    }

    i64 cnt = 0;
    rep(i, 1, H - 1){
        rep(j, 1, W - 1){
            if(A[i][j] < B[i][j]){
                i64 C = B[i][j] - A[i][j];
                A[i][j] += C;
                A[i][j + 1] += C;
                A[i + 1][j] += C;
                A[i + 1][j + 1] += C;
                cnt += C;
            } else if(B[i][j] < A[i][j]){
                i64 C = A[i][j] - B[i][j];
                A[i][j] -= C;
                A[i][j + 1] -= C;
                A[i + 1][j] -= C;
                A[i + 1][j + 1] -= C;
                cnt += C;
            }
        }
    }

    rep(i, 1, H){
        rep(j, 1, W){
            if(A[i][j] != B[i][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    cout << cnt << endl;

    return(0);
}
