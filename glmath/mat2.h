#pragma once

#include "matrix.h"
#include "v2.h"

#include <string>
#include <cstring>

class mat2 : Matrix {

	private:
		
		float mat_data[4];

	public:

		float &a1 = mat_data[0];
		float &a2 = mat_data[1];
		float &b1 = mat_data[2];
		float &b2 = mat_data[3];
		
		mat2 (float a1v=1, float a2v=0,
		      float b1v=0, float b2v=1);
		mat2 (mat2 const &from);
		
		virtual inline int num_components () {return 4;}
		virtual inline float* as_array () {return mat_data;}
		virtual inline int width () {return 2;}
		virtual inline int height () {return 2;}
		
		virtual std::string to_string ();
		virtual float get (int x, int y);
		virtual void set (float val, int x, int y);

		mat2 operator+ (mat2 const &b);
		mat2 operator* (mat2 const &b); //Behaves like *= for consistency with glm
		v2 operator* (v2 const &b);

		mat2& scale (v2 const &axes);
		mat2& rotate (float theta);

};

std::ostream& operator<< (std::ostream& stream, mat2 m);
