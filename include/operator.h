#include <string>

using namespace std;

class happy
{
public:
    happy();
    happy(int a, string b)
    {
        this->m_A = a;
        this->m_B = b;
    }
    // 成员函数实现 + 号运算符重载
    /*
    int operator+(const happy &b)
    {
        return this->m_A + b.m_A;
    }
    */
   happy operator+(const happy &b)
   {
       happy temp;
       temp.m_A = this->m_A + b.m_A;
       temp.m_B = this->m_B + b.m_B;
       return temp;
   }
   // 成员函数实现<<运算符重载(必须要配合友元实现)
   friend ostream &operator<<(ostream &cout, const happy &a)
   {
       cout << "a.m_A = " << a.m_A << "\t" << "a.m_B = " << a.m_B << endl;
       return cout;
   }
    ~happy();
    // 成员函数实现前置++运算符重载（必须返回引用）
    happy& operator++()
    {
        this->m_A++;
        return *this;
    }
    // 成员函数实现后置++运算符重载（返回的是局部对象，不能返回引用）
    happy operator++(int)
    {
        happy temp = *this;
        this->m_A++;
        return temp;
    }

public:
    int m_A;
    string m_B;
};

happy::happy(){
    this->m_A = 1;
    this->m_B = "b";
    cout << "调用happy类的构造函数!" << endl;
}
happy::~happy(){
    this->m_A = 0;
    this->m_B = "0";
    cout << "调用happy类的析构函数!" << endl;
}

// 全局函数实现 + 号运算符重载
happy operator+(const happy &a, const happy &b){
    happy temp;
    temp.m_A = a.m_A + b.m_A;
    temp.m_B = a.m_B + b.m_B;
    return temp;
}
happy operator+(const happy &a, int b){
    happy temp;
    temp.m_A = a.m_A + b;
    temp.m_B = a.m_B + "b";
    // cout << "operator+(const happy &a, int b)" << endl;
    return temp;  
}

class people_test
{
public:
    people_test(int age)
    {
        p_Age = new int(age);
    }

    people_test& operator=(people_test &p)
    {
        
    }
public:
    int *p_Age;
};