#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_greater_than_5(int value) {
    return (value > 5);
}

void printnumber(int y) {
    cout << y << endl;
}

// based on http://www.drdobbs.com/cpp/lambdas-in-c11/240168241?pgno=2
int main() {
    vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };

    for_each(numbers.begin(), numbers.end(), printnumber);

    cout << "*********************" << endl;

/*
    auto greater_than_5_count = count_if(numbers.begin(), numbers.end(), is_greater_than_5);

    cout << "The number of elements greater than 5 is: "
        << greater_than_5_count << "." << endl;

    auto divisor = 3;
    // here we make two changes: (i) include the lambda directly, (ii) capture an outside variable
    for_each(numbers.begin(), numbers.end(), [divisor] (int y) {
            if (y % divisor == 0) {
                cout << y << endl;
            }});


*/
    numbers.erase(remove_if(numbers.begin(), numbers.end(), [=] (int y) {
        return(y < 10);
    }), numbers.end());

    for_each(numbers.begin(), numbers.end(), printnumber);

    return 0;
}
