#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct destination
{
	string ip;
	int port;
	destination(string _ip, int _port) : ip(_ip), port(_port){}
};

struct connection
{
	string ip;
	int port;
	connection(string _ip, int _port) : ip(_ip), port(_port){}
};

connection connect(destination* dest)
{
	shared_ptr<connection> p(new connection(dest->ip, dest->port));
	cout << "creating connection:" << p.use_count() << endl;
	return *p;
}

void disconnect(connection c)
{
	cout << "closing connection:" << c.ip << ':' << c.port << endl;
}

void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
	cout << "connecting now:" << p.use_count() << endl;
}

int main()
{
	destination dest("10.10.10.10", 12345);
	f(dest);
	return 0;
}