
#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *learned[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource &ms);
		MateriaSource	&operator = (const MateriaSource &s);
		void		learnMateria(AMateria* toLearn);
		AMateria*	createMateria(std::string const & type);
};

#endif
