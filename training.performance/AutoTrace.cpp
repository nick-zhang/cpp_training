
#include <iostream>
#include <ctime>
#include "AutoTrace.h"

AutoTrace::AutoTrace(){
	start = std::clock();
}

AutoTrace::~AutoTrace() {
	long duration = std::clock() - start;
	std::cout << "duration: " << duration << "ms." << std::endl;
}
