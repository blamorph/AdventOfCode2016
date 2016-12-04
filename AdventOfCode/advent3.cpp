#include "advent3.h"
#include <string>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <functional>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

bool valid_triangle(std::vector<std::string> dirs) {

	int a = boost::lexical_cast<int>(dirs[0]);
	int b = boost::lexical_cast<int>(dirs[1]);
	int c = boost::lexical_cast<int>(dirs[2]);

	return (a + b > c) && (a + c > b) && (b + c > a);	
}

bool valid_triangle(std::vector<int> v) {
	return *std::max_element(v.begin(), v.end()) < (std::accumulate(v.begin(), v.end(), 0) - *std::max_element(v.begin(), v.end()));
}

void test_advent3()
{
	assert(valid_triangle({ "5","10","25" }) == false);
}

void advent3() {
	std::ifstream f("advent3.txt");
	std::string line;
	int ok = 0;
	int ok2 = 0;
	int i = 0;

	std::vector < std::string > a;
	std::vector < std::string > b;
	std::vector < std::string > c;

	for(i  = 1; std::getline(f, line); i++) {		

		//part1

		std::vector < std::string > res;
		boost::trim(line);
		boost::split(res, line, boost::is_any_of(" "), boost::token_compress_on);

		if (valid_triangle(res))
			ok++;

		a.push_back(res[0]);
		b.push_back(res[1]);
		c.push_back(res[2]);

		if (i % 3 == 0) {
			if (valid_triangle(a))
				ok2++;
			if (valid_triangle(b))
				ok2++;
			if (valid_triangle(c))
				ok2++;

			a.clear(); b.clear(); c.clear();
		}		
	}

	std::cout << "advent3: " << ok << std::endl;
	std::cout << "advent3.part2: " << ok2 << std::endl;
}