#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{

	std::cout << name << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell*>::iterator it_begin = arr.begin();
	std::map<std::string, ASpell*>::iterator it_end = arr.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	arr.clear();
	
}

std::string const &Warlock::getName()const 
{
	return name;
}

std::string const &Warlock::getTitle() const
{
	return title;
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;

}

void Warlock::learnSpell(ASpell *ptr)
{
	if (ptr)
	{
		arr.insert(std::pair<std::string, ASpell*>(ptr->getName(), ptr->clone()));
	}
}

void Warlock::forgetSpell(std::string name)
{
	std::map<std::string, ASpell*>::iterator it = arr.find(name);
	if (it != arr.end())
		delete it->second;
	arr.erase(name);
}

void Warlock::launchSpell(std::string name, ATarget const &tar_ref)
{
	// ASpell *spell;
	std::map<std::string, ASpell*>::iterator it = arr.find(name);
	if (it != arr.end())
		it->second->launch(tar_ref);
	// spell->launch(tar_ref);
}