#include <iostream>
#include <string>

using namespace std;
using LL = long long;

struct Fraction {
    LL up, down;
};

Fraction first, second, consuqence;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void printFraction(Fraction f) {
    f.up = abs(f.up);
    LL d = 1;
    if(f.up != 0)
        d = gcd(f.up, f.down);
    if (f.up % f.down == 0) {
        cout << f.up / f.down;
    } else if (f.up < f.down) {
        cout << f.up / d << "/" << f.down / d; 
    } else {
        cout << f.up / f.down << " " << f.up % f.down / d << "/" << f.down / d;
    }
}

Fraction format(Fraction f) {
    // format : -a / b
    if (f.down < 0) {
        f.down = -f.down;
        f.up = -f.up;
    }
    return f;
}

void formatPrint(const Fraction &f) {
    Fraction t = format(f);
    if (t.up >= 0) {
        printFraction(t);
    } else {
        cout << "(-";
        printFraction(t);
        cout << ")";
    }
}

void printfEquation(string &&op) {
    formatPrint(first);
    cout << op; 
    formatPrint(second);
    cout << " = ";
}

int main() {
    scanf("%lld/%lld %lld/%lld", &first.up, &first.down, &second.up, &second.down);
    
    // +
    printfEquation(" + ");
    consuqence.up = first.up * second.down + first.down * second.up;
    consuqence.down = first.down * second.down;
    formatPrint(consuqence);
    cout << endl;

    // -
    printfEquation(" - ");
    consuqence.up = first.up * second.down - first.down * second.up;
    formatPrint(consuqence);
    cout << endl;

    // *
    printfEquation(" * ");
    consuqence.up = first.up * second.up;
    formatPrint(consuqence);
    cout << endl;

    // /
    printfEquation(" / ");
    if (second.up == 0) {
        cout << "Inf";
    } else {
        consuqence.up = first.up * second.down;
        consuqence.down = first.down * second.up;
        formatPrint(consuqence);
    }
    return 0;
}
