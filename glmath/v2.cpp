#include "v2.h"

int v2::num_components () {
	return 2;
}
		
float* v2::as_array () {
	return vec_data;
}
		
std::string v2::to_string () {
	std::stringstream str_out;
	str_out << "[" << vec_data[0] << "," << vec_data[1] << "]";
	return str_out.str ();
}

v2 v2::operator+ (v2 const &b) {
	v2 result (x + b.x, y + b.y);
	return result;
}

v2 v2::operator+= (v2 const &b) {
	v2 result (x += b.x, y += b.y);
	return result;
}

float v2::operator* (v2 const &b) {
	return x * b.x + y * b.y;
}

std::ostream& operator<< (std::ostream& stream, v2 v) {
	stream << v.to_string ();
	return stream;
}
