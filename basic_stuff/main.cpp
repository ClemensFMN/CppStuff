#include <iostream>
#include <tuple>
#include <array>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct rslt {
    int res;
    int cnt;
};

int my_gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        my_gcd(b, a%b);
}

int my_gcd_it(const int a, const int b) {
    int u = a;
    int v = b;
    while(v != 0) {
        int temp = u;
        u = v;
        v = temp % v;
    }
    return(u);
}

// no const in the parameters -> we can change a & b (locally) -> function becomes simpler
int my_gcd_it_2(int a, int b) {
    while(b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return(a);
}


tuple <int, int> my_gcd_it_cnt(int a, int b) {
    int cnt = 0;
    while(b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
        cnt++;
    }
    tuple <int,int> res = make_tuple(a, cnt);
    return(res);
}

rslt my_gcd_it_cnt_2(int a, int b) {
    int cnt = 0;
    while(b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
        cnt++;
    }
    rslt r = {a, cnt};
    //r.cnt = cnt;
    //r.res = a;
    return(r);
}

// function with two return arguments - not ideal!
void f1(const int x, int& y, int&z) {
    y = 2*x;
    z = x+1;
}

// even more crazy - use a reference for input & output
void f2(int &x) {
    x = 2*x;
}


int main()
{
    cout << "Hello World!" << endl;
    cout << my_gcd(10,7) << "..." << my_gcd_it_2(10, 7) << endl;
    cout << my_gcd(21,6) << "..." << my_gcd_it_2(21,6) << endl;

    //tuple <int,int> res = my_gcd_it_cnt(21,6);
    auto res = my_gcd_it_cnt(21,6);
    cout << get<0>(res) << "..." << get<1>(res) << endl;

    auto res2 = my_gcd_it_cnt_2(21,6);
    cout << res2.res << "..." << res2.cnt << endl;

    int x = 2;
    int y, z;
    f1(x,y,z);
    cout << y << "..." << z << endl;

    f2(x);
    cout << x << endl;

    auto myarr = std::array<int, 10>({1,2,3,4,5,6,7,8,9});
    myarr[5] = 100;
    for(auto elem:myarr) {
        cout << elem << endl;
    }

    auto it = find(myarr.begin(), myarr.end(), 2);
    int index = distance(myarr.begin(), it);
    cout << "Index: " << index << endl;

    it = find_if(myarr.begin(), myarr.end(), [](const int & val) {
                 if(val % 3 == 0)
                     return true;
                 return false;});

    index = distance(myarr.begin(), it);
    cout << "Index: " << index << endl;

    map <string, int> occ;
    occ["susi"] += 1;
    occ["peter"] = 10;
    for(auto [key, val]:occ) {
        cout << key << "..." << val << endl;
    }

    return 0;
}
