#include <iostream>
#include <math.h>
#include <fplus/fplus.hpp>


using namespace std;

bool is_odd_int(int x) { return x % 2 == 1; }
int mod3(int x) {return x % 3;}

int main()
{
    cout << "Hello World!" << endl;

    auto xs = fplus::numbers<int>(1, 10);

    auto odds = fplus::keep_if(is_odd_int, xs);
    for(auto e: odds) {
        cout << e << endl;
    }

    auto idxs = fplus::find_all_idxs_by(is_odd_int, xs);
    for(auto e: idxs) {
        cout << e << endl;
    }

    auto vals = fplus::group_globally_on(mod3, xs);
    for(auto e: vals) {
        for(auto f: e) {
            cout << f << " ";
        }
        cout << endl;
    }

     return 0;
}
