#pragma once

#include <iostream>
#include <string>
#include <map>
#include "SpellBook.hpp"
#include "ASpell.hpp"
class ASpell;
class Warlock
{
private:
	std::string name;
	std::string title;
	Warlock();
	Warlock &operator=(Warlock const &other);
	Warlock(Warlock const &other);

	// std::map<std::string, ASpell*> arr;
	SpellBook book;

public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();

	std::string const &getName() const;
	std::string const &getTitle() const;

	void setTitle(std::string const &title);
	void introduce() const;

	void learnSpell(ASpell *ptr);
	void forgetSpell(std::string name);
	void launchSpell(std::string name, ATarget const &tar_ref);
};

