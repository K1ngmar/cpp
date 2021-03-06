
#ifndef SORCERER_H
# define SORCERER_H

#include <iostream>
#include <string>

class Victim;
class Peon;

class Sorcerer
{
	private:
		Sorcerer();
		std::string _name;
		std::string _title;
	public:
		Sorcerer(std::string n, std::string t);
		virtual ~Sorcerer();
		Sorcerer(const Sorcerer &copy);
		Sorcerer 	&operator = (const Sorcerer &s );
		std::string	getName() const;
		std::string	getTitle() const;
		void 		polymorph(Victim const &target) const;
};

std::ostream	&operator << (std::ostream &out, const Sorcerer &tbp);

#endif
