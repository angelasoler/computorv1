#include "computorv1.hpp"

//to-do
//remove coefficietn [1] if it is 0 (in this case, second degree equation is really first degree)
vector<float>	DetachTerms(string expr, int mult) {
	vector<float>	coefficient;
	regex delim(R"(\s*\*\s*X\^)");

	sregex_token_iterator it(expr.begin(), expr.end(), delim, -1);
	sregex_token_iterator end;

	coefficient.push_back(stof(*it) * mult);
	while(++it != end) {
		string s = *it;
		size_t sign = s.find('+');
		if (sign == string::npos)
			sign = s.find('-');
		if (sign != string::npos) {
			regex re("\\s+");
			string number = regex_replace(s.substr(sign), re, "");
			coefficient.push_back(stof(number) * mult);
		}
	}
	return coefficient;
}

vector<string> ParseExpressions(string expr) {
	regex delim("=");
	vector<string> parts;

	sregex_token_iterator it(expr.begin(), expr.end(), delim, -1);
	sregex_token_iterator end;

	while (it != end) {
		parts.push_back(*it);
		++it;
	}
	return parts;
}

string FormatFloat(float num) {
	string sign = num < 0? " - " : " + ";
	string number;
	if (num - int(num) == 0.0)
		number = to_string(int(abs(num)));
	else
		number = to_string(abs(num));
	string format_number = sign + number;
	return(format_number);
}

// presission(1)
vector<float>	ReduceForm(string &expression) {
	vector<string> parts = ParseExpressions(expression);
	if (parts.size() != 2)
		throw "Invalid expression";
	vector<float> coef_left = DetachTerms(parts[0], 1);
	vector<float> coef_right = DetachTerms(parts[1], -1);
	int size_left = coef_left.size();
	int size_right =  coef_right.size();
	vector<float> bigger = size_left >= size_right? coef_left : coef_right;
	vector<float> smaller = size_left < size_right? coef_left : coef_right;
	for (size_t i = 0; i < smaller.size(); i++)
		bigger.at(i) += smaller.at(i);
	cout << "Reduced form: ";
	for (size_t i = 0; i < bigger.size(); i++) {
		string number = FormatFloat(bigger.at(i));
		if (!i && bigger.at(i) >= 0)
			number.replace(0, 3, "");
		cout << number << " * X^" << i;
	}
	cout << " = 0"<< endl;
	return bigger;
}

float Sqrt(float number) {
	float guess = number / 2.0f;
	float epsilon = 0.01f;

	while ((guess * guess - number) > epsilon)
		guess = (guess + number / guess) / 2.0f;
	return guess;
}

ResultType QuadraticEquation(vector<float> coeffs) {
	float	a, b, c, discriminant, sqrt_discriminant;

	a = coeffs[2];
	b = coeffs[1];
	c = coeffs[0];
	discriminant = b * b - (4 * a * c);
	sqrt_discriminant = Sqrt(abs(discriminant));
	if (discriminant >= 0) {
		cout << "Discriminant is strictly positive, the two solutions are:" << endl;
		auto result = make_shared<vector<float>>();
		result->push_back((- b + sqrt_discriminant) / (2 * a));
		result->push_back((- b - sqrt_discriminant) / (2 * a));
		return result;
	}
	cout << "Discriminant is strictly negative, the two complex solutions are:" << endl;
	auto result = make_shared<vector<string>>();
	float div = a;
	ostringstream sum;
	ostringstream sub;
	//this is happy path
	sum << int(-b/2) << "/" << div << " + " << int(sqrt_discriminant/2) << "i" << "/" << div;
	sub << int(-b/2) << "/" << div << " - " << int(sqrt_discriminant/2) << "i" << "/" << div;
	result->push_back(sum.str());
	result->push_back(sub.str());
	return result;
}

void ZeroDegreeSolution(vector<float> coeffs) {
	if (coeffs[0] != 0)
		cout << "No Solution" << endl;
	else
		cout << "Any real number is a Solution" << endl;
}

float LinearEquation(vector<float> coeffs) {
	return (coeffs[0] * -1) / coeffs[1];
}

void Solution(vector<float> coeffs) {
	size_t	degree = coeffs.size() - 1;

	if (degree)
		cout << "Polynomial degree: " << degree << endl;
	switch (degree)
	{
		case 0:
			ZeroDegreeSolution(coeffs);
			break;
		case 1:
			cout << "The Solution is:" << endl;
			cout << to_string(LinearEquation(coeffs)) << endl;
			break;
		case 2: {
			ResultType result = QuadraticEquation(coeffs);
			visit([](auto& res) {
				for (const auto& value : *res) {
					cout << value << endl;
				}
			}, result);
			break;
		}
		default:
			cout << "The polynomial degree is strictly greater than 2, I can't solve." << endl;
			break;
	}
}
