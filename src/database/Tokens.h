#ifndef H_TOKENS
#define H_TOKENS
#include <iostream>
#include <string>
#include <vector>
#include <regex>

namespace database{
	class Tokens{
		public:
			struct Token{
				std::string name;
				std::string token;
				std::string s_exp_date;
			};
		private:
			std::vector<Token> tokens;
			std::string f_db;

			void scrapper();

			bool token_exists(const std::string& name_t);
		public:
			
			Tokens(const std::string& db);
			
			void add_token(Token tk);

			void add_token(const std::string& name, const std::string& tk, const std::string& dt);

			void del_token(const std::string& name_t);

			void upd_token(const std::string& name_t, Token new_data);

			std::vector<Token> getTokens();

			void save();
	};
}


#endif
