#include<iostream>
#include<conio.h>
#include<string>
#include"struct.h"

using namespace std;



bool Comparison(gitHubUser user1, gitHubUser user2)//This function is for comparing usernames of two users
{
	if (user1.firstName == user2.firstName);
	else return false;
	if (user1.userName == user2.userName);
	else return false;
	if (user1.password == user2.password);
	else return false;
	if (user1.email == user2.email);
	else return false;
	return true;
}
bool exists(gitHubUser* users, int size, string userName)//this function check if the username exists in the database/already exist
{
	for (int i = 0; i < size; i++)
	{
		if (users[i].userName == userName)
			return true;
	}
	return false;
}

void inputFromUser(gitHubUser*users, int size)//this function get input from user and store it but the username must be different
{
	string Username;
	for (int i = 0; i < size; i++)
	{
		cout <<endl<< "User # " << i + 1<<endl<<endl;
		cout << "First Name" << endl;
		cin >> users[i].firstName;
		cout << "User Name" << endl;
		cin >> Username;
		while (exists(users, size, Username))
		{
			cout << "This userName already exists, enter another userName" << endl;
			cout << "User Name" << endl;
			cin >> Username;
		}
		users[i].userName = Username;
		cout << "Password" << endl;
		cin >> users[i].password;
		cout << " Email" << endl;
		cin >> users[i].email;
		
		
	}
}
gitHubUser*searchUser(gitHubUser* users, int size, string userName)// this function search the whole array of users and output the adress of the pointer
{
	int i = 0,index=0;
	bool find = false;
	for (i; i < size&&find==false; i++)
	{
		if (users[i].userName == userName)
		{
			find = true;
			index = i;
		}
	}
	if (find = true)
		cout<< "Adress of the User name in from database" << &users[index];

}

int main()
{
	int size = 4;
	string Username;
	gitHubUser*users = new gitHubUser[size];
	inputFromUser(users, size);

	cout << "Enter user name to search.";
	cin >> Username;
	searchUser(users, size, Username);

	// For Comaring two users information.

	/*if (Comparison(user[0], user[1]))
		cout << "Same";
	else cout << "Not Same";*/
	delete[] users;
	_getch();

}