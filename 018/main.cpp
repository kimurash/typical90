// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define PI 3.14159265358979323846

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    double T;
    cin >> T;

    double L, X, Y;
    cin >> L >> X >> Y;

    i32 Q;
    cin >> Q;

    rep(i, 1, Q){
        double E;
        cin >> E;

        double theta = (E / T) * 2.0 * PI;
        double radius = L / 2.0;
        
        double y = -radius * sin(theta);
        double z = radius - radius * cos(theta);

        double dx = sqrt(X * X + (Y - y) * (Y - y));
        double dy = z;

        double ans = atan2(dy, dx) * 180.0 / PI;
        cout << fixed << setprecision(12) << ans << endl;
    }

    return(0);
}
