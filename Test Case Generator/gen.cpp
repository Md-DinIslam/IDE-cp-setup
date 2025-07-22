// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxN = 1e18;
// random number in range between a to b....
int getRandInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

ll getRand(ll a, ll b) {
    static std::random_device rd;  // Seed
    static std::mt19937_64 gen(rd());  // 64-bit Mersenne Twister generator

    std::uniform_int_distribution<ll> dis(a, b);
    return dis(gen);
}

int main(int argc, char* argv[]) {
    // atoi(s) converts an array of chars to int
    srand(atoi(argv[1]));
    int t = 1;
    // cout << t << '\n';
    int n = getRand(10000, 100000);
    int m = getRand(10000, 100000);
    n = 100;
    m = 100000;
    // int q = getRand(1, 10);

    // int q = getRand(1, 10);
    // int n = 1000;
    // printf("%d\n", n);
    // cout << n << " " << q << "\n";
    // cout << n << " " << m << '\n';
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        ll x = getRand(mxN - 10, mxN);
        ll y = getRand(mxN - 10, mxN);
        x = i;
        y = mxN;
        cout << x << " " << y << "\n";
    }

    // for (int i = 1; i <= m; ++i) {
    //     int x = getRand(1, mxN);
    //     cout << x << " \n"[i == m];
    // }
    // set<ll> used;
    // for (int i = 0; i < n; ++i) {
    //     ll x;
    //     do {
    //         // x = getRand(1, n);
    //         x = getRand(9999999999999999, 1000000000000000000);
    //     } while (used.count(x));
    //     // cout << x << " " << x << '\n';
    //     v[i] = x;
    // }

    // for (auto &x : v) {
    //     cout << x << " ";
    // }
    // cout << '\n';
    // used.clear();
    // cout << q << '\n';
    // for (int i = 0; i < q; ++i) {
    //     int tp = getRand(0, 1);
    //     int a = getRand(1, n);
    //     int b = getRand(1, n);
    //     if (tp == 1) {
    //         b = getRand(a, n);
    //     }
    //     cout << tp << " " << a << " " << b << '\n';
    // }

    // cout << "\n";
    // set<pair<int, int>> used2;
    // for (int i = 0; i < q; ++i) {
    //     int lb, rb;
    //     do {
    //         lb = getRand(1, 10);
    //         rb = getRand(lb, 10);
    //     } while (used2.count({lb, rb}));

    //     cout << lb << " " << rb << '\n';
    //     used2.insert({lb, rb});
    // }
    // // puts("");
    // cout << "\n";
}
