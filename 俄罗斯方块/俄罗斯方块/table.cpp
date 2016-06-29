#include"table.h"
using namespace std;

bool Table::Check(Position& position)
{
	return t[position.row][position.column];
}

void Table::Fresh()
{
	system("CLS");
	for(int i=4;i<HEIGHT-1;i++)
	{
		cout<<"    "<<"¡õ";
		for(int j=1;j<WIDTH-1;j++)
		{
			Position position={i,j};
			if(Check(position)==0){cout<<"  ";}
			else{printf("%c", "¡ö");}
		}
		cout<<"¡õ";
		cout<<endl;
	}
	cout<<"    ";
	for(int j=0;j<WIDTH;j++)
	{cout<<"¡õ";}
}