// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 100'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

i32 cnt0 = 0;
i32 cnt1 = 0;

i16 color[MAX];
vi32 G[MAX];

void dfs(int32_t node, i16 cur);

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 A, B;
    rep(i, 1, N - 1){
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    rep(i, 1, N){
        color[i] = -1;
    }

    dfs(1, 0);

    i32 g = cnt0 < cnt1 ? 1 : 0;

    bool first = true;
    i32 cnt = 0;
    rep(i, 1, N){
        if(color[i] == g){
            if(first){
                cout << i;
                first = false;
            } else{
                cout << " " << i;
            }

            cnt++;
            if(N / 2 <= cnt){
                break;
            }
        }
    }
    cout << endl;

    return(0);
}

void dfs(int32_t node, i16 cur){
    color[node] = cur;
    if(cur == 0){
        cnt0++;
    } else{
        cnt1++;
    }

    for(int32_t adj : G[node]){
        if(color[adj] == -1){
            dfs(adj, 1 - cur);
        }
    }

    return;
}
