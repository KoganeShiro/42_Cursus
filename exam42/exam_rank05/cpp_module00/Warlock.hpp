
#include  <iostream>
#include <ostream>

class Warlock
{
	private:
		std::string name;
		std::string title;
	
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		void	introduce() const;
		void	setTitle(std::string const &title);
		std::string getName() const;
		std::string getTitle() const;
		

};
