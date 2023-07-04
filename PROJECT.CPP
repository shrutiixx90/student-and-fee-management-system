#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip.h>
#include<iostream.h>
#include<conio.h>
class student
{
    char name[10],city[10],fathername[20],address[50];
    int roll,marks;
    long contact;
public:
    void addstudent()
    {
	fstream f1("student.dat",ios::binary|ios::app);
	student s1;
	s1.setdata();
	f1.write((char*)&s1,sizeof(s1));
	f1.close();
    }
    void setdata()
    {
	cout<<endl<<"enter following details :";
	cout<<"enter name :";
	cin>>name;
	cout<<"enter roll:";
	cin>>roll;
	cout<<"enter contact number :";
	cin>>contact;
	cout<<"enter your address:";
	cin>>address;
	cout<<"enter father's name: ";
	cin>>fathername;
	cout<<"enter your marks:" ;
	cin>>marks;
	cout<<"enter your city:";
	cin>>city;
    }
    void showstudent()
    {
	student s1;
	fstream f2("student.dat",ios::binary|ios::in);
	cout<<"\n----------------------------------------------------------------------------";
	cout<<endl<<setiosflags(ios::left)<<setw(10)<<"name "<<setw(10)<<"roll"<<setw(10)<<"contact"<<setw(15)<<"address"<<setw(10)<<"father"<<setw(10)<<"marks"<<setw(10)<<"city";
	cout<<"\n----------------------------------------------------------------------------";
	while(f2.read((char*)&s1,sizeof(s1)))
	{
		cout<<endl<<setiosflags(ios::left)<<setw(10)<<s1.name<<setw(10)<<s1.roll<<setw(10)<<s1.contact<<setw(15)<<s1.address<<setw(10)<<s1.fathername<<setw(10)<<s1.marks<<setw(10)<<s1.city;
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
	int r;
	cout<<"enter roll number to be searched :";
	cin>>r;
	fstream f1("student.dat",ios::binary|ios::in);
	student s1;
	while(f1.read((char*)&s1,sizeof(s1)))
	{
		if(s1.roll==r)
		{
			cout<<"\n record found";
			cout<<endl<<setiosflags(ios::left)<<setw(10)<<s1.name<<setw(10)<<s1.roll<<setw(10)<<s1.contact<<setw(15)<<s1.address<<setw(10)<<s1.fathername<<setw(10)<<s1.marks<<setw(10)<<s1.city;
		}
	}
	cout<<endl<<"result not found";
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
main()
{
    student s1;
    int choice;
    clrscr();
    while(1)
    {
	cout<<endl<<"welcome to STUDENT MANAGEMENT SYSTEM";
	cout<<endl<<"1.add student";
	cout<<endl<<"2.show student";
	cout<<endl<<"3.Delete student";
	cout<<endl<<"4.search student";
	cout<<endl<<"5.update student";
	cout<<endl<<"6.exit";
	cout<<endl<<"enter your choice";
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
	    exit(1);
	}
    }
    getch();
}
