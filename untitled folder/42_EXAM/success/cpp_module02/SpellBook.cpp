#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::~SpellBook()
{
	std::map<std::string, ASpell*>::iterator it_begin = spell_arr.begin();
	std::map<std::string, ASpell*>::iterator it_end = spell_arr.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	spell_arr.clear();
}

void SpellBook::learnSpell(ASpell *ptr)
{
	if (ptr)
		spell_arr.insert(std::pair<std::string, ASpell*>(ptr->getName(), ptr->clone()));
}

void SpellBook::forgetSpell(std::string const &name)
{
	std::map<std::string, ASpell*>::iterator it = spell_arr.find(name);
	if (it != spell_arr.end())
		delete it->second;
	spell_arr.erase(name);
}

ASpell *SpellBook::createSpell(std::string const &name)
{
	std::map<std::string, ASpell*>::iterator it = spell_arr.find(name);
	if (it != spell_arr.end())
		return (it->second);
	return (NULL);
}