/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:29:38 by cejin             #+#    #+#             */
/*   Updated: 2024/11/28 19:21:20 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "ICharacter.hpp"
# include "MateriaSource.hpp"

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

# define FLOOR_SPACE 10

/*
Handle the Materias your character left on the floor as you like.
Save the addresses before calling unequip(), or anything else, but
don’t forget that you have to avoid memory leaks.

The use(int, ICharacter&) member function will have to use the Materia at the
slot[idx], and pass the target parameter to the AMateria::use function
*/

/*
During copy, the Materias of a Character must be deleted before the new ones are added
to their inventory. Of course, the Materias must be deleted when a Character is destroyed
*/

class Character : public ICharacter
{
private:
    std::string name;
	AMateria   *inventory[INVENTORY_SIZE];
    AMateria  *floor[FLOOR_SPACE];

public:
	Character();
    Character(const Character &src);
	Character &operator=(const Character &src);
	Character(std::string const &name);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx); //must NOT delete the AMateria
	void use(int idx, ICharacter& target);
        //call use from cure/ice ?

    void getFullInventory() const;
    void getInventoryById(int idx);
};
