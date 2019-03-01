#include<fstream>
#include<iostream>
using namespace std;

class Com
{
protected:
	int x;
	int y;
public:
	Com(){x=1;y=2;}
	friend Com operator +(Com&,Com&);
	friend ostream& operator <<(ostream&,Com&);
	friend fstream& operator <<(fstream&,Com&);
	friend fstream& operator >>(fstream&,Com&);

};