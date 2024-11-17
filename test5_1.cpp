#include <iostream>
#include <cmath> 
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;
class Vector {
private:
	double x, y;

public:
	Vector(double x_val, double y_val) : x(x_val), y(y_val) {}

	Vector add(const Vector& v) const {
		return Vector(this->x + v.x, this->y + v.y);
	}

	void print() const {
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}


	void dir() const {
		double magnitude = std::sqrt(x * x + y * y); 
		std::cout << "模长: " << magnitude << std::endl;
	}
};
bool isValidInput(const string& token) {
    // 检查是否为有效的整数（包括负数）
    if (token.empty()) return false;
    for (size_t i = 0; i < token.size(); i++) {
        if (!isdigit(token[i]) && !(i == 0 && token[i] == '-')) {
            return false;
        }
    }
    return true;
}
int main() {

    vector<int> arr;
    string inputLine;

    while (true) {
        getline(cin, inputLine);

        stringstream ss(inputLine);
        string token;
        bool allValid = true;
        vector<int> tempArr;

        // 逐个提取输入的内容，并检查是否为有效的整数
        while (ss >> token) {
            if (isValidInput(token)) {
                tempArr.push_back(stoi(token));  // 转换为整数并存入临时数组
            } 
            else 
            {
                cout << "无效输入: " << token << ". 请重新输入！" << endl;
                allValid = false;
                break;
            }
        }

        if (allValid) {
            arr = tempArr;  // 输入有效，存入最终数组
            break;          // 跳出循环
        }
    }

	Vector v1(arr[0], arr[1]);
	Vector v2(arr[2], arr[3]);

	std::cout << "v1: ";
	v1.print();
	std::cout << "v2: ";
	v2.print();

	Vector v3 = v1.add(v2);
	std::cout << "v1 + v2 = ";
	v3.print();

	v3.dir();

	return 0;
}