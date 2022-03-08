#ifndef H_GIT_BRANCH
#define H_GIT_BRANCH
#include <string>
#include <vector>

namespace git{
	class Branch{
		public:
		std::string name;
		std::string remote_name;
		std::string merge;

		Branch(const std::string& name, const std::string& remote_name, const std::string& merge);

		Branch(const std::string& config);

		void tokenize(const std::string& token);
		
		std::string to_string();

	};
}
#endif
