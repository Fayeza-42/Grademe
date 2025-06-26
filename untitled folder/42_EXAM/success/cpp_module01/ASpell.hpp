#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"
class ATarget;

class ASpell
{
public:
ASpell();
virtual ~ASpell();
ASpell(std::string const &name, std::string const &effects);
ASpell& operator=(ASpell const &other);
ASpell(ASpell const &other);

std::string const &getName() const;
std::string const &getEffects() const;

virtual ASpell *clone() const = 0;
void launch(ATarget const &tar_ref) const;

private:
std::string name;
std::string effects;

};