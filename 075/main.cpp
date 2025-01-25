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

    i64 N;
    cin >> N;

    i32 sum = 0;
    for(i64 p = 2; p * p <= N; p++){
        i32 cnt = 0;
        while(N % p == 0){
            N /= p;
            cnt++;
        }
        sum += cnt;
    }

    if(N != 1){
        sum++;
    }

    if(sum == 0){
        cout << 0 << endl;
    } else{
        i64 ans = ceil(log2(sum));
        cout << ans << endl;
    }

    return(0);
}
