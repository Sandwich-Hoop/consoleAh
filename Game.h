#pragma once



#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;




#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:

public:

	bool signedIn = false;

	//lord fisslewick flanders


	bool running = true;
	const string server = "tcp://127.0.0.1:3306";
	const string username = "root";
	const string password = "root";

	std::string NewAccountUserName;
	std::string NewAccountPassword;

	struct results {

		string resposttitle;
		int respostid;
		int resuserid;
		string respostbody;


	};


	int workingID;
	//general



	void getHelp();


	void update();



	//home page

	void createHomePage();

	void getReplies(string postid);


	//personal account
	void createNewAccount();
	void signIn();
	string editBio();
	int choosePic();
	//createing account V

	void databaseConnect();

	//posting

	void newPost();

	//Searching

	void searchForUser();
	void searchForPost();
	vector<results> bubbleSort(vector<results> resultVector);


	//TODO

	void toDo();

	bool todo = false;
};
