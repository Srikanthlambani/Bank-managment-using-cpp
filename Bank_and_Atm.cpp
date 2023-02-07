#include<iostream>
#include<string>
#include<stdlib.h>
#include <ctime>
#include<vector>
using namespace std;
class Account
{
	private:	
	int pin;
	float balance;
	string name;
	string account_number;
	int age;
	string date_of_birth;
	string phone_num;
	vector <int> transaction_type;
	vector <string> date_and_time;
	vector <float> amount;
	string date_of_creation;
	
	
	public:
	Account();
	void create_account();
	void withdraw();
	void deposit();
	void transactions();
	void change_pin();
	void Atm_service();
	void Atm_menu_template();
	void Balance_check();
	void Bank_template_print();
	void Passbook();
	void Details();
		
};
void Account::Passbook()
{
	cout<<endl;
	Details();
	transactions();
}
void Account::Details()
{
	cout<<"Name                           -----> "<<name<<endl;
	cout<<"Date of birth                  -----> "<<date_of_birth<<endl;
	cout<<"Age                            -----> "<<age<<endl;
	cout<<"Account number                 -----> "<<account_number<<endl;
	cout<<"Phone number                   -----> "<<phone_num<<endl;
	cout<<"Account creation Date and Time -----> "<<date_of_creation<<endl;
	cout<<"Balance                        -----> "<<balance<<endl;
	
}
void Account::Bank_template_print()
{
	cout<<endl;
	cout<<"+----------------------------------------------------------------+"<<endl;
	cout<<"+ 1.Passbook                   |                  2.Details view +"<<endl;
	cout<<"+----------------------------------------------------------------+"<<endl;
	cout<<"+ 3.Atm services               |                  0.exit         +"<<endl;
	cout<<"+----------------------------------------------------------------+"<<endl;
}
void Account::Balance_check()
{
	cout<<endl<<"Available Balance ---> "<<balance<<endl;
}
void Account::Atm_menu_template()
{
	cout<<"Select choices and enter to make use of that services "<<endl;
	cout<<"+---------------------------------------------------------+"<<endl;
	cout<<"+ 1.Deposit                 |              2.Withdraw     +"<<endl;
	cout<<"+---------------------------------------------------------+"<<endl;
	cout<<"+ 3.change pin              |              4.Check Balance+"<<endl;
	cout<<"+---------------------------------------------------------+"<<endl;
	cout<<"+ 0.exit                    |              5.Transactions +"<<endl;
	cout<<"+---------------------------------------------------------+"<<endl;
}
void Account::Atm_service()
{
	int temp_pin,i=0;
	cout<<endl<<"Welcome saving mitra's Atm"<<endl;
	cout<<"Dear "<<name<<" you have activated atm services"<<endl;
	cout<<"Please enter the pin which you gave at the time of account registration or enter recent changed pin "<<endl<<endl;
	cout<<"enter pin ---> ";
	cin>>temp_pin;
	
	if(temp_pin==pin)
	{
		int choice;	
		while(i==0)
		{
		Atm_menu_template();
		cout<<"enter your option here---> ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				deposit();
				break;
			case 2:
				withdraw();
				break;
			case 3:
				change_pin();
				break;
			case 4:
				Balance_check();
				break;
			case 5:
				transactions();
				break;
			case 0:
				i=1;
				break;
			default:
				cout<<"Enter correct option "<<endl;
		}
		}
	}
	
}
Account::Account()
{
	int i=0,option;
	cout<<endl<<"Welcome to Saving mitra online Bank System"<<endl;
	create_account();
	balance=0;
	cout<<"Greetings "<<name<<" you have successfully registered with us ";
	cout<<endl<<"Now you are ready to go ";
	cout<<endl<<"here are some options, choose one ";
	while(i==0)
	{
		Bank_template_print();
		cout<<"Enter choice here-----> ";
		cin>>option;
		switch(option)
		{
			case 1:
				Passbook();
				break;
			case 2:
				Details();
				break;
			case 3:
				Atm_service();
				break;
			case 0:
				i=1;
				break;
			default:
				cout<<"Enter correct option "<<endl;
			
		}
	}
	
}
void Account::change_pin()
{
	int new_pin;
	cout<<endl<<"Enter new pin  --> ";
	cin>>new_pin;
	pin=new_pin;
}
void Account::create_account()
{
	cout<<endl<<"Hey user we think you are new to saving mitra,to join please give following details ";
	cout<<endl<<"Enter your name --> ";
	cin>>name;
	cout<<endl<<"Enter your age  --> ";
	cin>>age;
	cout<<endl<<"Enter your phone number ---> ";
	cin>>phone_num;
	cout<<endl<<"Enter your date of birth ----> ";
	cin>>date_of_birth;
	account_number="347687768777";
	time_t now = time(0);
	char* date_time = ctime(&now);
	date_of_creation=date_time;
	cout<<endl<<"Enter your pin, It will help to use authentication in Atm";
	cout<<endl<<"shh! dont share this to anyone, you can change it anytime"<<endl;
	cout<<"Enter pin ---> ";
	cin>>pin;
	balance=0.0;
}
void Account::deposit()
{
	float amountt;
	cout<<endl<<"Dear "<<name;
	cout<<endl<<"Enter the amount to deposit to your account ---> ";
	cin>>amountt;
	balance=balance+amountt;
	transaction_type.push_back(1);
	amount.push_back(amountt);
	time_t now = time(0);
	char* date_time = ctime(&now);
	date_and_time.push_back(date_time);

}
void Account::transactions()
{
	int i;
	cout<<endl<<"Previous Transactions done by "<<name<<endl;
	cout<<"|------------------------------------------------------------------|"<<endl;
	cout<<"|Transaction Type -------------Amount------------Date and time-----|"<<endl;
	for(i=0;i<amount.size();i++)
	{
	cout<<"|--";
	if(transaction_type[i]==1)
	{
		cout<<"Deposited------------";
	}
	else if(transaction_type[i]==2)
	{
		cout<<"Withdrawn------------";
	}
	cout<<amount[i]<<"--------";
	cout<<date_and_time[i]<<"------|"<<endl;
	}
	cout<<"|--------------------------------------------------------------------|"<<endl;
}
void Account::withdraw()
{
	float amountt;
	cout<<endl<<"Dear "<<name;
	cout<<endl<<"Enter the amount to withdraw from your account ---> ";
	cin>>amountt;
	if(balance>amountt)
	{
		balance=balance-amountt;
		transaction_type.push_back(2);
		amount.push_back(amountt);
		time_t now = time(0);
		char* date_time = ctime(&now);
		date_and_time.push_back(date_time);
	}
	else
	{
		cout<<endl<<"Insufficent Balance to withdraw"<<endl;
	}
}
int main()
{
	Account a;
}
