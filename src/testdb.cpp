#include <iostream>
#include <vector>
#include "./database/Tokens.cpp"

int main(){
	database::Tokens tk("tests/test.db");
	std::cout << "Constructor tests passed!" << std::endl;
	std::vector<database::Tokens::Token> db = tk.getTokens();
	for(database::Tokens::Token t : db){
		std::cout << t.token << std::endl;
	}
	tk.add_token("Test 2", "assdgjdfn", "2022-03-04");
	for(database::Tokens::Token t : tk.getTokens())
		std::cout << t.name << std::endl;
	tk.save();
	return 0;
}
