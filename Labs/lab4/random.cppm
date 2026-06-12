export module random;
import std;

export float get_random_num(float b1, float b2) {
	std::random_device rd;
	std::mt19937 prng(rd());

	std::uniform_real_distribution<float> d{ b1, b2 };
	return d(prng);
}

export int get_random_num(int b1, int b2) {
	std::random_device rd;
	std::mt19937 prng(rd());

	std::uniform_int_distribution<int> d{ b1, b2 };
	return d(prng);
}