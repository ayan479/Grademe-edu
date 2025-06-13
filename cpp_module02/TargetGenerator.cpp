#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const & obj)
{
	*this = obj;
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & tg)
{
	t_arr= tg.t_arr;
	return (*this);
}

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget* at)
{
	if (at)
		t_arr[at->getType()] = at;
}

void TargetGenerator::forgetTargetType(std::string const & tname)
{
	if (t_arr.find(tname) != t_arr.end())
		t_arr.erase(t_arr.find(tname));
}

ATarget* TargetGenerator::createTarget(std::string const & tname)
{
	ATarget* tmp = NULL;
	if (t_arr.find(tname) != t_arr.end())
		tmp = t_arr[tname];
	return (tmp);
}
