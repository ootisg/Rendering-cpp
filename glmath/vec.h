#pragma once

#include <iostream>

class Vec {
	
	public:
		
		virtual int num_components () {
			return 0; //Default implementation
		}
		
		virtual float* as_array () {
			return nullptr; //Default implementation
		}
		
		virtual std::string to_string () {
			return "[]"; //Default implementation
		}
		
};
