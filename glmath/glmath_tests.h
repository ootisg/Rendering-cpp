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
	}

	public:
	
		void run_v2_tests () {
			
			//if(1) used for scoping
			
			//Test construction
			if (1) {
				tests_init ("Running v2 construction tests");
				v2 a(0.5, 0.2);
				v2 b(0.3, 0.4);
				assert_equals (a, "[0.5,0.2]");
				assert_equals (b, "[0.3,0.4]");
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
				assert_equals (c, "[0.8,0.6]");
				assert_equals (b, "[0.8,0.6]");
			}
			
			//Test dot product
			if (1) {
				tests_init ("Running v2 dot product tests");
				v2 a(0.5, 0.2);
				v2 b(0.3, 0.4);
				assert_equals (a * b, 0.23);
			}
			
		}
		
		void run_all_tests () {
			run_v2_tests ();
		}
		
};
