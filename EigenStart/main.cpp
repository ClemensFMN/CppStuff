#include <iostream>
#include <Eigen/Dense>


using namespace std;
using namespace Eigen;


int main()
{
    cout << "Hello World!" << endl;

    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    cout << m << endl;

    auto m2 = m + m.transpose();

    auto es = m2.eigenvalues();
    cout << es << endl;

    VectorXd v(2);
    v << 1 , 2;
    cout << v << endl;

    auto r = m*v;
    cout << r << endl;

    return 0;
}
