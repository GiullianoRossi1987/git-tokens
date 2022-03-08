#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include "./Tokens.h"


void database::Tokens::scrapper(){
	std::vector<std::string> lines;
	std::string l_b;
	std::fstream f_db;
	f_db.open(this->f_db);
	while(getline(f_db, l_b))
		lines.push_back(l_b);
	int exp_data = 0;  // if 0 it expects a new entrance, if 1 it expects the token data, if 2 it expects the token's 'expiration date
	Token per;
	for(std::string line : lines){
		if(exp_data == 0){
			if(line.compare("\n") != 0 && line.substr(0, 1).compare("\t") != 0){
				// if the return is 1, that means it's not a empty line
				per.name = line.substr(0, line.find_first_of("\n"));
				std::cout << line << std::endl;
				exp_data = 1;
			}
		}
		else{
			if(line.substr(0, 1).compare("\t") == 0){
				std::string data = line.substr(1);
				if(exp_data == 1){
					per.token = data;
					exp_data = 2;
				}
				else{
					// then it's equal 2
					per.s_exp_date = data;
					this->tokens.push_back(per);
					per.name = "";
					per.token = "";
					per.s_exp_date = "";
					exp_data = 0;
				}
			}
		}
	}
}

bool database::Tokens::token_exists(const std::string & name_t){
	bool ex = false;
	for(database::Tokens::Token tk : this->tokens){
		if(!name_t.compare(tk.name)){
			ex = true;
			break;
		}
	}
	return ex;
}

database::Tokens::Tokens(const std::string& db){
	this->f_db = db;
	this->scrapper();
}

std::vector<database::Tokens::Token> database::Tokens::getTokens(){
	return this->tokens;
}

void database::Tokens::save(){
	std::string poll = "";
	for(database::Tokens::Token t : this->tokens){
		std::string tk_str = t.name + "\n\t" + t.token + "\n\t" + t.s_exp_date;
		poll += tk_str + "\n";
	}
	std::ofstream fd(this->f_db, std::ofstream::trunc);
	fd << poll;
}

void database::Tokens::add_token(Token tk){
	if(!this->token_exists(tk.name)){
		this->tokens.push_back(tk);
	}
}

void database::Tokens::add_token(const std::string& name, const std::string& tk, const std::string& dt){
	if(!this->token_exists(name)){
		Token tt;
		tt.name = name;
		tt.token = tk;
		tt.s_exp_date = dt;
		this->tokens.push_back(tt);
	}
}

void database::Tokens::del_token(const std::string& name_t){
	if(this->token_exists(name_t)){
		std::vector<database::Tokens::Token> ndb;
		for(database::Tokens::Token item : this->tokens){
			if(item.name.compare(name_t) != 0)
				ndb.push_back(item);
		}
		this->tokens = ndb;
	}
	else{
		std::cerr << "Token " << name_t << " Not found" << std::endl;
		throw;
	}
}

void database::Tokens::upd_token(const std::string& name_t, Token new_data){
	if(this->token_exists(name_t)){
		std::vector<database::Tokens::Token> ndb;
		for(database::Tokens::Token item : this->tokens){
			if(!item.name.compare(name_t))
				ndb.push_back(new_data);
		}
		this->tokens = ndb;
	}
	else{
		std::cerr << "Token " << name_t << " Not found" << std::endl;
		throw;
	}
}



