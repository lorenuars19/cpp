#include "template.hpp"

using namespace std;

int main(void)
{
	Template a(42);
	Template b(a);

	b.setVar(19);
	a.getVar();

}
