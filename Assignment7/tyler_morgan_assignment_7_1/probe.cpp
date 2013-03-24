#include "probe.h"
#include <iostream>

Probe::Probe()
	:my_count(0)
{

}

Probe::~Probe()
{

}

void Probe::increase()
{
	my_count++;
}

void Probe::decrease()
{
	my_count--;
}

std::ostream& operator<<(std::ostream& os, const Probe& probe)
{
	os << probe.my_count;
}