#pragma once
#include <unordered_map>
#include <iostream>
#include <string>

class c_globals {
public:
	
	bool active = true;
	char user_name[255] = "pollo";
	char pass_word[255] = "123";
	char key[255] = "key";
	bool triggerbot = false;
	bool showLogin = true;
	bool showMenu = false;
	bool showAccInfo = false;
	bool showRegister = false;

	std::string status = "...";
	std::string registerStatus = "...";



};

inline c_globals globals;