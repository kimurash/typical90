// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 1009
#define INF 1e9

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef struct state{
    i16 i;
    i16 j;
    i32 dir;
} State;

char grid[MAX][MAX];
i32 dist[MAX][MAX][4];

i16 di[] = {0, 1, 0, -1};
i16 dj[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);

    i16 H, W;
    cin >> H >> W;

    i16 rs, cs;
    cin >> rs >> cs;

    i16 rt, ct;
    cin >> rt >> ct;

    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            if(i == 0 || i == H + 1 || j == 0 || j == W + 1){
                grid[i][j] = '#';
            } else {
                cin >> grid[i][j];
            }
            rep(d, 0, 3){
                dist[i][j][d] = INF;
            }
        }
    }

    deque<State> yet;
    rep(d, 0, 3){
        yet.push_back({rs, cs, d});
        dist[rs][cs][d] = 0;
    }
    
    while(!yet.empty()){
        State state = yet.front();
        yet.pop_front();

        rep(d, 0, 3){
            i16 ni = state.i + di[d];
            i16 nj = state.j + dj[d];
            if(grid[ni][nj] == '#'){
                continue;
            }

            i32 nd = dist[state.i][state.j][state.dir] + (state.dir != d);
            if(nd < dist[ni][nj][d]){
                dist[ni][nj][d] = nd;
                State ns = {ni, nj, d};
                // 方向転換の回数が少ない経路を優先的に探索する
                if(state.dir == d){
                    yet.push_front(ns);
                } else {
                    yet.push_back(ns);
                }
            }
        }
    }

    i32 ans = INF;
    rep(d, 0, 3){
        ans = min(ans, dist[rt][ct][d]);
    }
    cout << ans << endl;

    return(0);
}
