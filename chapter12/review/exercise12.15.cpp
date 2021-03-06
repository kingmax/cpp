#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct destination
{
	string IP;
	int Port;
	destination(string ip, int port) : IP(ip), Port(port)
	{
		cout << "destination constructor, IP:" << ip << ", Port:" << port << endl;
	}
};

struct connection
{
	string IP;
	int Port;
	connection(string ip, int port) : IP(ip), Port(port)
	{
		cout << "connection constructor, IP:" << ip << ", Port:" << port << endl;
	}
};

connection connect(destination *d)
{
	shared_ptr<connection> p(new connection(d->IP, d->Port));
	cout << "creating connection: " << p.use_count() << endl; 
	return *p;
}

void disconnect(connection c)
{
	cout << "disconnect: " << c.IP << ":" << c.Port << endl;
}

void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *cnn){disconnect(*cnn);});
	cout << "connecting now:" << p.use_count() << endl;
}

void f2(destination &d)
{
	connection c = connect(&d);
	unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection);
}

int main()
{
	destination dest("10.10.10.10", 12345);
	destination dest2("10.10.10.11", 23456);
	f(dest);
	f2(dest2);
	return 0;
}