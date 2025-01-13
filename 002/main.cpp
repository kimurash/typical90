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

bool is_dyck(string s);

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    for(int i = 0; i < (1 << N); i++){
        bitset<20> bs(i);
        string s(N, ' ');

        for(int j = 0; j < N; j++){
            if(bs.test(N - 1 - j)) {
                s[j] = ')';
            } else{
                s[j] = '(';
            }
        }

        if(is_dyck(s)){
            cout << s << endl;
        }
    }

    return(0);
}

bool is_dyck(string s){
    stack<char> st;

    for(char c : s){
        if(c == '('){
            st.push(c);
        } else{
            if(st.empty()){
                return false;
            } else{
                st.pop();
            }
        }
    }

    return st.empty();
}
