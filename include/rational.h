#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;


class rational
{
public:
    //cto
    rational();
    rational(int num, int denom);

    //input and show are not really needed
    //because of ostream and istream
    void input();
    void show();

    void reset();
    bool error();
    rational inverse();

    //operators
    friend rational operator + (const rational& left,
                                const rational& right); //Add
    friend rational operator - (const rational& left,
                                const rational& right); //Subtract
    friend rational operator * (const rational& left,
                                const rational& right); //Multiply
    friend rational operator / (const rational& left,
                                const rational& right); //Divide

    friend bool operator <(const rational& left,
                            const rational& right);     //Less
    friend bool operator >(const rational& left,
                            const rational& right);     //Greater
    friend bool operator ==(const rational& left,
                            const rational& right);     //Equal

    friend ostream& operator <<(ostream& outstream,
                               const rational& print);
    friend istream& operator >>(istream& instream,
                                rational& give_me);

private:
    //member variables
    int _num, _denom;
    bool _error;

};

#endif // RATIONAL_H
