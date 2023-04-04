#pragma once

#include <string>

class Matrix {

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
		
		virtual int width () {
			return 0; //Default implementation
		}

		virtual int height () {
			return 0; //Default implementation
		}

		virtual float get (int x, int y) {
			return 0; //Default implementation
		}

		virtual void set (float val, int x, int y) {
			//Default implementation
		}

};
