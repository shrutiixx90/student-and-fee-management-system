#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip.h>
#include<iostream.h>
#include<conio.h>
class student
{
    char name[10],city[10],fname[20],mname[50];
    int roll,marks;
    long contact;
public:
    void addstudent()
    {
	fstream f1("student.dat",ios::binary|ios::out);
	student s1;
	s1.setdata();
	f1.write((char*)&s1,sizeof(s1));
	f1.close();
    }
    void setdata()
    {
	cout<<"enter following details :\n";
	cout<<"enter name :";
	cin>>name;
	cout<<"enter roll:";
	cin>>roll;
	cout<<"enter contact number :";
	cin>>contact;
	cout<<"enter your mother's name:";
	cin>>mname;
	cout<<"enter father's name: ";
	cin>>fname;
	cout<<"enter your marks:" ;
	cin>>marks;
	cout<<"enter your city:";
	cin>>city;

    }

    void showstudent()                                     x
    {
	student s1;
	fstream f2("student.dat",ios::binary|ios::in);
	cout<<"\n----------------------------------------------------------------------------";
	cout<<endl<<setiosflags(ios::left)<<setw(10)<<"name "<<setw(10)<<"roll"<<setw(10)<<"contact"<<setw(15)<<"mother"<<setw(10)<<"father"<<setw(10)<<"marks"<<setw(10)<<"city";
	cout<<"\n----------------------------------------------------------------------------";
	while(f2.read((char*)&s1,sizeof(s1)))
	{
		cout<<endl<<setiosflags(ios::left)<<setw(10)<<s1.name<<setw(10)<<s1.roll<<setw(10)<<s1.contact<<setw(15)<<s1.mname<<setw(10)<<s1.fname<<setw(10)<<s1.marks<<setw(10)<<s1.city;
	}
	cout<<"\n----------------------------------------------------------------------------";
	f2.close();
    }
    void deletestudent()
    {
       int r;
       cout<<endl<<"enter roll number to be delete:";
       cin>>r;
       fstream f1("student.dat",ios::binary|ios::in);
       fstream f2("temp.dat",ios::binary|ios::out);
       student s1;
       while(f1.read((char*)&s1,sizeof(s1)))
       {
		if(s1.roll!=r)
		{
			f2.write((char*)&s1,sizeof(s1));
		}
       }
       f1.close();
       f2.close();
       remove("student.dat");
       rename("temp.dat","student.dat");
    }
    void searchstudent()
    {
	int r,flag=0;
	cout<<"enter roll number to be searched :";
	cin>>r;
	fstream f1("student.dat",ios::binary|ios::in);
	student s1;
	while(f1.read((char*)&s1,sizeof(s1)))
	{
		if(s1.roll==r)
		{
			cout<<"\n record found";
			cout<<endl<<setiosflags(ios::left)<<setw(10)<<s1.name<<setw(10)<<s1.roll<<setw(10)<<s1.contact<<setw(15)<<s1.mname<<setw(10)<<s1.fname<<setw(10)<<s1.marks<<setw(10)<<s1.city;
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<endl<<"result not found";
	}
    }
    void updatestudent()
    {
	int r;
       cout<<endl<<"enter roll number to be update:";
       cin>>r;
       fstream f1("student.dat",ios::binary|ios::in);
       fstream f2("temp.dat",ios::binary|ios::out);
       student s1;
       while(f1.read((char*)&s1,sizeof(s1)))
       {
		if(s1.roll!=r)
		{
			f2.write((char*)&s1,sizeof(s1));
		}
		else
		{
			s1.setdata();
			f2.write((char*)&s1,sizeof(s1));
		}
       }
       f1.close();
       f2.close();
       remove("student.dat");
       rename("temp.dat","student.dat");
    }
};
class fee
{
	char date[15];
	int roll,recipt;
	long amount;
public:
    void addfee()
    {
	fstream f1("fee.dat",ios::binary|ios::app);
	fee b1;
	b1.setfeedata();
	f1.write((char*)&b1,sizeof(b1));
	f1.close();
    }
    void setfeedata()
    {
	cout<<"enter following details :\n";
	recipt=getmaxrecno()+1;
	cout<<"enter roll:";
	cin>>roll;
	cout<<"enter amount :";
	cin>>amount;
	cout<<"enter date:";
	cin>>date;
    }
    int getmaxrecno()
    {
	fstream f1("fee.dat",ios::binary|ios::in);
	fee b1;
	int max=0;
	while(f1.read((char*)&b1,sizeof(b1)))
	{

		if(b1.recipt>max)
		{
			max=b1.recipt;
		}
	}
	return max;
	f1.close();

    }
    void showfee()
    {
	fee b1;
	fstream f2("fee.dat",ios::binary|ios::in);
	cout<<"\n----------------------------------------------------------------------------";
	cout<<endl<<setiosflags(ios::left)<<setw(10)<<"recipt "<<setw(10)<<"roll"<<setw(10)<<"amount"<<setw(15)<<"date";
	cout<<"\n----------------------------------------------------------------------------";
	while(f2.read((char*)&b1,sizeof(b1)))
	{
		cout<<endl<<setiosflags(ios::left)<<setw(10)<<b1.recipt<<setw(10)<<b1.roll<<setw(10)<<b1.amount<<setw(15)<<b1.date;
	}
	cout<<"\n----------------------------------------------------------------------------";
	f2.close();
    }
    void deletefee()
    {
       int r;
       cout<<endl<<"enter recpit number to be delete:";
       cin>>r;
       fstream f1("fee.dat",ios::binary|ios::in);
       fstream f2("data.dat",ios::binary|ios::out);
       fee b1;
       while(f1.read((char*)&b1,sizeof(b1)))
       {
		if(b1.roll!=r)
		{
			f2.write((char*)&b1,sizeof(b1));
		}
       }
       f1.close();
       f2.close();
       remove("fee.dat");
       rename("data.dat","fee.dat");
    }
    void searchfee()
    {
	int r,flag=0;
	cout<<"enter roll number to be searched :";
	cin>>r;
	fstream f1("fee.dat",ios::binary|ios::in);
	fee b1;
	while(f1.read((char*)&b1,sizeof(b1)))
	{
		if(b1.roll==r)
		{
			cout<<"\n record found";
			cout<<endl<<setiosflags(ios::left)<<setw(10)<<b1.recipt<<setw(10)<<b1.roll<<setw(10)<<b1.amount<<setw(15)<<b1.date;
			flag=1;
		}

	}
	if(flag==0)
	{
		cout<<endl<<"result not found";
	}
    }
    void updatefee()
    {
	int r;
       cout<<endl<<"enter roll number to be update:";
       cin>>r;
       fstream f1("fee.dat",ios::binary|ios::in);
       fstream f2("data.dat",ios::binary|ios::out);
       fee b1;
       while(f1.read((char*)&b1,sizeof(b1)))
       {
		if(b1.roll!=r)
		{
			f2.write((char*)&b1,sizeof(b1));
		}
		else
		{
			b1.setfeedata();
			f2.write((char*)&b1,sizeof(b1));
		}
       }
       f1.close();
       f2.close();
       remove("fee.dat");
       rename("data.dat","fee.dat");
    }

};
main()
{
    student s1;
    fee b1;
    int choice;
    clrscr();
    START:
    while(1)
    {
	cout<<endl<<"STUDENT FEE MANAGEMENT SYSTEM";
	cout<<endl<<"MAIN MENU";
	cout<<endl<<"1.STUDENT MASTER";
	cout<<endl<<"2.FEE MASTER";
	cout<<endl<<"3.exit";
	cout<<endl<<"enter your choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			while(1)
			{
				cout<<endl<<" STUDENT MASTER";
				cout<<endl<<"1.add student";
				cout<<endl<<"2.show student";
				cout<<endl<<"3.Delete student";
				cout<<endl<<"4.search student";
				cout<<endl<<"5.update student";
				cout<<endl<<"6.BACK";
				cout<<endl<<"enter your choice:";
				cin>>choice;
				switch(choice)
				{
					case 1:
						s1.addstudent();
						break;
					case 2:
						s1.showstudent();
						break;
					case 3:
						s1.deletestudent();
						break;
					case 4:
						s1.searchstudent();
						break;
					case 5:
						s1.updatestudent();
						break;
					default:
						goto START;
				}

			}
			break;

		case 2:
			while(1)
			{
				cout<<endl<<" FEE MASTER";
				cout<<endl<<"1.add FEE";
				cout<<endl<<"2.show FEE";
				cout<<endl<<"3.Delete FEE";
				cout<<endl<<"4.search FEE";
				cout<<endl<<"5.update FEE";
				cout<<endl<<"6.BACK";
				cout<<endl<<"enter your choice:";
				cin>>choice;
				switch(choice)
				{
					case 1:
						b1.addfee();
						break;
					case 2:
						b1.showfee();
						break;
					case 3:
						b1.deletefee();
						break;
					case 4:
						b1.searchfee();
						break;
					case 5:
						b1.updatefee();
						break;
					default:
						goto START;
				}

			}
			break;
		default:
			exit(1);
			break;
	}
    }

    getch();
}
