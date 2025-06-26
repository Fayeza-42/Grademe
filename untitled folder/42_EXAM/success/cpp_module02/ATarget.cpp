#include "ATarget.hpp"

ATarget::ATarget(){}
ATarget::~ATarget(){}

ATarget::ATarget(ATarget const &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
}

ATarget &ATarget::operator=(ATarget const &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

std::string const &ATarget::getType() const
{
	return type;
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}

