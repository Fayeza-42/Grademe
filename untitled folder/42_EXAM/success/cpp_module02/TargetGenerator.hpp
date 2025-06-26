#pragma once

#include <iostream>
#include <string>
#include <map>
// class ASpell;
#include "ATarget.hpp"
class TargetGenerator
{
private:
TargetGenerator &operator=(TargetGenerator const &other);
TargetGenerator(TargetGenerator const &other);

std::map<std::string, ATarget*> tar_arr;

public:
TargetGenerator();
~TargetGenerator();

void learnTargetType(ATarget *ptr);
void forgetTargetType(std::string const &name);
ATarget *createTarget(std::string const &name);

};