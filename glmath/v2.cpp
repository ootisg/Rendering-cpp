#include "v2.h"

#include <cmath>

int v2::num_components () {
	return 2;
}
		
float* v2::as_array () {
	return vec_data;
}
		
std::string v2::to_string () {
	char* buf = new char[20];
	sprintf (buf, "[%.4f,%.4f]", x, y);
	return buf;	
}

//Non-virtual functions
float v2::len () {
	return sqrt (x * x + y * y);
}

//Operators
v2 v2::operator+ (v2 const &b) {
	v2 result (x + b.x, y + b.y);
	return result;
}

v2 v2::operator+= (v2 const &b) {
	x += b.x;
	y += b.y;
	return *this;
}

v2 v2::operator- (v2 const &b) {
	v2 result (x - b.x, y - b.y);
	return result;
}

v2 v2::operator-= (v2 const &b) {
	x -= b.x;
	y -= b.y;
	return *this;
}

float v2::operator* (v2 const &b) {
	return x * b.x + y * b.y;
}

v2 v2::operator* (float const &b) {
	v2 result (x * b, y * b);
	return result;
}

v2 v2::operator*= (float const &b) {
	v2 result (x *= b, y *= b);
	return result;
}

v2 v2::operator/ (float const &b) {
	v2 result (x / b, y / b);
	return result;
}

v2 v2::operator/= (float const &b) {
	x /= b;
	y /= b;
	return *this;
}

std::ostream& operator<< (std::ostream& stream, v2 v) {
	stream << v.to_string ();
	return stream;
}
