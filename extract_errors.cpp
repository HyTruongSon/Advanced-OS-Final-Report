#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void extract(string input_fn, string keyword, string output_fn) {
	ifstream input(input_fn.c_str(), ios::in);
	ofstream output(output_fn.c_str(), ios::out);
	
	string line, str;
	while (true) {
		if (!getline(input, line)) {
			break;
		}
		bool found = false;
		if (keyword.length() < line.length()) {
			found = true;
			for (int i = 0; i < keyword.length(); ++i) {
				if (keyword[i] != line[i]) {
					found = false;
					break;
				}
			}
			if (found) {
				str = "";
				for (int i = keyword.length(); i < line.length(); ++i) {
					str += line[i];
				}
				output << str << endl;
			}
		}
	}

	input.close();
	output.close();
}

int main(int argc, char **argv) {
	extract("CCN-1D.report", "Test MAE: ", "CCN_1D_MAE.dat");
	extract("CCN-1D.report", "Test RMSE: ", "CCN_1D_RMSE.dat");
	extract("CCN-2D.report", "Test MAE: ", "CCN_2D_MAE.dat");
	extract("CCN-2D.report", "Test RMSE: ", "CCN_2D_RMSE.dat");
	return 0;
}