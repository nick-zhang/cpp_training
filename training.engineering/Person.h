
#include <iostream>
#include "Name.h"
#include "Food.h"
#include "Country.h"

namespace engineering_demo {

	class Person {
	public:
		Person();
		void Eat(Food food);
		void Speak(std::ostream& output);
	private:
		Name name;
		const Country& country;
	};
}