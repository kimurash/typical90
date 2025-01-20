// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MOD 100'000

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

i32 calc_digit_sum(i32 n);

int main(){
    cin.tie(nullptr);

    i32 N;
    i64 K;
    cin >> N >> K;

    i32 next[MOD];
    i32 time[MOD];
    bool visited[MOD];
    rep(i, 0, MOD - 1){
        visited[i] = false;
    }

    i32 cnt = 0;
    i32 x, y, z;
    x = N;
    time[x] = cnt;
    visited[x] = true;

    while(true){
        y = calc_digit_sum(x);
        z = (x + y) % MOD;
        if(visited[z]){
            break;
        }
        next[x] = z;

        x = z;
        visited[z] = true;
        
        cnt++;
        time[z] = cnt;
    }

    if(time[z] <= K){
        i32 cycle = time[x] - time[z] + 1;
        K = (K - time[z]) % cycle + time[z];
    }

    i32 ans = N;
    rep(i, 1, K){
        ans = next[ans];
    }
    cout << ans << endl;

    return(0);
}

i32 calc_digit_sum(i32 n){
    i32 sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return(sum);
}
