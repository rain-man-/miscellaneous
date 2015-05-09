/*
 * MyPhPFunctions.cpp
 *
 *  Created on: Apr 30, 2015
 *      Author: uttam
 */

#include<phpcpp.h>
#include<sstream>
#include<cstdlib>
#include<stdio.h>


Php::Value get_some_random_string() {
	std::ostringstream stm;
	stm << "Here is a random number:";
	stm << rand();
	stm << ", and another random number " << rand();

	return stm.str();
}

extern "C" {
	PHPCPP_EXPORT void *get_module() {
		static Php::Extension extension ("myphpextensions","1.0");

		extension.add("get_some_random_string", get_some_random_string);
		return extension;
	}
}



