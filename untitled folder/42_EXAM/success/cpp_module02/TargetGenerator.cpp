#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget*>::iterator it_begin = tar_arr.begin();
	std::map<std::string, ATarget*>::iterator it_end = tar_arr.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	tar_arr.clear();
}

void TargetGenerator::learnTargetType(ATarget *ptr)
{
	if (ptr)
		tar_arr.insert(std::pair<std::string, ATarget*>(ptr->getType(), ptr->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &name)
{
	std::map<std::string, ATarget*>::iterator it = tar_arr.find(name);
	if (it != tar_arr.end())
		delete it->second;
	tar_arr.erase(name);
}

ATarget *TargetGenerator::createTarget(std::string const &name)
{
	std::map<std::string, ATarget*>::iterator it = tar_arr.find(name);
	if (it != tar_arr.end())
		return (it->second);
	return (NULL);
}