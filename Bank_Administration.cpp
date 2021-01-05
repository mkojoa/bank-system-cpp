#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class database
{
	// Properties
	int accno, ssno;
	char name[25];
	// char first_name[20], last_name[20];
    	long long int phone;
    	float totalbal;

	//Helper Methods for reuse
	public:
    		void accept();
    		void acceptedit();
    		void display();
    		char* getname();
    		long long int getnumber();
    		int getaccno();
    		int getssno();
    		void edit_rec();
    		void delete_rec();
};

void database :: accept()
{
    cout<<"\nEnter Account Number: ";
    cin>>accno;
    cout<<"Enter Name : ";
    cin>>name;
    cout<<"Enter Phone number : ";
    cin>>phone;
    cout<<"Enter Balance: ";
    cin>>totalbal;
    cout<<"Enter Social Security Number : ";
    cin>>ssno;
    cout<<endl;
}

void database :: acceptedit()
{
    cout<<"\nEnter Name : ";
    cin>>name;
    cout<<"Enter Phone number : ";
    cin>>phone;
    cout<<"Enter Balance: ";
    cin>>totalbal;
    cout<<endl;
}

void database :: display()
{
    cout<<"\nAccount Number: "<<accno<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Phone : "<<phone<<endl;
    cout<<"Current Balance: Rs.  "<<totalbal<<endl;
    cout<<"-------------------------------"<<endl;
}

char* database :: getname()
{
	return name;
}

long long int database :: getnumber()
{
	return phone;
}

int database :: getaccno()
{
	return accno;
}

int database :: getssno()
{
	return ssno;
}

// create file
void create_file()
{
    int n;
    database d1;
    cout<<"\nEnter no. of Customers: ";
    cin>>n;
    ofstream file;
    file.open("record.DAT");
    for(int i=0; i<n; ++i)
    {
        d1.accept();
        file.write((char*)&d1 , sizeof(d1));
    }
    file.close();
}

void display_file()
{
	ifstream file;
	database d1;
	file.open("record.DAT");
	cout<<"\nEntered Details are : ";
	while(file)
	{
		file.read((char*)&d1,sizeof(d1));
		if(file.eof())
			break;
		d1.display();
	}
	file.close();
}

void addnewrec()
{
	ofstream file;
	database d1;
	file.open("record.DAT" , ios::app);
	cout<<"\nEnter Data to add New Record at the end of Previous\n";
	d1.accept();
	file.write((char*)&d1,sizeof(d1));
	file.close();
}

void searchonName()
{
	ifstream file;
	database d1;
	char name[25];
	bool flag = 0;
	cout<<"\nEnter Name To Be Searched ";
	cin>>name;
	file.open("record.DAT" , ios::in);
	while(file)
	{
		file.read((char*)&d1,sizeof(d1));
		if (file.eof()!=0)
			break;
		if (strcmp(d1.getname(),name)==0)
		{
			cout<<"\nData Found ";
			d1.display();
			flag = 1;
			break;
		}
	}
	file.close();
	if (flag == 0)
	{
		cout<<"\nRecord Not Found ";
	}
}

// search based on number
void searchonNumber()
{
	ifstream file;
	database d1;
	long long int phone;
	bool flag = 0;
	cout<<"\nEnter Number To Be Searched ";
	cin>>phone;
	file.open("record.DAT" , ios::in);
	while(file)
	{
		file.read((char*)&d1,sizeof(d1));
		if (file.eof()!=0)
			break;
		if (d1.getnumber() == phone)
		{
			cout<<"\nData Found ";
			d1.display();
			flag = 1;
			break;
		}
	}
	file.close();
	if (flag == 0)
	{
		cout<<"\nRecord Not Found ";
	}
}

//look for account number
void searchonAccNumber()
{
	ifstream file;
	database d1;
	int accno;
	bool flag = 0;
	cout<<"\nEnter Account Number To Be Searched ";
	cin>>accno;
	file.open("record.DAT" , ios::in);
	while(file)
	{
		file.read((char*)&d1,sizeof(d1));
		if (file.eof()!=0)
			break;
		if (accno == d1.getaccno())
		{
			cout<<"\nData Found ";
			d1.display();
			flag = 1;
			break;
		}
	}
	file.close();
	if (flag == 0)
	{
		cout<<"\nRecord Not Found ";
	}
}

// modify name method
void modifyonname()
{
	fstream file;
	database d1;
	char name[25];
	int ssno;
	bool flag = 0;
	cout<<"\nEnter Name To Be Searched : ";
	cin>>name;
	file.open("record.DAT" , ios::in | ios::out | ios::binary);

	while(file)
	{
		file.read((char*)&d1,sizeof(d1));
		if (file.eof()!=0)
			break;
		if (strcmp(d1.getname(),name)==0)
		{
			cout<<"\nAccount Found ";
			cout<<"\nEnter Your Social Security Number : ";
			cin>>ssno;
			if(ssno == d1.getssno())
			{
				cout<<"\nEnter New Details : ---->>>";
				d1.acceptedit();
				file.seekp(-sizeof(d1),ios::cur);
				file.write((char*)&d1,sizeof(d1));
				flag = 1;
				break;
			}
			else
				cout<<"\nGod Is Watching Don't Cheat!!!\n";
		}
	}
	file.close();
	if (flag == 0)
	{
		cout<<"\nRecord Not Found!!!! ";
	}
}

// method for modifiying account number
void modifyonaccno()
{
	fstream file;
	database d1;
	int accno;
	int ssno;
	bool flag = 0;
	cout<<"\nEnter Account Number To Be Searched : ";
	cin>>accno;
	file.open("record.DAT" , ios::in | ios::out | ios::binary);

	while(file)
	{
		file.read((char*)&d1,sizeof(d1));
		if (file.eof()!=0)
			break;
		if (d1.getaccno() == accno)
		{
			cout<<"\nAccount Found ";
			cout<<"\nEnter Your Social Security Number : ";
			cin>>ssno;
			if(ssno == d1.getssno())
			{
				cout<<"\nEnter New Details : --->>>";
				d1.acceptedit();
				file.seekp(-sizeof(d1),ios::cur);
				file.write((char*)&d1,sizeof(d1));
				flag = 1;
				break;
			}
			else
				cout<<"\nGod Is Watching Don't Cheat!!!\n";
		}
	}
	file.close();
	if (flag == 0)
	{
		cout<<"\nRecord Not Found ";
	}
}

int main()
{
	int ch, password, pass;
	int i=0;
	password = 98765;
	do
	{
	cout<<"\nAdmin Enter Your Password : ";
	cin>>pass;
	
	//check if entered password was right.
	if (password == pass)
	{
		cout<<"\n*****WELCOME ADMINISTRATOR*****\n";
		do
		{
			cout<<"\n1. Create Database";
			cout<<"\n2. Add New Record To the Database";
			cout<<"\n3. Search Customer By Name ";
			cout<<"\n4. Search Customer By Phone Number";
			cout<<"\n5. Search Customer By Account Number";
			cout<<"\n6. Modify Customer Data By Name ";
			cout<<"\n7. Modify Customer Data By Account Number";
			cout<<"\n8. View Your Database";
			cout<<"\n\nEnter Your Choice : ";
			cin>>ch;

			//Switch between methods based on the selected option.
			switch(ch)
			{
			case 1 : create_file();			break;
			case 2 : addnewrec(); 			break;
			case 3 : searchonName();		break;
			case 4 : searchonNumber();		break;
			case 5 : searchonAccNumber();	break;
			case 6 : modifyonname();		break;
			case 7 : modifyonaccno();		break;
			case 8 : display_file();		break;
			}
		}while(ch>0 && ch<9);
	}
	else
		{
		cout<<"\nYou Are No Admin\n";
		i++;
		cout<<'\n'<<5-i<<" Trie(s) More Left";
		}
	}while(i>0 && i<5);
	return 0;
}
