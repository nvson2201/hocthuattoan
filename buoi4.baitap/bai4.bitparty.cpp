#include <bits/stdc++.h>
#include<math.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-6;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

struct Cash {
    long long int M;
    long long int S;
    long long int P;
};

bool check(long long int t, long long int C , long long int B, long long int R, vector<Cash> cashier){

    long long int count = 0;
    long long int K[C];


    for (long long int i = 0; i < C;i++) {
        K[i] = (long long int)min(cashier[i].M, (t-cashier[i].P)/cashier[i].S);
    }

    // Sắp xếp để có số lượng bits được cho vào nhiều nhất trong khoảng thời gian t đối
    // với mỗi cashier.
    sort(K, K+C, std::greater<long long int>());

    for (long long int i = 0; i < R;i++) {    
        // Cộng dồn các lượng tối ưu bits này của mỗi robot-cashier 
        // nếu lượng này lớn hơn hoặc bằng B thì thỏa 'mid' này thỏa mãn, tiêp tục tìm.
        count += K[i];
        if(count >= B) {
            return true;
        }
    }

    return false;
}

long long int Findt(long long int C , long long int B, long long int R, vector<Cash> cashier){

    long long int L = 0, Right = 7000000000000000000;

    while(L < Right){
        long long int mid = L + (Right-L) / 2;
        if(check(mid, C, B, R, cashier)){
            Right = mid;
        }
        else L = mid + 1;
    }
    return Right;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // freopen("inputbai4.txt", "r", stdin);
    // freopen("outputbai4.txt", "w", stdout);

    int testCase;
    cin >> testCase;
    
    for (int t = 1; t <= testCase; t++) {
        vector<Cash> Cashiers;
        long long int R,B,C;
        cin >> R >> B >> C;
        for(long long int j = 0; j < C; j++) {
            long long int Mj, Sj, Pj;
            cin >> Mj >> Sj >> Pj;
            Cashiers.push_back(Cash{Mj,Sj,Pj});
        }
        
        cout << "Case #" << t  << ": " << Findt(C, B, R, Cashiers) << "\n";
    }

}
