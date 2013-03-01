
#include "Menus.h"

using namespace std;

vector<string> Menus::load_menus() {
	vector<string> menus;
	menus.push_back("Feature A");
	menus.push_back("Feature C");
	menus.push_back("Feature F");
#ifdef INTERNAL_VERSION
	menus.push_back("Feature B");
#endif
	return menus;
}