#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct dest
{
	string ip;
	unsigned port;
	dest(string _ip, unsigned _port) : ip(_ip), port(_port){}
};

struct conn
{
	string ip;
	unsigned port;
	conn(string _ip, unsigned _port) : ip(_ip), port(_port){}
};

conn connect(const dest *d)
{
	//return conn(d->ip, d->port);
	shared_ptr<conn> pConn(new conn(d->ip, d->port));
	cout << "creating connection:" << pConn.use_count() << endl;
	return *pConn;
}

void disconnect(const conn &c)
{
	cout << "disconnect connection:" << c.ip << ":" << c.port << endl;
}

void close_conn(const conn *p)
{
	disconnect(*p);
}

void f(dest &d)
{
	conn c = connect(&d);
	shared_ptr<conn> p(&c, close_conn); //auto free memory while exit
	cout << "connect..." << p.use_count() << endl;
	//disconnect(c);
}

//exercise12.15
void f2(dest &d)
{
	conn c = connect(&d);
	shared_ptr<conn> p(&c/* &connect(&d) */, [](conn *p){disconnect(*p);});
	cout << "connect2..." << p.use_count() << endl;
}

void f3(dest &d)
{
	conn c = connect(&d);
	unique_ptr<conn, decltype(close_conn)*> p(&c, close_conn);
	cout << "connect3..." << endl;
}

int main()
{
	dest d("192.168.0.1", 8080);
	f(d);
	cout << d.ip << ':' << d.port << endl;
	cout << endl;
	f2(d);
	
	cout << endl;
	f3(d);
	
	return 0;
}