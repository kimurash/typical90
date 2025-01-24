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

i16 si, sj;
i32 ans;

i16 di[] = {0, 1, 0, -1};
i16 dj[] = {1, 0, -1, 0};

char grid[20][20];
bool visited[20][20];

void dfs(i32 i, i32 j, i32 depth);

int main(){
    cin.tie(nullptr);

    i16 H, W;
    cin >> H >> W;

    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            if(i == 0 || i == H + 1 || j == 0 || j == W + 1){
                grid[i][j] = '#';
            } else{
                cin >> grid[i][j];
            }
        }
    }

    ans = 0;

    rep(i, 1, H){
        rep(j, 1, W){
            if(grid[i][j] == '.'){
                si = i;
                sj = j;
                dfs(i, j, 0);
            }
        }
    }

    if(ans == 0){
        cout << -1 << endl;
    } else{
        cout << ans << endl;
    }

    return(0);
}

void dfs(i32 i, i32 j, i32 depth){
    visited[i][j] = true;

    rep(d, 0, 3){
        i32 ni = i + di[d];
        i32 nj = j + dj[d];
        
        if(ni == si && nj == sj && 3 <= depth){
            ans = max(ans, depth + 1);
            continue;
        }

        if(grid[ni][nj] == '.' && !visited[ni][nj]){
            dfs(ni, nj, depth + 1);
        }
    }

    visited[i][j] = false;

    return;
}
