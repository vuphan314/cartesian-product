#include <vector>

using namespace std;

////////////////////////////////////////////////////////////

template<typename T>
void setCartesianProduct(const vector<vector<T>> &input,
    vector<vector<T>> &output) {
  for (auto& u : input) {
    vector<vector<T>> r;
    for (auto& x : output) {
      for (auto y : u) {
        r.push_back(x);
        r.back().push_back(y);
      }
    }
    output.swap(r);
  }
}

////////////////////////////////////////////////////////////

int main() {
	vector<vector<int>> inputV{{1}, {4,5,6}, {8,9}},
    &input = inputV, outputV{{}}, &output = outputV;
  setCartesianProduct(input, output);
	for (size_t i = 0; i < output.size(); i++) {
		for (size_t j = 0; j < output[i].size(); j++) {
			cout << output[i][j] << "\t";
		}
		cout << endl;
	}
}