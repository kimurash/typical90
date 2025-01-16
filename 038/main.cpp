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

// #defineではWA
const i64 INF = 1e18;

int main(){
    cin.tie(nullptr);

    i64 A, B;
    cin >> A >> B;

    i64 g = gcd(A, B);
    
    if(A / g > INF / B){
        cout << "Large" << endl;
    }else{
        cout << (A / g) * B << endl;
    }

    return(0);
}
