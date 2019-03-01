#include"БъЭЗ.h"
#include<iostream>

ostream& operator <<(ostream& out,Com& c)
{
	out<<"("<<c.x<<","<<c.y<<")"<<endl;
	return out;
}

fstream& operator <<(fstream& fout ,Com& c)
{
	fout<<c.x<<" "<<c.y<<endl;
	return fout;
}

fstream& operator >>(fstream& fin,Com& c)
{
	fin>>c.x>>c.y;
	return fin;
}

Com operator +(Com& c1,Com& c2)
{
	Com c;
	c.x=c1.x+c2.x;
	c.y=c1.y+c2.y;
	return c;
}

int main()
{
	Com c;
	Com d;
	d=c+c;
	cout<<c;

	fstream file;
	file.open("data.txt",ios::app);
	if(!file)
	{
		cerr<<"open fail"<<endl;
		file.open("data.txt",ios::out);
	}
	file<<d;
	file<<c;
	file<<d;
	file.close();
	file.open("data.txt",ios::in);
	if(!file)
	{cout<<"read fail"<<endl;}
	file>>c;
	cout<<c;
	file>>c;
	cout<<c;
	system("pause");
	return 0;


}