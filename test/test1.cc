#include <iostream> 
#include <memory>
#include <deque>
#include <queue>
#include <thread>
#include <chrono>

using namespace std; 
class Apple;
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

class Fruit {
    public:
        int i;
        shared_ptr <int> f_sp;
        shared_ptr <Apple> f_scp;
        weak_ptr <Apple> w_p;
        array<int, 10> f_array;

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
    shared_ptr <int> a_sp;
    shared_ptr <Fruit> a_scp;
    weak_ptr <Fruit> w_p;
    array<int, 10> a_array;
	
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



void hello_thread(void) {
    string name("world");
    this_thread::sleep_for(chrono::seconds(3));
    cout << "hello " << name << endl;
    return;
}
int main() 
{ 
    #if 0
    cout << "######start of test 1######\n"; 
    Apple obj1; 
    Apple obj2; 
    Apple::s = 4;
    obj1.test_static();
    Apple::test_static();
    {
        static  Apple obj3;
        obj3.test_static();
    }
    cout << "######end of test 1######\n"; //test class static member
    #endif
    #if 0
    cout << "######start of test 2######\n"; 
    Apple obj4;
    obj4.a = 4;
    Fruit* f = &obj4;
    f->fruit_virtual();
    cout << "######end of test 2######\n"; //test polymorphism
    #endif
    #if 0
    cout << "######start of test 3######\n"; 
    A a();
    cout << "size of class: " << sizeof(A) << endl;
    cout << "######end of test 3######\n";
    #endif
    #if 0
    cout << "######start of test 4######\n";
    Apple obj5;
    Apple* a1;
    Fruit f2;
    Fruit* f1 = &obj5;
    //f1->same(3);
    //a1 = &f2;
    a1->same();
    //obj5.same(3);
    cout << "######end of test 4######\n"; //test method in derived class only, derived class pointer point to based class(error)
    #endif
    #if 0
    cout << "######start of test 5######\n";
    Apple a2;
    Fruit f3;
    a2.a_sp = make_shared<int>(5);
    f3.f_sp = a2.a_sp;//use_count == 2()
    
    cout << "a2.a_sp.usecount: " << a2.a_sp.use_count() << endl;
    cout << "a2.a_sp.getptr: " << a2.a_sp.get() << endl;
    cout << "f3.f_sp.usecount: " << f3.f_sp.use_count() << endl;
    cout << "f3.f_sp.getptr: " << f3.f_sp.get() << endl;
    cout << "shared int : " << *f3.f_sp.get() << endl;
    #endif
    
    #if 0
    auto f4 = make_shared<Fruit>();
    auto a3 = make_shared<Apple>();
    cout << "f3.usecount: " << f4.use_count() << endl;
    cout << "a3.usecount: " << a3.use_count() << endl;
    #if 0 //shared_ptr memory leak
    f4->f_scp = a3;
    a3->a_scp = f4;
    #else //weak_ptr ok
    f4->w_p = a3;
    a3->w_p = f4;
    #endif
    cout << "f3.usecount: " << f4.use_count() << endl;
    cout << "a3.usecount: " << a3.use_count() << endl;
    cout << "######end of test 5######\n"; //test shared_ptr
    #endif
    #if 0
    cout << "######start of test 6######\n";
    Fruit f1;
    Apple a1;

    cout << "is f_array is empty? " << f1.f_array.empty() << endl;
    cout << "size: " << f1.f_array.size() << endl;
    cout << "max_size: " << f1.f_array.max_size() << endl;

    cout << "first val" << endl;
    for (auto i = f1.f_array.begin(); i < f1.f_array.end(); i++) {
        cout << "f1.f_array item: " << *i << endl;
    }
    for (auto i = a1.a_array.begin(); i < a1.a_array.end(); i++) {
        cout << "a1.a_array item: " << *i << endl;
    }
    cout << "init val" << endl;
    int a = 0;
    for (auto i = f1.f_array.begin(); i < f1.f_array.end(); i++, a++) {
        *i = a;
    }
    cout << "check init val" << endl;
    for (auto i = f1.f_array.begin(); i < f1.f_array.end(); i++) {
        cout << "item: " << *i << endl;
    }
    f1.f_array.swap(a1.a_array);
    cout << "check swap val" << endl;
    for (auto i = f1.f_array.begin(); i < f1.f_array.end(); i++) {
        cout << "f1.f_array item: " << *i << endl;
    }
    for (auto i = a1.a_array.begin(); i < a1.a_array.end(); i++) {
        cout << "a1.a_array item: " << *i << endl;
    }
    cout << "######end of test 6######\n"; //test array
    #endif
    #if 0
    cout << "######start of test 7######\n";
    deque<int> my_deck1(3, 100);
    deque<int> my_deck2(2, 50);
    queue<int, deque<int>> my_queue1(my_deck1);//use dequeue implementation
    queue<int, deque<int>> my_queue2(my_deck2);
    cout << "sizeof my_queue1: " << my_queue1.size() << endl;
    cout << "front my_queue1: " << my_queue1.front() << endl;
    my_queue1.pop();
    cout << "sizeof my_queue1: " << my_queue1.size() << endl;
    cout << "front my_queue1: " << my_queue1.front() << endl;
    my_queue1.pop();
    cout << "sizeof my_queue1: " << my_queue1.size() << endl;
    cout << "front my_queue1: " << my_queue1.front() << endl;
    

    
    cout << "######end of test 7######\n"; //test queue
    #endif

    #if 1
    cout << "######start of test 8######\n";
    thread t(hello_thread);
    //t.join();//with join or detach, or terminate called without an active exception
    t.detach();
    this_thread::sleep_for(chrono::seconds(5));
    cout << "######end of test 8 ######\n"; //test thread
    #endif
    
    cout << "end of main\n";
    return 0;
} 
