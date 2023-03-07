#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

int Position = 0;
int Count = 0;
int RepoCount = 0;
int RepoPosition = 0;
int FeedCount = 0;
int ComplainCount = 0;
int RepoNameCount = 0;

string Email[1000];
string Password[1000];
string RepoName[1000];
string RepoType[1000];
string RepoScript[1000];
string Feed[1000];
string Time[1000];
string Date[1000];
string Complain[1000];

void LoadFiles();
void LoadData();
void Logo00();
void Logo01();
void Logo02();
void Logo03();
void Logo04();
void Logo05();

void SignUp();
void LogIn();

void Home();
void MainMenu();
void AdminMenu();

void AccountDetails();
void AccountOptions();

void NewRepositoryForAdmin();
void NewRepositoryForUsers();
void ViewRepositoryForAdmin();
void ViewRepositoryForUsers();
void DeleteRepository();

void Feedback();
void ViewFeedbacks();

void Complaint();
void ViewComplaints();

void Survey();
void Subscribtion();
void LogOut();

int main()
{
	LoadFiles();
	LoadData();
	while(true)
	{
		Logo00();
		int Position = 0;
		string Choice;
		cout  <<  "            1. SignUp"  <<  endl;
		cout  <<  "            2. LogIn"  <<  endl;
		cout  <<  "            3. Exit"  <<  endl  <<  endl;
		cout  <<  "        Enter Your Choice: ";
		cin  >>  Choice;
		if(Choice == "1")
		{
			SignUp();
		}
		else if(Choice == "2")
		{
			LogIn();
		}
		else if(Choice == "3")
		{
			break;
		}
		else
		{
			system("cls");
			Logo00();
			cout  <<  "           Invalid Choice !!!"  <<  endl;
			Sleep(3000);
		}
	}
}
void LoadFiles()
{
	fstream UserAndCode;
	UserAndCode.open("UsernameAndPassword.txt",ios::app);
	UserAndCode  <<  "waah805@gmail.com"  <<  endl;
	UserAndCode  <<  "LP-Gangster"  <<  endl;
	UserAndCode.close();
	fstream Repository;
	Repository.open("Repositories.txt",ios::app);
	Repository.close();
	fstream Feedback;
	Feedback.open("Feedbacks.txt",ios::app);
	Feedback.close();
	fstream Complaint;
	Complaint.open("Complaints.txt",ios::app);
	Complaint.close();
}
void LoadData()
{
	fstream UserAndCode;
	UserAndCode.open("UsernameAndPassword.txt",ios::in);
	while(!UserAndCode.eof())
	{
		string UserData;
		getline(UserAndCode,UserData);
		Email[Count] = UserData;
		getline(UserAndCode,UserData);
		Password[Count] = UserData;
		Count++;
	}
	UserAndCode.close();
	fstream Repository;
	Repository.open("Repositories.txt",ios::in);
	while(!Repository.eof())
	{
		string RepoData;
		getline(Repository,RepoData);
		RepoName[RepoCount] = RepoData;
		getline(Repository,RepoData);
		RepoType[RepoCount] = RepoData;
		getline(Repository,RepoData);
		Time[RepoCount] = RepoData;
		getline(Repository,RepoData);
		Date[RepoCount] = RepoData;
		getline(Repository,RepoData);
		RepoScript[RepoCount] = RepoData;
		RepoCount++;
	}
	Repository.close();
	fstream Complaint;
	Complaint.open("Complaints.txt",ios::in);
	while(!Complaint.eof())
	{
		string UserComplaint;
		getline(Complaint,UserComplaint);
		Complain[ComplainCount] = UserComplaint;
		ComplainCount++;
	}
	Complaint.close();
	fstream Feedback;
	Feedback.open("Feedbacks.txt",ios::in);
	while(!Complaint.eof())
	{
		string UserFeedback;
		getline(Feedback,UserFeedback);
		Feed[FeedCount] = UserFeedback;
		FeedCount++;
	}
	Feedback.close();
}
void Logo00()
{
	system("cls");
	cout  <<  "###################################"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "#@ * * Welcome to BLACK HOLE * * @#"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "###################################"  <<  endl  <<  endl;
}
void Logo01()
{
	system("cls");
	cout  <<  "###################################"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "#@ * * Welcome to BLACK MENU * * @#"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "###################################"  <<  endl  <<  endl;
}
void Logo02()
{
	system("cls");
	cout  <<  "###################################"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "#@ * Welcome to BLACK  ACCOUNT * @#"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "###################################"  <<  endl  <<  endl;
}
void Logo03()
{
	system("cls");
	cout  <<  "###################################"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "#@ * * Welcome to BLACK REPO * * @#"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "###################################"  <<  endl  <<  endl;
}
void Logo04()
{
	system("cls");
	cout  <<  "###################################"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "#@ * * Welcome to BLACK FEED * * @#"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "###################################"  <<  endl  <<  endl;
}
void Logo05()
{
	system("cls");
	cout  <<  "###################################"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "#@ * Welcome to BLACK COMPLAIN * @#"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "###################################"  <<  endl  <<  endl;
}
void SignUp()
{
	Logo00();
	fstream UserAndCode;
	UserAndCode.open("UsernameAndPassword.txt",ios::app);
	bool Found = false;
	cout  <<  "Example: ******@GMAIL.COM"  <<  endl;
	cout  <<  endl;
	cout  <<  "Enter your desired E-mail: ";
	cin  >>  Email[Count];
	for(int i = 0;i < Count;i++)
	{
		if(Email[i] == Email[Count])
		{
			Logo00();
			Found = true;
			cout  <<  "Username Already Exists.";
			Sleep(3000);
		}
	}
	if(Found == false)
	{
		UserAndCode  <<  Email[Count]  <<  endl;
		Logo00();
		cout  <<  "Enter your desired Password: ";
		cin  >>  Password[Count];
		UserAndCode  <<  Password[Count]  <<  endl;
		Count++;
		UserAndCode.close();
	}
}
void LogIn()
{
	Logo00();
	Position = 0;
	string ID;
	string Code;
	bool Admin = false;
	bool AARC = false;
	bool User = false;
	bool Key = false;
	int i = 0;
	cout  <<  "Username or E-mail: ";
	cin  >>  ID;
	for(i = 0;i < 1000;i++)
	{
		if(ID != "waah805@gmail.com")
		{
			if(ID == Email[i])
			{
				User = true;
				cout  <<  "Password: ";
				cin  >>  Code;
				if(Code == Password[i])
				{
					Key = true;
					break;
				}
			}
			else
			{
				Position++;
			}
		}
		if(ID == "waah805@gmail.com")
		{
			Logo00();
			cout  <<  "     WELCOME ADMIN!!!";
			Admin = true;
			Sleep(5000);
			Logo00();
			cout  <<  "Please enter AARC (Admin Authority Recognition Code): ";
			cin  >>  Code;
			if(Code == "LP-Gangster")
			{
				AARC = true;
				break;
			}
			else
			{
				break;
			}
		}
	}
	if(ID != "waah805@gmail.com")
	{
		if(User == false)
		{
			Logo00();
			cout  <<  "INVALID USER ID."  <<  endl;
			Sleep(3000);
		}
		else if(User ==  true && Key == false)
		{
			Logo00();
			cout  <<  "INVALID PASSWORD."  <<  endl;
			Sleep(3000);
		}
		else if(User == true && Key == true)
		{
			Home();
		}
	}
	if(ID == "waah805@gmail.com")
	{
		if(Admin ==  true && AARC == false)
		{
			Logo00();
			cout  <<  "          INVALID AARC."  <<  endl;
			Sleep(3000);
		}
		else if(Admin == true && AARC == true)
		{
			AdminMenu();
		}
		
	}
}
void Home()
{
	Logo00();
	string Choice;
	cout  <<  "      1. Visit Main Menu"  <<  endl;
	cout  <<  "      2. Logout"  <<  endl;
	cout  <<  endl;
	cout  <<  "      Enter Your Choice: ";
	cin  >>  Choice;
	if(Choice == "1")
	{
		MainMenu();
	}
	else if(Choice == "2")
	{
		LogOut();
	}
	else
	{
		Logo00();
		cout  <<  "        Invalid Choice."  <<  endl;
		Sleep(3000);
		Home();
	}
}
void MainMenu()
{
	Logo01();
	string Choice;
	cout  <<  "Which HOLE do you want to Access?"  <<  endl  <<  endl;
	cout  <<  "1. View Account Details"  <<  endl;
	cout  <<  "2. Create New Repository"  <<  endl;
	cout  <<  "3. View Existing Repositories"  <<  endl;
	cout  <<  "4. Delete Existing Repositories"  <<  endl;
	cout  <<  "5. Send Feedback"  <<  endl;
	cout  <<  "6. Send Complaint"  <<  endl;
	cout  <<  "7. Perform Survey"  <<  endl;
	cout  <<  "8. Subscribtions"  <<  endl;
	cout  <<  "9. Logout"  <<  endl  <<  endl;
	cout  <<  "        Enter your Choice: ";
	cin  >>  Choice;
	if(Choice  ==  "1")
	{
		AccountDetails();
	}
	else if(Choice  ==  "2")
	{
		NewRepositoryForUsers();
	}
	else if(Choice  ==  "3")
	{
		ViewRepositoryForUsers();
	}
	else if(Choice  ==  "4")
	{
		DeleteRepository();
	}
	else if(Choice  ==  "5")
	{
		Feedback();
	}
	else if(Choice  ==  "6")
	{
		Complaint();
	}
	else if(Choice  ==  "7")
	{
		Survey();
	}
	else if(Choice  ==  "8")
	{
		Subscribtion();
	}
	else if(Choice  ==  "9")
	{
		LogOut();
	}
	else
	{
		Logo01();
		cout  <<  "        INVALID CHOICE.";
		Sleep(3000);
		MainMenu();
	}
}
void AdminMenu()
{
	Logo01();
	string Choice;
	cout  <<  "Which HOLE do you want to Access?"  <<  endl  <<  endl;
	cout  <<  "1. View Account Details"  <<  endl;
	cout  <<  "2. Create New Repository"  <<  endl;
	cout  <<  "3. View Existing Repositories"  <<  endl;
	cout  <<  "4. Delete Existing Repositories"  <<  endl;
	cout  <<  "5. View Feedbacks"  <<  endl;
	cout  <<  "6. View Complaints"  <<  endl;
	cout  <<  "7. Conduct Surveys"  <<  endl;
	cout  <<  "8. Logout"  <<  endl  <<  endl;
	cout  <<  "      Enter your Choice: ";
	cin  >>  Choice;
	if(Choice  ==  "1")
	{
		AccountDetails();
	}
	else if(Choice  ==  "2")
	{
		NewRepositoryForAdmin();
	}
	else if(Choice  ==  "3")
	{
		ViewRepositoryForAdmin();
	}
	else if(Choice  ==  "4")
	{
		DeleteRepository();
	}
	else if(Choice  ==  "5")
	{
		ViewFeedbacks();
	}
	else if(Choice  ==  "6")
	{
		ViewComplaints();
	}
	else if(Choice  ==  "7")
	{
		Survey();
	}
	else if(Choice  ==  "8")
	{
		LogOut();
	}
	else
	{
		Logo01();
		cout  <<  "         INVALID CHOICE.";
		Sleep(3000);
		AdminMenu();
	}
}
void AccountDetails()
{
	Logo02();
	char Choice;
	cout  <<  "     Account Name: "  <<  Email[Position]  <<  endl;
	cout  <<  "     Current Password: "  <<  Password[Position]  <<  endl;
	cout  <<  endl;
	cout  <<  "Enter any single Key for further options: ";
	cin  >>  Choice;
	AccountOptions();
}
void AccountOptions()
{
	Logo02();
	string ID;
	string Code;
	string Choice;
	cout  <<  "     1. Change Account Name "  <<  endl;
	cout  <<  "     2. Change Account Password "  <<  endl;
	cout  <<  "     3. Go Back to Black Menu "  <<  endl  <<  endl;
	cout  <<  "          Enter your choice: ";
	cin  >>  Choice;
	if(Choice == "1")
	{
		Logo02();	
		cout  <<  "   Confirm previous account name: ";
		cin  >>  ID;
		if(ID == Email[Position])
		{
			Logo02();
			cout  <<  "   Enter new E-mail: ";
			cin  >>  Email[Position];
			Logo02();
			cout  <<  "  Saving Changes.Please wait!";
			Sleep(3000);
			MainMenu(); 
		}
		else
		{
			Logo01();
			cout  <<  "   !WRONG ATTEMPT!"  <<  endl;
			Sleep(3000);
			AccountOptions();
		}
	}
	else if(Choice == "2")
	{
		Logo02();
		cout  <<  "   Confirm previous account password: ";
		cin  >>  Code;
		if(Code == Password[Position])
		{
			Logo02();
			cout  <<  "     Enter new Password: ";
			cin  >>  Password[Position];
			Logo02();
			cout  <<  "  Saving Changes.Please wait!";
			Sleep(3000);
			MainMenu();
		}
		else
		{
			system("cls");
			Logo02();
			cout  <<  "     !WRONG ATTEMPT!"  <<  endl;
			Sleep(3000);
			AccountOptions();
		}
	}
	else if(Choice == "3")
	{
		MainMenu();	
	}
	else
	{
		Logo02();
		cout  <<  "     INVALID CHOICE.";
		Sleep(3000);
		AccountOptions();
	}
}
void NewRepositoryForUsers()
{
	Logo03();
	fstream Repository;
	Repository.open("Repositories.txt",ios::app);
	cout  <<  "Enter repository name: ";
	cin  >>  RepoName[RepoCount];
	Repository  <<  RepoName[RepoCount]  <<  endl;  
	cout  <<  "Enter repository type: ";
	cin  >>  RepoType[RepoCount];
	Repository  <<  RepoType[RepoCount]  <<  endl;
	cout  <<  endl;
	Logo03();
	cout  <<  "NOTE !!! Enter time in given format = Hours:Minutes:AM or PM"  <<  endl  <<  endl;
	cout  <<  "Enter repository creation time: ";
	cin  >>  Time[RepoCount];
	Repository  <<  Time[RepoCount]  <<  endl  <<  endl;
	Logo03();
	cout  <<  "NOTE !!! Enter date in given format = DDMMYYYY"  <<  endl;
	cout  <<  "Enter repository creation date: ";
	cin  >>  Date[RepoCount];
	Repository  <<  Date[RepoCount]  <<  endl;
	Logo03();
	cout  <<  "Write any data depending on your given repository name."  <<  endl  <<  endl;
	cin.ignore();
	getline(cin,RepoScript[RepoCount]);
	Repository  <<  RepoScript[RepoCount]  <<  endl;
	RepoCount++;
	Logo02();
	cout  <<  "Saving Document. Please Wait!";
	Sleep(5000);
	MainMenu();
}
void NewRepositoryForAdmin()
{
	Logo03();
	fstream Repository;
	Repository.open("Repositories.txt",ios::app);
	cout  <<  "Enter repository name: ";
	cin  >>  RepoName[RepoCount];
	Repository  <<  RepoName[RepoCount]  <<  endl;  
	cout  <<  "Enter repository type: ";
	cin  >>  RepoType[RepoCount];
	Repository  <<  RepoType[RepoCount]  <<  endl;
	cout  <<  endl;
	Logo03();
	cout  <<  "NOTE !!! Enter time in given format = Hours:Minutes:AM or PM"  <<  endl  <<  endl;
	cout  <<  "Enter repository creation time: ";
	cin  >>  Time[RepoCount];
	Repository  <<  Time[RepoCount]  <<  endl  <<  endl;
	Logo03();
	cout  <<  "NOTE !!! Enter date in given format = DDMMYYYY"  <<  endl;
	cout  <<  "Enter repository creation date: ";
	cin  >>  Date[RepoCount];
	Repository  <<  Date[RepoCount]  <<  endl;
	Logo03();
	cout  <<  "Write any data depending on your given repository name."  <<  endl  <<  endl;
	cin.ignore();
	getline(cin,RepoScript[RepoCount]);
	Repository  <<  RepoScript[RepoCount]  <<  endl;
	RepoCount++;
	Logo02();
	cout  <<  "Saving Document. Please Wait!";
	Sleep(5000);
	AdminMenu();
}
void ViewRepositoryForAdmin()
{
	Logo03();
	string Name;
	char Choice;
	bool Found = false;
	cout  <<  "Enter a Repository Name: ";
	cin  >>  Name;
	for(int i = 0;i < 1000;i++)
	{
		if(Name == RepoName[i])
		{
			Found = true;
			break;
		}
		else
		{
			RepoPosition++;
		}
	}
	if(Found == true)
	{
		Logo03();
		cout  <<  "Repository Name: "  <<  RepoName[RepoPosition]  <<  endl;
		cout  <<  "Repository Type: "  <<  RepoType[RepoPosition]  <<  endl;
		cout  <<  "Repository creation Date: "  <<  Date[RepoPosition]  <<  endl;
		cout  <<  "Repository creation Time: "  <<  Time[RepoPosition]  <<  endl  <<  endl;
		cout  <<  RepoScript[RepoPosition]  <<  endl  <<  endl;
		cout  <<  "Enter any key to continue: ";
		cin  >>  Choice;
		AdminMenu();
	}
	else if(Found == false)
	{
		Logo03();
		cout  <<  "REPOSITORY NAME NOT FOUND."  <<  endl;
		Sleep(3000);
		AdminMenu();
	}
}
void ViewRepositoryForUsers()
{
	Logo03();
	string Name;
	char Choice;
	bool Found = false;
	cout  <<  "Enter a Repository Name: ";
	cin  >>  Name;
	for(int i = 0;i < 1000;i++)
	{
		if(Name == RepoName[i])
		{
			Found = true;
			break;
		}
		else
		{
			RepoPosition++;
		}
	}
	if(Found == true)
	{
		Logo03();
		cout  <<  "Repository Name: "  <<  RepoName[RepoPosition]  <<  endl;
		cout  <<  "Repository Type: "  <<  RepoType[RepoPosition]  <<  endl;
		cout  <<  "Repository creation Date: "  <<  Date[RepoPosition]  <<  endl;
		cout  <<  "Repository creation Time: "  <<  Time[RepoPosition]  <<  endl  <<  endl;
		cout  <<  RepoScript[RepoPosition]  <<  endl  <<  endl;
		cout  <<  "Enter any key to continue: ";
		cin  >>  Choice;
		MainMenu();
	}
	else if(Found == false)
	{
		Logo03();
		cout  <<  "REPOSITORY NAME NOT FOUND."  <<  endl;
		Sleep(3000);
		MainMenu();
	}
}
void DeleteRepository()
{
	Logo03();
	cout  <<  "This function is suspended till next update.";
	Sleep(3000);
	MainMenu();
}
void Feedback()
{
	Logo04();
	fstream Feedback;
	Feedback.open("Feedbacks.txt",ios::app);
	cout  <<  "Comment about our application to let us think what do you think of its working."  <<  endl  <<  endl;
	cin.ignore();
	getline(cin,Feed[FeedCount]);
	Feedback  <<  Feed[FeedCount];
	Logo04();
	cout  <<  "Saving FeedBack. Please Wait!";
	Sleep(5000);
	Feedback.close();
	FeedCount++;
	MainMenu();
}
void ViewFeedbacks()
{
	string Feedbacks;
	int Count = 0;
	string Choice;
	fstream Feedback;
	Feedback.open("Feedbacks.txt",ios::in);
	system("cls");
	Logo04();
	while(!Feedback.eof())
	{
		getline(Feedback,Feedbacks);
		cout  <<  Feedbacks  <<  endl  <<  endl;
		Count++;
	}
	cout  <<  "Enter any key to continue: ";
	cin  >>  Choice;
	Feedback.close();
	AdminMenu();
}
void Complaint()
{
	Logo05();
	fstream Complaint;
	Complaint.open("Complaints.txt",ios::app);
	cout  <<  "Comment us if you are having problems while using our application."  <<  endl  <<  endl;
	cin.ignore();
	getline(cin,Complain[ComplainCount]);
	Complaint  <<  Complain[ComplainCount]  <<  endl;
	system("cls");
	Logo05();
	cout  <<  "Saving Complaint. Please Wait!";
	Sleep(5000);
	ComplainCount++;
	Complaint.close();
	MainMenu();
}
void ViewComplaints()
{
	string Complaints;
	int Count = 0;
	string Choice;
	fstream Complaint;
	Complaint.open("Complaints.txt",ios::in);
	Logo05();
	while(!Complaint.eof())
	{
		getline(Complaint,Complaints);
		cout  <<  Complaints  <<  endl;
		Count++;
	}
	cout  <<  "Enter any key to continue: ";
	cin  >>  Choice;
	Complaint.close();
	AdminMenu();
}
void Survey()
{
	system("cls");
	cout  <<  "###################################"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "#@  * Welcome to BLACK SURVEY *  @#"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "###################################"  <<  endl;
	cout  <<  endl;	
	cout  <<  "This function is suspended till next update.";
	Sleep(3000);
	MainMenu();
}
void Subscribtion()
{
	system("cls");
	cout  <<  "####################################"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "#@ Welcome to BLACK Subscribtions @#"  <<  endl;
	cout  <<  "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#"  <<  endl;
	cout  <<  "####################################"  <<  endl;
	cout  <<  endl;
	cout  <<  "This function is suspended till next update.";
	Sleep(3000);
	MainMenu();
}
void LogOut()
{
	cout  <<  endl;
}