// 继承_重载_using构造函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;


class Partner {
public:
	Partner(int id) :mID(id) {}
private:
	int mID;
	// 定义在类中的友元函数,其作用域在全局作用域下.
	// 类域内定义的友元函数调用时必须具有该类类型的实参,或者具有从该类型(实参是本类型)转换到形参类型 
	friend ostream& operator<< (ostream& os, Partner& self) {
		os << self.mID;
		return os;
	}
};


class Base {
public:
	Base(int temp):mInt(temp){}
	Base(float temp):mFloat(temp){}
	Base(double temp) :mDouble(temp) {}

	void overload_func(int temp) {
		cout << "Base::overload_func(int temp) " << temp << endl;
	}
	void overload_func(Partner& p) {
		cout << "Base::overload_func(Partner temp) temp = " << p << endl;
	}

private:
	int mInt{0};
	float mFloat{0};
	double mDouble{0};
};

class Derive : public Base {
public:
	using Base::Base;			// 继承构造函数
	using Base::overload_func;	// 继承非虚成员函数 否则 d.overload_func(p); => error: no viable conversion from 'Partner' to 'double'

	void overload_func(double temp) {
		cout << "Derive::overload_func(double temp) " << temp << endl;
	}

private:
	double mDD{ 0 };
};

int main()
{
	Partner p(123);
	// Derive d ;	//	错误!	Derive没有从Base上继承到无参构造函数
	Derive d(12); 


	d.overload_func(12);
	d.Base::overload_func(p);	// 不用 using Base::overload_func;
	d.overload_func(p);			// 必须 using Base::overload_func; 继承非虚成员函数

    return 0;
}

