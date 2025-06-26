#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::~ASpell(){}

ASpell::ASpell(ASpell const &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->effects = other.effects;
	}
}

ASpell &ASpell::operator=(ASpell const &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->effects = other.effects;
	}
	return *this;
}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
	this->name = name;
	this->effects = effects;
}

std::string const &ASpell::getName() const
{
	return name;
}

std::string const &ASpell::getEffects() const 
{
	return effects;
}

void ASpell::launch(ATarget const &tar_ref) const
{
	tar_ref.getHitBySpell((*this));
}