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
    string S;
    cin >> N >> S;

    i32 r = -1;

    i32 cnto = 0;
    i32 cntx = 0;

    i64 ans = 0;
    rep(l, 0, N - 1){
        while(r < N && (cnto <= 0 || cntx <= 0)){
            r++;
            if(S[r] == 'o'){
                cnto++;
            } else if(S[r] == 'x'){
                cntx++;
            }
        }

        ans += N - r;

        if(S[l] == 'o'){
            cnto--;
        } else if(S[l] == 'x'){
            cntx--;
        }
    }

    cout << ans << endl;

    return(0);
}
