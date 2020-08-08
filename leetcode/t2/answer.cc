#include <vector>
#include <iostream>
#include <cmath>

#include <string>
#include <algorithm>
using namespace std;


class Answer {
public:
    
    int reverse(int x);
};

int Answer::reverse(int x) {
    long ret = 0;
    short eve[32] = {0};//every number
    bool p = true;
    int i = 0, j = 0, num = 0;

    //if negative, change it to positive
    if (x < 0) {
        p = false;
        x = -x;
    }

    //get every number divided by 10, 100,
    while (x > 0) {
        eve[i] = x % 10;
        cout << "eve: " << eve[i] << endl;
        x = x / 10;
        i++;
    }
    num = i;
    cout << i << endl;
    
    while (i) {
        cout << eve[i-1] * pow(10, num-i) << endl;
        ret += eve[i-1] * pow(10, num-i);
        cout << "ret: " << ret << endl;
        i--; 
        
    }
    if (p == false) {
        ret = -ret;
    }

    if (ret < -pow(2, 31) || ret > (pow(2, 31) - 1)) {
        cout << "in the wrong range" << endl;
        return 0;
    }
    cout << "ret: " << ret << endl;
    
    return (int)ret;
}
class Answer_o {
    public:
        int reverse_int(int c);
};

int Answer_o:: reverse_int(int c) {
    long ret = 0;
    string tmp((to_string(c)));
    cout << "tmp string: " << tmp << endl;
    std::reverse(tmp.begin(), tmp.end());
    cout << "reverse tmp string: " << tmp << endl;
    
    ret = stol(tmp);
    cout << "return int: " << ret << endl;

    if (ret < -pow(2, 31) || ret > (pow(2, 31) - 1)) {
        cout << "in the wrong range" << endl;
        ret = 0;;
    }
    return ret;
}

int main(void)
{
    cout << "hello world" << endl;
#if 0 //method1
    Answer a;
    int number = 2147483648;
    cout << "input number: " << number << endl;

    a.reverse(number);
#endif
#if 1 //method2
    Answer_o a;
    int number = 12345678;
    cout << "input number: " << number << endl;
    
    a.reverse_int(number);
#endif
    return 0;
}
