#include "Game.h"



#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;


void Game::getHelp()
{

	std::cout << "List of commands: \n-------------------------------\nThese commands can not be used when a menu (e.g. making a post) is open.\n\n 'h' - Brings the user to the homepage, showing them the 10 most recent posts on the app. \n 'p' - Allows the user to create a post, they are then prompted to enter a title and a body for the post, which can then be viewed including their id by other users. \n '0' - Exits the program.  -------------------------------\n\nFeatures explained\n-------------------------------\n Creating an account: When the program is first opened, the user is given the option to sign in or create an account, when creating an account you will be prompted to enter a 16 character or less username, and a 9 character or less password NOTE THAT IF YOUR USERNAME/PASSWORD IS HAS MORE CHARACTERS THAN ALLOWED, IT WILL BE TRUNCATED, AND THE ACCOUNT CREATED WITH DETAILS YOU DONT REMEMBER SO BE CAREFUL\n Signing in: using your username and password from before, enter your details as prompted.\n Commenting: In order to comment on another user's post, simply create one of your own with their post's id as your post's title. \n-------------------------------\n" << endl;

}

void Game::update()
{
	//prints to do list : )
	toDo();

	char decision;

	while (signedIn == false)
	{

		signIn();

	}

	std::cout << "Press 'h' to see the home page, press 'p' to create a new post, press '0' to exit the program, '?' to get help, 's' to search users, 'o' to search posts" << endl;
	std::cin >> decision;

	if (decision == 'h')
	{

		createHomePage();

	}

	else if (decision == 'p')
	{

		newPost();

	}

	else if (decision == '0')
	{

		//exits program

		running = false;

	}

	else if (decision == '?')
	{

		//displays help
		getHelp();

	}
	else if (decision == 's')

	{

		searchForUser();

	}
	else if (decision == 'o')

	{

		searchForPost();

	}


}

void Game::databaseConnect()
{

	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;

	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	//please create database "quickstartdb" ahead of time
	con->setSchema("socialnetwork");



	pstmt = con->prepareStatement("INSERT INTO user(username, password, description,image) VALUES(?,?,?,?)");

	string newBio = editBio();
	int newPic = choosePic();
	pstmt->setString(1, NewAccountUserName);
	pstmt->setString(2, NewAccountPassword);
	pstmt->setString(3, newBio);
	pstmt->setInt(4, newPic);
	pstmt->execute();
	cout << "One row inserted." << endl;

	delete pstmt;
	delete con;
	system("pause");

	//THE CODE WORKS

}

void Game::createHomePage()
{

	//gets 10 recent posts from database, displays in order, scrollable, searchable

	//individual post formatting

	std::cout << "-----------------------------------------------" << endl;







		sql::Driver* driver;
		sql::Connection* con;
		sql::Statement* stmt;
		sql::PreparedStatement* pstmt;
		sql::ResultSet* res;



		try
		{
			driver = get_driver_instance();
			con = driver->connect(server, username, password);
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}





		//please create database "quickstartdb" ahead of time
		con->setSchema("socialnetwork");


		//SELECT userid, username, password FROM user WHERE username = ? AND password = ?


		stmt = con->createStatement();

		res = stmt->executeQuery("SELECT * FROM post");




		while (res->next())
		{

			cout << "---------------------------------"<<endl;
			cout << res->getString("posttitle") << endl;
			cout << "---------------------------------"<<endl;
			cout << "Post ID: "<<res->getInt("postid") << endl;





			cout << "Poster ID: "<<res->getInt("userid") << endl;
			cout << res->getString("postbody") << endl;


			string thistitle = res->getString("postid");

			getReplies(thistitle);











			//when title is changed to getInt, it returns 0
			//potential error with type ?


			//  ^
			//  ^
			//body always results in 0 somehow despite throwing an error if a getInt is used instead of a getString?????? could mean it doesn't exist ? despite existing
			//otherwise everything else very succesfull
			// : )            \         /
			//             O        ?      O
			//                \________/
			//
			//               nvm it was an error in the schema
			//				still keeping my beautiful ASCII art
			//
			//

		}




		//exception thrown with res->getstring...




		std::cout << "DB succesfully checked" << endl;


		delete con;

		system("pause");





	}

	void Game::getReplies(string postid)
	{











		sql::Driver* driver1;
		sql::Connection* con1;
		sql::Statement* stmt1;
		sql::PreparedStatement* pstmt1;
		sql::ResultSet* res1;



		try
		{
			driver1 = get_driver_instance();
			con1 = driver1->connect(server, username, password);
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}





		//please create database "quickstartdb" ahead of time
		con1->setSchema("socialnetwork");


		//SELECT userid, username, password FROM user WHERE username = ? AND password = ?


		stmt1 = con1->createStatement();

		res1 = stmt1->executeQuery("SELECT * FROM post WHERE posttitle = '" + postid + "'");




		while (res1->next())
		{
			cout <<  "\n\nreplies: \n";

			cout << "---------------------------------" << endl;
			cout << "	Post ID: " << res1->getInt("postid") << endl;





			cout << "	Poster ID: " << res1->getInt("userid") << endl;
			cout << "	" << res1->getString("postbody") << endl;




			//the reply appears twice because it is also displayed as a regular post, this is probably fine? Only looks weird because reply is same as last post.

			//when title is changed to getInt, it returns 0
			//potential error with type ?


			//  ^
			//  ^
			//body always results in 0 somehow despite throwing an error if a getInt is used instead of a getString?????? could mean it doesn't exist ? despite existing
			//otherwise everything else very succesfull
			// : )            \         /
			//             O        ?      O
			//                \________/
			//
			//               nvm it was an error in the schema
			//				still keeping my beautiful ASCII art
			//
			//

		}




		//exception thrown with res->getstring...




		std::cout << "DB succesfully checked" << endl;


		delete con1;

		//system pause was making it necessary to enter key to continue, not needed but good to know.







	}

	//THE CODE WORKS




	//output post id (gotten from database)
	//output post title
	//output post body

	//in order to commen/reply to a post, create a new post using the original post's ID as the title
	//if a post has a title that is equal to another's id, display that post under the original




void Game::createNewAccount()
{

	//asks user to enter information and theinformation is added to the database as a new account

	std::cout << "Enter a username(16 chars): " << endl;
	std::cin >> NewAccountUserName;
	std::cout << "Enter a password(9 chars): " << endl;
	std::cin >> NewAccountPassword;



	databaseConnect();



}

void Game::signIn()
{

	char signInChoice;
	std::cout << "Press '1' to sign in, press '2' to make a new account." << endl;
	std::cin >> signInChoice;

	if (signInChoice == '1')
	{

		std::string AttemptuserName;
		std::string Attemptpassword;
		std::cout << "Enter your username: " << endl;
		std::cin >> AttemptuserName;
		std::cout << "Enter your password: " << endl;
		std::cin >> Attemptpassword;

		//function to check if this username and password match one on the database, if yes set sign in to true, sign in should default to false

		sql::Driver* driver;
		sql::Connection* con;
		sql::Statement* stmt;
		sql::PreparedStatement* pstmt;
		sql::ResultSet* res;




		try
		{
			driver = get_driver_instance();
			con = driver->connect(server, username, password);

			//block of code attempted
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
			//executes if try fails
		}





		//please create database "quickstartdb" ahead of time
		con->setSchema("socialnetwork");


		bool found = false;

		//SELECT userid, username, password FROM user WHERE username = ? AND password = ?


		stmt = con->createStatement();


		res = stmt->executeQuery("SELECT userid, username, password FROM user WHERE username = '" + AttemptuserName +"' AND password ='"+Attemptpassword+"'");






		while (res->next())
		{


			cout << "username: " << res->getString("username") << endl;


			std::string workingCheesePass = res->getString("password");
			cout << "password: " << res->getString("password") << endl;
			std::string workingCheeseName = res->getString("username");




			if (workingCheesePass == Attemptpassword)
			{

				signedIn = true;
				std::cout << signedIn;
				std::cout << "You are signed in as: " << res->getString("username");
				workingID = res->getInt("userid");

			}
			else
			{

				std::cout << "The username/password is incorrect" << endl;

			}

		}




		//exception thrown with res->getstring...




		std::cout << "DB succesfully checked" << endl;


		delete con;
		system("pause");

		//THE CODE WORKS


	}
	else
	{

		createNewAccount();


	}
	//asks user to enter username and password before signing in, this allows them to add posts etc, updates their state to logged in and posts are registered under their account


}

string Game::editBio()
{

	std::string bio;

	std::cout << "Enter your bio: " << "\n";

	cin.ignore();
	std::getline(std::cin, bio);

	return bio;

}

int Game::choosePic()
{

	int pic;

	std::cout << "Please choose which profile image you would like (1-6): " << "\n";

	cin.ignore();
	cin >> pic;


	return pic;
}

void Game::newPost()
{

	//user enters information, header and body, which is posted, others can then reply, user must be logged in, posts are tied to them.

	std::string body;
	std::string title;

	std::cout << "Enter the post title" << "\n";

	cin.ignore();
	std::getline(std::cin, title);




	std::cout << "Enter the post body" << "\n";
	std::getline(std::cin, body);



	//if a space is included in the input, the item after the space and before the next is input as the next cin statement

	//fixed with stupid c++ things

	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;




	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}



	//please create database "quickstartdb" ahead of time
	con->setSchema("socialnetwork");


	pstmt = con->prepareStatement("INSERT INTO post(userid,posttitle,postbody) VALUES(?,?,?)");

	pstmt->setInt(1, workingID);
	pstmt->setString(2, title);

	pstmt->setString(3, body);

	//in order to fix, convert all spaces to a "." before uploading and when downloading, convert all dots to spaces.


	pstmt->execute();
	cout << "One row inserted." << endl;

	delete pstmt;
	delete con;
	system("pause");

	//THE CODE WORKS


}

void Game::searchForUser()
{

	std::string searchTerm;



		std::cout << "Enter the name of the user you would like to search for: " << endl;
		std::cin >> searchTerm;




		sql::Driver* driver;
		sql::Connection* con;
		sql::Statement* stmt;
		sql::PreparedStatement* pstmt;
		sql::ResultSet* res;




		try
		{
			driver = get_driver_instance();
			con = driver->connect(server, username, password);

			//block of code attempted
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
			//executes if try fails
		}





		//please create database "quickstartdb" ahead of time
		con->setSchema("socialnetwork");


		bool found = false;

		//SELECT userid, username, password FROM user WHERE username = ? AND password = ?


		stmt = con->createStatement();


		res = stmt->executeQuery("SELECT image, userid, username, description FROM user WHERE username = '" + searchTerm + "'");






		while (res->next())
		{






			if (res->getString("username") == searchTerm)
			{


				std::cout << "Profile pic: " << res->getInt("image") << "\n" << res->getString("username") << "\n" << res->getInt("userid") << "\n" << res->getString("description") << "\n";

				//in sfml set the output pic texture to that corresponding to the int image, :)

			}
			else
			{

				std::cout << "No one with that name was found" << endl;

			}

		}




		//exception thrown with res->getstring...




		std::cout << "DB succesfully checked" << endl;


		delete con;
		system("pause");

		//THE CODE WORKS


}

void Game::searchForPost()
{

	//search for all posts with a certain keyword, then display in alphabetical order using bubble sort


	std::string searchTerm;



	std::cout << "Enter the keyword that you would like to search for (in posts): " << endl;
	std::cin >> searchTerm;




	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* res;




	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);

		//block of code attempted
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
		//executes if try fails
	}





	//please create database "quickstartdb" ahead of time
	con->setSchema("socialnetwork");


	bool found = false;

	//SELECT userid, username, password FROM user WHERE username = ? AND password = ?


	stmt = con->createStatement();


	res = stmt->executeQuery("SELECT posttitle, postid,userid, postbody FROM post WHERE posttitle LIKE '%" + searchTerm + "%'");



	//use 2d array to store all the parts of the result, then bubble sort with that array then display, ez!



	std::vector<results> resultVector;

	int indexThing = 0;
	while (res->next())
	{







		 results newResult = {};

		 newResult.resposttitle = res->getString("posttitle"); newResult.respostid = res->getInt("postid"); newResult.resuserid = res->getInt("userid"); newResult.respostbody = res->getString("postbody");

		resultVector.push_back(newResult);
				//in sfml set the output pic texture to that corresponding to the int image, :)
				indexThing++;
				//suspect the issue may be to do with a string being initialized as an int 0
	}

	resultVector = bubbleSort(resultVector);


	for (int i = 0; i < sizeof(resultVector); i++)
	{

		std::cout << "Matching posts: \n" << resultVector[i].resposttitle<< "\n" << resultVector[i].respostid<< "\n"<< resultVector[i].resuserid << "\n"<< resultVector[i].respostbody << endl;

	}


	std::cout << "DB succesfully checked" << endl;


	delete con;



}

vector<Game::results> Game::bubbleSort(vector<results> resultVector)
{






	//loop over vector,check if vector at position index's position 0 (posttitle) is

	bool swapped = true;

	int j = 0;

	while (swapped)
	{

		swapped = false;
		++j;


		for (int i = 0; i < resultVector.size() - j; i++)
		{




				std::vector<results> storage = {};
				if (resultVector[i].resposttitle.compare(resultVector[i + 1].resposttitle) > 0)
					//if(resultVector[i].resposttitle > (resultVector[i + 1].resposttitle))
				{

					storage.push_back(resultVector[i]);
					resultVector[i] = resultVector[i + 1];

					resultVector[i + 1] = storage[0];

					swapped = true;
				}

		}
	}
	return resultVector;

}


void Game::toDo()
{
	if (todo == false)

	{
		std::cout << "TODO: " << endl;



		todo = true;
	}










}
