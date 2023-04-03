class GlMathTest {
	
	int current_test = 1;

	void tests_init () {
		current_test = 1;
	}

	void tests_init (std::string message) {
		std::cout << message << std::endl;
		current_test = 1;
	}

	//Assert functions
	void assert_equals (int a, int b) {
		if (a != b) {
			std::cout << "Test " << current_test << " failed: " << a << " != " << b << std::endl;
		} else {
			std::cout << "Test " << current_test << " passed (" << a << " == " << b << ")" << std::endl;
		}
		current_test++;
	}

	void assert_equals (float a, float b) {
		if (abs (a - b) > .00001) {
			std::cout << "Test " << current_test << " failed: " << a << " != " << b << std::endl;
		} else {
			std::cout << "Test " << current_test << " passed (" << a << " == " << b << ")" << std::endl;
		}
		current_test++;
	}

	void assert_equals (v2 const &a, v2 const &b) {
		if (abs (a.x - b.x) > .00001 || abs (a.y - b.y) > .00001) {
			std::cout << "Test " << current_test << " failed: " << a << " != " << b << std::endl;
		} else {
			std::cout << "Test " << current_test << " passed (" << a << " == " << b << ")" << std::endl;
		}
		current_test++;
	}

	void assert_equals (v2 const &a, float x, float y) {
		if (abs (a.x - x) > .00001 || abs (a.y - y) > .00001) {
			std::cout << "Test " << current_test << " failed: " << a << " != [" << x << "," << y << "]" << std::endl;
		} else {
			std::cout << "Test " << current_test << " passed (" << a << " == " << "[" << x << "," << y << "]" << ")" << std::endl;
		}
		current_test++;
	}

	public:
	
		void run_v2_tests () {
			
			//if(1) used for scoping
			
			//Test construction
			if (1) {
				tests_init ("Running v2 construction tests");
				v2 a(0.5, 0.2);
				v2 b(0.3, 0.4);
				assert_equals (a, 0.5f, 0.2f);
				assert_equals (b, 0.3f, 0.4f);
			}
			
			//Test addition
			if (1) {
				tests_init ("Running v2 addition tests");
				v2 a(0.5, 0.2);
				v2 b(0.3, 0.4);
				v2 c;
				c.x = (a + b).x;
				c.y = (b += a).y;
				assert_equals (c, 0.7f, 0.8f);
				assert_equals (b, 0.7f, 0.8f);
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