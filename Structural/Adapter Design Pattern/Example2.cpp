#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

using namespace std;

template <typename T> class Converter {
  public:
    string convert(const int from) { return to_string(from); }
    T convertBack(const string &to) {
        T t;
        try {
            t = stof(to);
        } catch (...) {
            return numeric_limits<T>::min();
        }
        return t;
    }
};

int main(void) {
    Converter<float> converter;
    cout << converter.convert(15) << endl;
    cout << converter.convertBack("19") << endl;
    cout << converter.convertBack("12.2") << endl;
    cout << converter.convertBack("d") << endl;
}