#include<iostream> 
using namespace std; 
class Fruit {
    public:
        int i;

        Fruit() {
		    cout << "Fruit constructor" << this << endl; 
        }
        ~Fruit() {
		    cout << "Fruit deconstructor" << this << endl; 
        }
        virtual int fruit_virtual(void) {
            cout << "in fruit vitual";
            return 0;
        }
        int same(void) {
            cout << "in fruit same;\n";
        }
};

class Apple : public Fruit { 
public: 
	static int s; 
	int a; 
	
	Apple() {
		cout << "Apple constructor" << this << endl; 
	} 
    ~Apple() {
        cout << "Apple deconstructor" << this << endl;
    }
    int fruit_virtual(void) {
        cout << "in fruit virtual but in apple\n";
        return 0;
    }
    static int test_static(void) {
        cout << "this is static function in a class\n";
        return 0;
    }
    int same(void) {
        cout << "in apple same;\n";
    }
    int same(int a) {
        cout << "in apple same with input;\n";
    }
}; 
int Apple::s = 3;
class A
{
    public:
        char b;
        //virtual void fun() {};
        //virtual void fun1() {};
        //virtual void fun2() {};
        virtual void fun3() {};
        virtual void fun4() {};
        int c;
        static int d;
        static int f;
};



int main() 
{ 
    Apple obj1; 
    Apple obj2; 
    Apple::s = 4;
    obj1.test_static();
    Apple::test_static();
    {
        static  Apple obj3;
        obj3.test_static();
    }
    cout << "end of test1\n";
    
    Apple obj4;
    obj4.a = 4;
    Fruit* f = &obj4;
    f->fruit_virtual();
    cout << "end of test2\n";
    
    A a();
    cout << "size of class: " << sizeof(A) << endl;
    cout << "end of test3\n";
    Apple obj5;
    Apple* a1;
    Fruit f2;
    Fruit* f1 = &obj5;
    //f1->same(3);
    //a1 = &f2;
    a1->same();
    //obj5.same(3);
    cout << "end of main\n";
    return 0;
} 
