#ifndef H_GIT
#define H_GIT
#include <string>
#include <vector>
#include "./database/Tokens.cpp"

namespace git{
	class Git{
		public:
		struct Remote{
			std::string name;
			std::string url;
			std::string fetch;
		};
		
		struct Branch{
			std::string name;
			std::string remote_name;
			std::string merge;
		};

		private:
		std::string config_full_path;
		bool loaded_file = false;
		std::vector<Remote> remotes;
		std::vector<Branch> branches;

		public:

	};
}

#endif
