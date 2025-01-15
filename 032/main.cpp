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

    i16 N;
    cin >> N;

    i32 A[N + 1][N + 1];
    bool Z[N + 1][N + 1];
    rep(i, 1, N){
        rep(j, 1, N){
            cin >> A[i][j];
            Z[i][j] = true;
        }
    }

    i32 M;
    cin >> M;

    i16 X, Y;
    rep(i, 1, M){
        cin >> X >> Y;
        Z[X][Y] = false;
        Z[Y][X] = false;
    }

    vi16 order(N);
    rep(i, 0, N - 1){
        order[i] = i + 1;
    }

    i32 ans = INT32_MAX;
    do{
        i32 sum = 0;
        bool ok = true;
        rep(i, 0, N - 1){
            i16 now = order[i];
            if(i != 0){
                i16 prev = order[i - 1];
                if(!Z[now][prev]){
                    ok = false;
                    break;
                }
            }
            sum += A[now][i + 1];
        }
        if(ok){
            ans = min(ans, sum);
        }
    } while(next_permutation(all(order)));

    if(ans == INT32_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return(0);
}
