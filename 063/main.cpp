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

    i32 H, W;
    cin >> H >> W;

    i32 grid[H][W];
    rep(i, 0, H - 1){
        rep(j, 0, W - 1){
            cin >> grid[i][j];
        }
    }

    i32 ans = 1;
    for(int n = 1; n < (1 << H); n++){
        bitset<8> bs(n);
        
        vector<i32> row;
        for(int i = 0; i < 8; i++){
            if(bs.test(i)) {
                row.push_back(i);
            }
        }

        map<i32, i32> mp;
        rep(j, 0, W - 1){
            bool same = true;
            rep(k, 1, row.size() - 1){
                i32 i1 = row[k - 1];
                i32 i2 = row[k];
                if(grid[i1][j] != grid[i2][j]){
                    same = false;
                    break;
                }
            }
            if(same){
                i32 P = grid[row[0]][j];
                mp[P] += row.size();
                ans = max(ans, mp[P]);
            }
        }
    }

    cout << ans << endl;

    return(0);
}
