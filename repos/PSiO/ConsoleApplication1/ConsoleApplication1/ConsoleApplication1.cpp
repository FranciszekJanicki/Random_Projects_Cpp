#include "Rational.h"

int main() {
    Rational quarter(1, 4);
    Rational one_third(1, 3);

    Rational add_result, sub_result, multi_result;
    /*add_result = one_third.add(quarter);
    sub_result = one_third.subtract(quarter);
    */

    add_result = one_third + quarter;
    sub_result = one_third - quarter;
    multi_result = one_third * quarter;

    cout << one_third << " + " << quarter << " = " << add_result << endl;
    cout << one_third << " - " << quarter << " = " << sub_result << endl;
    cout << one_third << " * " << quarter << " = " << multi_result << endl;

    Rational cinResult;
    cin >> cinResult;
    cout << cinResult;

    Rational p = one_third / quarter;
    cout << p;

    return 0;
}
