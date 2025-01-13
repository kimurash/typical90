// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 2009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

class UnionFind{
public:
    // 各頂点の親
    vi32 parent;
    // 各頂点を根とする木の頂点数
    vi32 size;

    // 頂点xの根を求める
    int32_t root(int32_t x){
        while(parent[x] != -1){
            x = parent[x];
        }
        return(x);
    }
    
    UnionFind(int32_t N){
        this->parent.resize(N + 1);
        this->size.resize(N + 1);

        rep(i, 1, N){
            // 最初は親がない
            this->parent[i] = -1;
            // 最初はグループの頂点数が1
            this->size[i] = 1;
        }
    }

    // 節uと節vが属するグループを統合する
    void unite(int32_t u, int32_t v){
        int32_t rootu = this->root(u);
        int32_t rootv = this->root(v);
        if(rootu == rootv){
            return;
        } else{
            if(this->size[rootu] < this->size[rootv]){
                this->parent[rootu] = rootv;
                this->size[rootv] += this->size[rootu];
            } else{
                this->parent[rootv] = rootu;
                this->size[rootu] += this->size[rootv];
            }
        }
    }

    // 節uと節vが同一のグループか判定する
    bool same(int32_t u, int32_t v){
        int32_t rootu = this->root(u);
        int32_t rootv = this->root(v);
        return(rootu == rootv);
    }
};

i32 di[] = {0, 1, 0, -1};
i32 dj[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);

    i32 H, W;
    cin >> H >> W;

    char grid[H + 2][W + 2];
    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            grid[i][j] = '#';
        }
    }

    UnionFind uf((H + 1) * (W + 1) + 1);

    i32 Q;
    cin >> Q;

    rep(i, 1, Q){
        i32 t;
        cin >> t;

        if(t == 1){
            i32 r, c;
            cin >> r >> c;

            grid[r][c] = '.';

            rep(d, 0, 3){
                i32 ni = r + di[d];
                i32 nj = c + dj[d];
                if(grid[ni][nj] == '.'){
                    uf.unite(r * W + c, ni * W + nj);
                }
            }
        } else if(t == 2){
            i32 ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            
            if(grid[ra][ca] == '#'){
                cout << "No" << endl;
            } else if(grid[rb][cb] == '#'){
                cout << "No" << endl;
            } else if(uf.same(ra * W + ca, rb * W + cb)){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        }
    }

    return(0);
}
