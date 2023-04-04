#include "v2.h"
#include "mat2.h"

class GlMathTest {
	
	int current_test = 1;

	void tests_init () {
		current_test = 1;
	}

	void tests_init (std::string message) {
		std::cout << message << std::endl;
		current_test = 1;
	}

	void assert_equals (int a, int b) {
		if (a != b) {
			std::cout << "Test " << current_test << " FAILED: " << a << " != " << b << std::endl;
		} else {
			std::cout << "Test " << current_test << " passed (" << a << " == " << b << ")" << std::endl;
		}
		current_test++;
	}

	void assert_equals (float a, float b) {
		if (abs (a - b) > .00001) {
			std::cout << "Test " << current_test << " FAILED: " << a << " != " << b << std::endl;
		} else {
			std::cout << "Test " << current_test << " passed (" << a << " == " << b << ")" << std::endl;
		}
		current_test++;
	}

	//Assert functions
	template <typename T>
	void assert_equals (T a, T b) {
		std::stringstream a_stream;
		std::stringstream b_stream;
		a_stream << a;
		b_stream << b;
		if (a_stream.str ().compare (b_stream.str ()) == 0) {
			std::cout << "Test " << current_test << " passed (" << a << " == " << b << ")" << std::endl;
		} else {
			std::cout << "Test " << current_test << " FAILED: " << a << " != " << b << std::endl;
		}
		current_test++;
	}

	template <typename T>
	void assert_equals (T a, const char* b) {
		std::stringstream a_stream;
		a_stream << a;
		std::string b_str(b);
		if (a_stream.str ().compare (b_str) == 0) {
			std::cout << "Test " << current_test << " passed (" << a << " == " << b_str << ")" << std::endl;
		} else {
			std::cout << "Test " << current_test << " FAILED: " << a << " != " << b_str << std::endl;
		}
		current_test++;
	}

	public:
	
		void run_v2_tests () {
			
			//if(1) used for scoping
			
			std::cout << "Running tests for v2:" << std::endl;

			//Test construction
			if (1) {
				tests_init ("Running v2 construction tests");
				v2 a(0.5, 0.2);
				v2 b(0.3, 0.4);
				assert_equals (a, "[0.5000,0.2000]");
				assert_equals (b, "[0.3000,0.4000]");
				assert_equals (a, a);
			}
			
			//Test addition
			if (1) {
				tests_init ("Running v2 addition tests");
				v2 a(0.5, 0.2);
				v2 b(0.3, 0.4);
				v2 c;
				c.x = (a + b).x;
				c.y = (b += a).y;
				assert_equals (c, "[0.8000,0.6000]");
				assert_equals (b, "[0.8000,0.6000]");
			}
			
			//Test scaling
			if (1) {
				tests_init ("Running v2 scaling tests");
				v2 a(0.5, 0.2);
				v2 b(0.3, 0.4);
				assert_equals (a * 0.5, "[0.2500,0.1000]");
				b *= 0.1;
				assert_equals (b, "[0.0300,0.0400]");
				assert_equals (a / 2, "[0.2500,0.1000]");
				b /= 2;
				assert_equals (b, "[0.0150,0.0200]");
			}

			//Test dot product
			if (1) {
				tests_init ("Running v2 dot product tests");
				v2 a(0.5, 0.2);
				v2 b(0.3, 0.4);
				assert_equals (a * b, 0.23);
			}

			//Test length
			if (1) {
				tests_init ("Running v2 length tests");
				v2 a(0.5, 0.9);
				v2 b(0.1, 0.4);
				assert_equals (a.len(), 1.029563);
				assert_equals (b.len(), .412310);
			}
			
		}

		void run_mat2_tests () {
		
			//if(1) used for scoping
			
			std::cout << "Running mat2 tests:" << std::endl;

			//Test constructors
			if (1) {
				tests_init ("Running mat2 constructor tests");
				mat2 a (1, 0,
					0, 1);
				mat2 b;
				mat2 c (2);
				assert_equals (a, b);
				assert_equals (c, "[2.0000 0.0000]\n"
						  "[0.0000 1.0000]\n");
			}

			//Test addition
			if (1) {
				tests_init ("Running mat2 addition tests");
				mat2 a (1, 0,
					0, 1);
				mat2 b (0.2, 0.2,
					0.2, 0.2);
				mat2 c = a + b;
				assert_equals (c, "[1.2000 0.2000]\n"
						  "[0.2000 1.2000]\n");
			}

			//Test multiplication
			if (1) {
				tests_init ("Running mat2 multiplication tests");
				mat2 a (0.1, 0.2,
					0.3, 0.4);
				mat2 b (0.5, 0.6,
					0.7, 0.8);
				a * b;
				assert_equals (a, "[0.1900 0.2200]\n"
						  "[0.4300 0.5000]\n");
				v2 test_vec (0.5, 0.7);
				assert_equals (a * test_vec, "[0.2490,0.5650]");
			}

		}
		
		void run_all_tests () {
			run_v2_tests ();
			run_mat2_tests ();
		}
		
};
