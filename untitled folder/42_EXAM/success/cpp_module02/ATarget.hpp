#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"
class ASpell;

class ATarget
{
public:
ATarget();
virtual ~ATarget();
ATarget(std::string const &type);
ATarget& operator=(ATarget const &other);
ATarget(ATarget const &other);

std::string const &getType() const;
std::string const &getEffects() const;

virtual ATarget *clone() const = 0;
void getHitBySpell(ASpell const &spell) const;


private:
std::string type;

};