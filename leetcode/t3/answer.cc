#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Answer {
    public:
        bool isPalindrome(int x);
};

bool Answer::isPalindrome(int x) {
    string tmp(to_string(x));
    long rev = 0;
    reverse(tmp.begin(), tmp.end());

    rev = stol(tmp);
    if (rev == x) {
        cout << x << "是回文数字" << endl;
        return true;
    }
    return false;

}

int main (void)
{
    Answer a;
    //int test = 123321;
    int test = 3321;
    a.isPalindrome(test);

    return 0;
}