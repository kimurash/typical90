// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 1009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

i32 grid[MAX][MAX];
i32 acc[MAX][MAX];

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 lx, ly, rx, ry;
    rep(i, 1, N){
        cin >> lx >> ly >> rx >> ry;
        grid[lx][ly]++;
        grid[lx][ry]--;
        grid[rx][ly]--;
        grid[rx][ry]++;
    }

    // 横方向の累積和
    rep(i, 0, 1000){
        rep(j, 0, 1000){
            if(j == 0){
                acc[i][j] = grid[i][j];
            } else{
                acc[i][j] = acc[i][j - 1] + grid[i][j];
            }
        }
    }
    // 縦方向の累積和
    rep(j, 0, 1000){
        rep(i, 1, 1000){
            acc[i][j] += acc[i - 1][j];
        }
    }

    i32 ans[N + 1] = {0};
    rep(i, 0, 1000){
        rep(j, 0, 1000){
            ans[acc[i][j]]++;
        }
    }

    rep(i, 1, N){
        cout << ans[i] << endl;
    }

    return(0);
}
