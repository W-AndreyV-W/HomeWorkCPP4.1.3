#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::vector <double> array_angle = { 30, 60, 90 };
	std::vector<double>angles;

	std::cout << "[Входные данные]: ";
	std::for_each(array_angle.begin(), array_angle.end(), [&](int tmp) {
		angles.push_back(tmp * 3.1415926 / 180);
		std::cout << tmp << " * 3.1415926 / 180, ";
		});
	std::cout << std::endl;

	std::function<void(double)> sin_print = [](double radian) {
		std::cout << "sin: " << sin(radian) << " ";

	};

	std::function<void(double)> cos_print = [](double radian) {
		std::cout << "cos: " << cos(radian) << " ";
	};
	
	std::vector<std::function<void(double)>> functions{ sin_print, cos_print };

	std::cout << "[Выходные данные]: " << std::endl;
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
}