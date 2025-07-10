#ifndef MYCOMPLEX
#define MYCOMPLEX

// 前向声明 complex 类
class complex;

// 内部辅助函数声明（用于实现运算符重载）
complex& __doapl(complex* ths, const complex& r);
complex& __doami(complex* ths, const complex& r);

class complex 
{
public:
    complex (double r = 0, double i = 0) : re (r), im (i) {}
    complex& operator += (const complex&);
    complex& operator -= (const complex&);
    double real() const {return re;}
    double imag() const {return im;}
private:
    double re, im;

    // 声明辅助函数为友元，允许其访问私有成员
    friend complex& __doapl (complex*, const complex&);
    friend complex& __doami (complex*, const complex&);
};

// 辅助函数定义，实现加法和减法的具体操作
inline complex& __doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex& __doami(complex* ths, const complex& r)
{
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

// 成员函数实现，重载 += 和 -= 运算符
inline complex& complex::operator += (const complex& r)
{
    return __doapl(this, r);
}

inline complex& complex::operator -= (const complex& r)
{
    return __doami(this, r);
}

// 全局函数，获取复数的实部和虚部
inline double real(const complex& x) 
{
    return x.real();
}

inline double imag(const complex& x)
{
    return x.imag();
}

// 全局运算符重载，实现复数加法和减法
inline complex operator + (complex& x, complex& y)
{
    return complex(real(x)+real(y), imag(x)+imag(y));
}

inline complex operator - (complex& x, complex& y)
{
    return complex(real(x)-real(y), imag(x)-imag(y));
}

#endif