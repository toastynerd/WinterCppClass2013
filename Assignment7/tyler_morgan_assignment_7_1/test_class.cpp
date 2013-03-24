#include "test_class.h"

Probe TestClass::probe;
TestClass::TestClass()
{
	probe.increase();
}

TestClass::~TestClass()
{
	probe.decrease();
}
