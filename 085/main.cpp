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

    i64 K;
    cin >> K;

    vi64 div;
    for(i64 i = 1; i * i <= K; i++){
        if(K % i == 0){
            div.push_back(i);
            if(i * i != K){
                div.push_back(K / i);
            }
        }
    }

    sort(all(div));

    i64 ans = 0;
    size_t N = div.size();
    rep(i, 0, N - 1){
        rep(j, i, N - 1){
            i64 a = div[i];
            i64 b = div[j];

            if(a * b == 0){
                continue;
            }

            if(K % (a * b) == 0){
                i64 c = K / (a * b);
                if(b <= c){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return(0);
}
