#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

long long get_decimal(string num, long long radix) {
    long long sum = 0, t = 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        if (num[i] > '9')
           // num[i] -= ('a' + 10); //logic error
            num[i] -= ('a' - 10);
        else
            num[i] -= '0';
        sum += (long long)num[i] * t;
        if(sum < 0) return -1;
        t *= radix;
    }
    return sum;
}

int get_radix(string n1, long long radix, string n2) {
    long long cmp_num = get_decimal(n1, radix);
    char max_c = *max_element(n2.begin(), n2.end());
    long long low, high, temp, mid;
    low = (isdigit(max_c) ? max_c - '0' : max_c - 'a' + 10) + 1;
    high = max(low, cmp_num);
    while (low <= high) {
        mid = (low + high) / 2;
        temp = get_decimal(n2, mid);
        if (temp == cmp_num) {
           return mid; 
        } else if (temp < 0 || temp > cmp_num) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    string num1, num2;
    long long tag, ans, radix;
    cin >> num1 >> num2 >> tag >> radix;
    if (tag == 1) {
        ans = get_radix(num1, radix, num2);
    } else {
        ans = get_radix(num2, radix, num1);
    }
    if (ans == -1) {
        cout << "Impossible";
    } else {
        cout << ans;
    }
    return 0;
}
