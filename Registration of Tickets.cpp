#include <iostream>
#include <fstream>
void submit();
void history();
void payoff();
void deleteTicket();
void summary();
void ID();
using namespace std;
int main()
{
	long long int n;
	for(;;)
	{
		cout<<"1.submit a new ticket"<<endl<<"2.traffic infringement history"
		<<endl<<"3.pay off a ticket"<<endl<<"4.delete a ticket"
		<<endl<<"5.providing a full history of all tickets"
		<<endl<<"6.ID"<<endl<<"7.end"<<endl;		
		do
		{
			cout<<"input your number:";
			cin>>n;
			system("cls");
		}while(n<1 && n>7);
		switch(n)
		{
			case 1:submit();break;
			case 2:history();break;
			case 3:payoff();break;
			case 4:deleteTicket();break;
			case 5:summary();break;
			case 6:ID();break;
			case 7:return 0;
		}
	}
}
void submit()
{
	long long int a[10];
	cout<<"license number" ;
	cin>>a[0];
	cout<<"history (y/m/d):";
	cin>>a[1]>>a[2]>>a[3];
	cout<<"fine of the ticket:";
	cin>>a[4];
	cout<<"ID number:";
	cin>>a[5];
	a[6]=0;
	ofstream f;
	f.open("your directory of a text file",ios::app);
	for(int i=0;i<7;i++)f<<a[i]<<"\t";
	f<<endl;
	f.close();
	cout<<"done"<<endl;
	system("pause");
	system("cls");
}
void history()
{
	long long int a[10],n,s=0,x;
	cout<<"license number" ;
	cin>>n;
	ifstream g;
	g.open("your directory of a text file");
	if(!g)
	{
		cout<<"can not open the file";
		return;
	}
	for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
	{
		if(n==a[0])
		{
			cout<<"("<<a[1]<<"/"<<a[2]<<"/"<<a[3]<<")"<<"\t"<<a[4]<<"\t"<<a[5]<<"\t"<<a[6]<<endl;
			if(a[6]==0)s+=a[4];
		}
	}
	g.close();
	cout<<"sum of fines:"<<s<<endl;
	system("pause");
	system("cls");
}
void payoff()
{
	long long int a[10],n,i=0,j,x;
	cout<<"license number:";
	cin>>n;
	ifstream g;
	ofstream f;
	g.open("your directory of a text file");
	if(!g)
	{
		cout<<"can not open the file";
		return;
	}
	for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];i=0)
		if(n==a[0] && a[6]==0){i++;break;}
	if(i==0)
	{
		cout<<"ticket does not exist based on this license number"<<endl;
		system("pause");
		system("cls");
		return;
	}
	g.close();
	g.open("your directory of a text file");
	i=1;
	for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
	{
		if(a[0]==n && a[6]==0)
		{
			cout<<i<<"."<<"("<<a[1]<<"/"<<a[2]<<"/"<<a[3]<<")"<<"\t"<<a[4]<<"\t"<<a[5]<<"\t"<<a[6]<<endl;
			i++;
		}
	}
	cout<<i<<'.'<<"pay off all"<<endl<<i+1<<'.'<<"pay off none"<<endl;
	g.close();
	do
	{
		cout<<"input your number:";
		cin>>x;
	}while(x<1 || x>i+1);
	if(x==i)
	{
		g.open("your directory of a text file");
		f.open("your directory of a text file");
		for(j=1;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
		{
			if(a[0]==n && a[6]==0)a[6]=1;
			for(int y=0;y<7;y++)f<<a[y]<<' ';
			f<<endl;
		}
		system("cls");
		cout<<"done"<<endl;
		g.close();
		f.close();
		g.open("your directory of a text file");
		f.open("your directory of a text file");
		for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
		{
			for(int y=0;y<7;y++)f<<a[y]<<"\t";
			f<<endl;
		}
		g.close();
		f.close();
	}
	else if(x==i+1)
	{
		system("cls");
		return;
	}
	else
	{
		g.open("your directory of a text file");
		f.open("your directory of a text file");
		for(j=1;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
		{
			if(a[0]==n && a[6]==0)j++;
			if(j==x+1){a[6]=1,j++;}
			for(int y=0;y<7;y++)f<<a[y]<<' ';
			f<<endl;
		}
		cout<<"done"<<endl;
		g.close();
		f.close();
		g.open("your directory of a text file");
		f.open("your directory of a text file");
		for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
		{
			for(int y=0;y<7;y++)f<<a[y]<<"\t";
			f<<endl;
		}
		g.close();
		f.close();
	}
	system("pause");
	system("cls");
}
void deleteTicket()
{
	long long int a[10],n,i=0,j,x;
	cout<<"license number:";
	cin>>n;
	ifstream g;
	ofstream f;
	g.open("your directory of a text file");
	if(!g)
	{
		cout<<"can not open the file";
		return;
	}
	for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];i=0)
		if(n==a[0]){i++;break;}
	if(i==0)
	{
		cout<<"ticket does not exist based on thins license number"<<endl;
		system("pause");
		system("cls");
		return;
	}
	g.close();
	g.open("your directory of a text file");
	i=1;
	for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
	{
		if(a[0]==n)
		{
			cout<<i<<"."<<"("<<a[1]<<"/"<<a[2]<<"/"<<a[3]<<")"<<"\t"<<a[4]<<"\t"<<a[5]<<"\t"<<a[6]<<endl;
			i++;
		}
	}
	cout<<i<<'.'<<"delete all"<<endl<<i+1<<'.'<<"delete none"<<endl;
	g.close();
	do
	{
		cout<<"input your number:";
		cin>>x;
	}while(x<1 || x>i+1);
	if(x==i)
	{
		g.open("your directory of a text file");
		f.open("your directory of a text file");
		for(j=1;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
		{
			if(a[0]==n)a[0]=0;
			if(a[0]!=0)
			{
				for(int y=0;y<7;y++)f<<a[y]<<' ';
				f<<endl;
			}
		}
		system("cls");
		cout<<"done"<<endl;
		g.close();
		f.close();
		g.open("your directory of a text file");
		f.open("your directory of a text file");
		for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
		{
			for(int y=0;y<7;y++)f<<a[y]<<"\t";
			f<<endl;
		}
		g.close();
		f.close();
	}
	else if(x==i+1)
	{
		system("cls");
		return;
	}
	else
	{
		g.open("your directory of a text file");
		f.open("your directory of a text file");
		for(j=1;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
		{
			if(a[0]==n)j++;
			if(j==x+1){a[0]=0,j++;}
			if(a[0]!=0)
			{
				for(int y=0;y<7;y++)f<<a[y]<<' ';
				f<<endl;
			}
		}
		cout<<"done"<<endl;
		g.close();
		f.close();
		g.open("your directory of a text file");
		f.open("your directory of a text file");
		for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
		{
			for(int y=0;y<7;y++)f<<a[y]<<"\t";
			f<<endl;
		}
		g.close();
		f.close();
	}
	system("pause");
	system("cls");
}
void summary()
{
	long long int a[10],x,s=0,b[10];
	ifstream g;
	ofstream f1;
	ifstream g1;
	f1.open("your directory of a text file");
	g.open("your directory of a text file");
	if(!g)
	{
		cout<<"can not open the file";
		return;
	}
	for(int i=0;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];i=0)
	{
		g1.open("your directory of a text file");
		if(!g1)
		{
			cout<<"can not open the file";
			return;
		}
		for(;g1>>x;)if(a[0]==x){i++;break;}
		if(i==0)f1<<a[0]<<endl;
		g1.close();
	}
	f1.close();
	g.close();
	g1.open("your directory of a text file");
	f1.open("your directory of a text file");
	for(;g1>>x;s=0)
	{
		g.open("your directory of a text file");
		for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
			if(x==a[0] && a[6]==0)s+=a[4];
		f1<<x<<" : "<<s<<endl;
		g.close();
	}
	f1.close();
	g1.close();
	cout<<"done"<<endl;
	system("pause");
	system("cls");
}
void ID()
{
	long long int a[10],x,s=0,b[10];
	ifstream g;
	ofstream f1;
	ifstream g1;
	f1.open("your directory of a text file");
	g.open("your directory of a text file");
	if(!g)
	{
		cout<<"can not open the file";
		return;
	}
	for(int i=0;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];i=0)
	{
		g1.open("your directory of a text file");
		if(!g1)
		{
			cout<<"can not open the file";
			return;
		}
		for(;g1>>x;)if(a[5]==x){i++;break;}
		if(i==0)f1<<a[5]<<endl;
		g1.close();
	}
	f1.close();
	g.close();
	g1.open("your directory of a text file");
	f1.open("your directory of a text file");
	for(;g1>>x;s=0)
	{
		g.open("your directory of a text file");
		for(;g>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];)
			if(x==a[5] && a[6]==0)s+=a[4];
		f1<<x<<" : "<<s<<endl;
		g.close();
	}
	f1.close();
	g1.close();
	cout<<"done"<<endl;
	system("pause");
	system("cls");
}
