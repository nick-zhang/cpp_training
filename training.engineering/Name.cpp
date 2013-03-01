
#include "Name.h"
#include <iostream>

namespace engineering_demo {

	Name::Name(char* first, char* last) : first(first), last(last) {
	}

	void Name::PrintFullName() {
		std::cout << first << " " << last << std::endl;
	}
}