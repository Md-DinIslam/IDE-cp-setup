// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

// random number in range between a to b....
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

char randChar() {
    int choice = 1;
    if (choice == 0) {
        return 'A' + rand() % 26;
    }
    else {
        return 'a' + rand() % 26;
    }
}

void query(int n, int q) {
    // cout << "\n";
    set<pair<int, int>> used2;
    for (int i = 0; i < q; ++i) {
        int lb, rb;
        do {
            lb = rand(1, n);
            rb = rand(lb, n);
        } while (used2.count({lb, rb}));

        cout << lb << " " << rb;
        if (i < q - 1)
            cout << "\n";
        used2.insert({lb, rb});
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // atoi(s) converts an array of chars to int
    srand(atoi(argv[1]));
    // int t = rand(1, 100);
    int n = 100000;
    int q = 100000;
    // int n = 1000;
    // printf("%d\n", n);
    cout << n << " " << q << "\n";
    // cout << t << '\n';
    // for (int i = 1; i <= t; ++i) {
    set<char> used;
    string s = "";
    
    for (int i = 0; i < n; ++i) {
        s.push_back(randChar());
        // int x = rand(0, 52);
        // s.push_back(x + '0');
        // do {
        //     x = rand(0, 25);
        // } while (used.count(x));
        // printf("%d ", x);
        // cout << char(x + 'a');

        // used.insert(x);
    }
    cout << s << '\n';
    for (int i = 1; i <= q; ++i) {
        // int lb = rand()
        int rb = rand(i, n);
        cout << 1 << " " << rb << "\n";
    }
    // query(n, q);
    // puts("");
    // cout << "\n";
    // }
}
