#ifndef _DERIVATE_H_
#define _DERIVATE_H_
#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

class DeleteTest
{
public:
	DeleteTest()
	{
		cout << "DeleteTest constructed!" << endl;
	}

	~DeleteTest()
	{
		cout << "DeleteTest destructed!" << endl;
	}

};

class A
{
public:
	A() { cout <<"A constructed!" << endl;}
	~A(){ cout <<"A constructed!" << endl;}
	void Aout(){ cout << "A cout" << endl; }
	virtual void vAout(){ cout << "A virtual cout" << endl; }


};

class C
{

public:
	C() { cout << "C constructed!" << endl; }
	~C() { cout << "C constructed!" << endl; }
	void Cout() { cout << "C cout" << endl; }
	virtual void vCout() { cout << "C virtual cout" << endl; }

};

class B : public A  //,public C
{
public:
	B() { cout << "B constructed!" << endl; }
	~B() { cout << "B constructed!" << endl; }
	void Aout(){ cout << "B cout" << endl; }
	virtual void vAout(){ cout << "B virtual cout" << endl; }
};

class D :public B
{

};




void TestDerivate()
{
	//如果不用delete[] 会触发断点
	cout << "TestDerivate !" << endl;
	DeleteTest *test = new DeleteTest[2];
	delete[] test;
	//指针大小根据系统位数，与数组不同
	cout << "sizeof test "<<sizeof(test)<<"\n" << endl<<endl<<endl;
	
	A *a = new A();
	a->Aout();
	a->vAout();
	A aaa;
	cout << "sizeof(aaa) = :" << sizeof(aaa) << endl;
	//delete a;

	A *ab = new B();
	ab->Aout();
	ab->vAout();
	B abb;
	cout << "sizeof(abb) = :" << sizeof(abb) << endl;
	cout << "sizeof(ab) = :" << sizeof(ab) << endl;
	//delete ab;

	B *b = new B();
	b->Aout();
	b->vAout();
	cout << "sizeof(b) = :" << sizeof(b) << endl;
	//delete b;


	A* d = new D();
	D dd;
	A add = static_cast<B>(dd);
	add.Aout();
	add.vAout();
}





#endif _DERIVATE_H_