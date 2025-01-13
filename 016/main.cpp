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

    i32 N;
    cin >> N;

    i64 A, B, C;
    cin >> A >> B >> C;

    i32 ans = 10000;
    rep(i, 0, 10000){
        rep(j, 0, 10000){
            i64 sum = A * i + B * j;
            if(N < sum){
                break;
            }
            
            if((N - sum) % C == 0){
                i32 cnt = i + j + (N - sum) / C;
                ans = min(ans, cnt);
            }
        }
    }

    cout << ans << endl;
    return(0);
}
