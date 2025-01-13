// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 100009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, int32_t> pi32;

vector<i32> G[MAX];

pi32 bfs(i32 N, i32 start);

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

    pi32 p1 = bfs(N, 1);
    pi32 p2 = bfs(N, p1.first);

    cout << p2.second + 1 << endl;

    return(0);
}

pi32 bfs(i32 N, i32 start){
    i32 dist[N + 1];
    rep(i, 1, N){
        dist[i] = -1;
    }

    queue<int32_t> yet;
    yet.push(start);
    dist[start] = 0;

    i32 maxv = start;
    i32 maxd = 0;
    
    while(!yet.empty()){
        int32_t now = yet.front();
        yet.pop();
    
        for(int32_t adj: G[now]){
            if(dist[adj] == -1){
                dist[adj] = dist[now] + 1;
                yet.push(adj);

                if(maxd < dist[adj]){
                    maxd = dist[adj];
                    maxv = adj;
                }
            }
        }
    }

    return make_pair(maxv, maxd);
}
