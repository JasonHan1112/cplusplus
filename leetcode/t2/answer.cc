#include <vector>
#include <iostream>
#include <cmath>
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

int main(void)
{
    cout << "hello world" << endl;
    Answer a;
    int number = 2147483648;
    cout << "input number: " << number << endl;

    a.reverse(number);
    return 0;
}
