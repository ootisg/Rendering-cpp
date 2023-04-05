#include "mat2.h"
#include "v2.h"

#include <cmath>

mat2::mat2 (float a1v, float a2v,
      	    float b1v, float b2v) {
	mat_data[0] = a1v;
	mat_data[1] = a2v;
	mat_data[2] = b1v;
	mat_data[3] = b2v;
}

std::string mat2::to_string () {
	char* buf = new char[33];
	sprintf (buf,
		 "[%.4f %.4f]\n"
		 "[%.4f %.4f]\n",
		 a1, b1,
		 a2, b2);
	return std::string (buf);
}
		
float mat2::get (int x, int y) {
	if (x * 2 + y > 4) {
		return 0;
	}
	return mat_data[x * 2 + y];
}

void mat2::set (float val, int x, int y) {
	if (x * 2 + y < 4) {
		mat_data[x * 2 + y] = val;
	}
}

mat2 mat2::scale (v2 const &axes) {
	return mat2(axes.x, 0,
		    0, axes.y);
}

mat2 mat2::rotate (float theta) {
	return mat2(cos(theta), sin(theta),
		    -sin(theta), cos(theta));
}

mat2 mat2::operator+ (mat2 const &b) {
	return mat2 (a1 + b.a1, b1 + b.b1,
		     a2 + b.a2, b2 + b.b2);
}

mat2 mat2::operator* (mat2 const &b) {
	mat2 result (a1 * b.a1 + b1 * b.a2, a2 * b.a1 + b2 * b.a2,
		     a1 * b.b1 + b1 * b.b2, a2 * b.b1 + b2 * b.b2);
	a1 = result.a1;
	a2 = result.a2;
	b1 = result.b1;
	b2 = result.b2;
	return *this;
}

v2 mat2::operator* (v2 const &b) {
	return v2 (a1 * b.x + b1 * b.y, a2 * b.x + b2 * b.y);
}

std::ostream& operator<< (std::ostream& stream, mat2 m) {
	stream << m.to_string ();
	return stream;
}
