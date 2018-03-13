#include <iostream>
using namespace std;

void param_val()
{
	size_t v1 = 100;
	auto f = [v1]{cout << v1 << endl;};
	f();	//100
	v1 = 0;
	f();	//100, when lambda expression created, the param was copied!!! not call lambda object assign param!
}

void param_ref()
{
	size_t va = 100;
	auto f = [&va]{cout << va << endl;};
	f();	//100;
	va = 0;
	f();	//0, because va if reference!
}

void implicit(int x)
{
	//[=] means the captured param copied by value!
	auto lambda_expression = [=]{cout << x << endl;};
	//auto lambda_expression = [=]{cout << x << endl;}; //Error, val param is const, can't be changed!
	lambda_expression();
}

void implicit2(int x)
{
	//[&] means the captured param is reference! so can change it.
	auto lambda_expression = [&]{cout << ++x << endl;};
	lambda_expression();
}

void implicit3(int x, ostream &os = cout, char c = '$')
{
	auto lambda_expression = [&, c]{os << c << endl;};
	lambda_expression();
	
	auto lambda_expression2 = [=, &os]{os << c << c << endl;};
	lambda_expression2();
	
	/* auto lambda_expression3 = [=, &, c]{os << c << x << endl;};
	lambda_expression3(); */ //Error, [=, &], cannot implicit capture multiple params!
	
	auto lambda_expression3 = [&, x, c]{os << c << c << c << x << endl;};
	lambda_expression3();
}

void mutable_local_var()
{
	size_t x = 99;
	auto lambda = [x]()mutable{cout << ++x << endl;}; //100, init x=99 embed lambda expression!
	lambda();
	x = 0;
	lambda(); //101!!!
}

void lambda2()
{
	size_t x = 99;
	auto lambda = [&x]{cout << ++x << endl;}; //100
	lambda();
	x = 0;
	lambda();	//1
}

int main()
{
	param_val();
	cout << endl;
	
	param_ref();
	cout << endl;
	
	int v = 99;
	implicit(v);
	cout << endl;
	
	implicit2(v);	//100, implicit captured reference param
	cout << v << endl; //99; but copy v to function implicit2, so v is still 99!!!
	cout << endl;
	
	implicit3(v);
	cout << endl;
	
	mutable_local_var();
	cout << endl;
	
	lambda2();
	cout << endl;
	
	return 0;
}