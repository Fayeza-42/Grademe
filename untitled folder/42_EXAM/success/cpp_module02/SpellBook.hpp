#pragma once

#include <iostream>
#include <string>
#include <map>
// class ASpell;
#include "ASpell.hpp"
class SpellBook
{
private:
SpellBook &operator=(SpellBook const &other);
SpellBook(SpellBook const &other);

std::map<std::string, ASpell*> spell_arr;

public:
SpellBook();
~SpellBook();

void learnSpell(ASpell *ptr);
void forgetSpell(std::string const &name);
ASpell *createSpell(std::string const &name);

};