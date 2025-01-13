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

typedef pair<int16_t, int16_t> pi16;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i16 C, P;
    vector<pi16> students(N + 1);
    rep(i, 1, N){
        cin >> C >> P;
        students[i] = make_pair(C, P);
    }

    i32 acc1[N + 1] = {0};
    i32 acc2[N + 1] = {0};

    rep(i, 1, N){
        i16 class_ = students[i].first;
        i16 point = students[i].second;

        if(class_ == 1){
            acc1[i] = acc1[i - 1] + point;
            acc2[i] = acc2[i - 1];
        } else{
            acc1[i] = acc1[i - 1];
            acc2[i] = acc2[i - 1] + point;
        }
    }

    i32 Q;
    cin >> Q;

    i32 L, R;
    rep(i, 1, Q){
        cin >> L >> R;
        printf("%d %d\n", acc1[R] - acc1[L - 1], acc2[R] - acc2[L - 1]);
    }

    return(0);
}
