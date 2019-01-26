#include "rational.h"
#include <iostream>

using namespace std;

rational::rational() { //CTOR
//    _num = 1;
//    _denom = 1;
    _error = false;
}
rational::rational(int num, int denom) { //CTOR
    _num = num;
    _denom = denom;
    _error = false;
    if (_denom==0)
        _error = true;
    else
        _error = false;
}
rational rational::inverse() {
    int new_num = _denom;
    int new_denom = _num;
    rational local(new_num, new_denom);
    return local;
}

rational operator +(const rational& left,
                    const rational& right) { //Add
    rational sum;
    sum._num = (left._num*right._denom)+(right._num*left._denom);
    sum._denom = left._denom*right._denom;
    rational local(sum._num, sum._denom);
    return local;
}
rational operator -(const rational& left,
                    const rational& right) { //Subtract
    rational diff;
    diff._num = (left._num*right._denom)-(right._num*left._denom);
    diff._denom = left._denom*right._denom;
    rational local(diff._num, diff._denom);
    return local;
}
rational operator *(const rational& left,
                    const rational& right) { //Multiply
    rational product;
    product._num = left._num * right._num;
    product._denom = left._denom * right._denom;
    rational local(product._num, product._denom);
    return local;
}
rational operator /(const rational& left,
                    const rational& right) { //Divide
    rational quotient;
    quotient._num = left._num * right._denom;
    quotient._denom = left._denom * right._num;
    rational local(quotient._num, quotient._denom);
    return local;
}

bool operator <(const rational& left,
                const rational& right) {   //Lesser
    int new_left, new_right;
    new_left = left._num * right._denom;
    new_right = left._denom * right._num;
    if (new_left < new_right)
        return true;
    else
        return false;
}
bool operator >(const rational& left,
                const rational& right) {     //Greater
    int new_left, new_right;
    new_left = left._num * right._denom;
    new_right = left._denom * right._num;
    if (new_left > new_right)
        return true;
    else
        return false;
}
bool operator ==(const rational& left,
                 const rational& right) { //Equal
    int new_left, new_right;
    new_left = left._num * right._denom;
    new_right = left._denom * right._num;
    if (new_left == new_right) {
        return true;
    }
}

ostream& operator <<(ostream& outstream,
                     const rational& print) {
    if (print._error)
        outstream<<" E R R O R "; //should be never seen!
    else
        outstream<<print._num<<"/"<<print._denom;
    return outstream;
}
istream& operator >>(istream& instream,
                     rational& give_me) {
    char slash;
    cin>>give_me._num>>slash>>give_me._denom;
    if (give_me._denom == 0)
        give_me._error = true;
    else
        give_me._error = false;
    return instream;
}
void rational::show() {
    cout<<_num<<"/"<<_denom;
}
void rational::input() {
    char slash;
    cin>>_num>>slash>>_denom;
    if (_denom == 0) {
        _error = true;
        cout<<" E R R O R "; //should never be seen
    }
    else
        _error = false;
}
//Reset button so I can still use program
//even after inputting fraction with 0 denom
void rational::reset() {
    _num = 1;
    _denom = 1;
    _error = false;
}

bool rational::error() {
    return _error;
}







