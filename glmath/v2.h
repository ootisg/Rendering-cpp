#pragma once

#include "vec.h"

#include <string>
#include <iostream>
#include <sstream>

class v2 : Vec {
	
	float vec_data[2];
	
	public:
	
		float &x = vec_data[0];
		float &y = vec_data[1];
	
		v2 () {
			//No-arg constructor
		}
	
		v2 (float x, float y) {
			vec_data[0] = x;
			vec_data[1] = y;
		}
		
		virtual int num_components ();
		virtual float* as_array ();
		virtual std::string to_string ();
		
		v2 operator+ (v2 const &b);
		v2 operator+= (v2 const &b);
		float operator* (v2 const &b);
	
};

std::ostream& operator<< (std::ostream& stream, v2 v);
