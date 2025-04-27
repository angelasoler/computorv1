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
	// https://www.cuemath.com/algebra/squares-and-square-roots/
	float guess = number / 2.0f;
	float epsilon = 0.01f;

	while ((guess * guess - number) > epsilon)
		guess = (guess + number / guess) / 2.0f;
	return guess;
}

auto QuadraticEquation(vector<float> coeffs) {
	float	a, b, c, discriminant;
	auto	result = make_shared<vector<string>>();

	a = coeffs[2];
	b = coeffs[1];
	c = coeffs[0];
	discriminant = b * b - (4 * a * c);
	float r1 = -(b/2*a);
	if (discriminant > 0){
		float sqrt_discriminant = Sqrt(discriminant);
		float aux = (- b + sqrt_discriminant) / (2 * a);
		result->push_back(to_string(aux));
		aux = (- b - sqrt_discriminant) / (2 * a);
		result->push_back(to_string(aux));
	}
	else if (discriminant < 0) {
		float r2 = Sqrt(abs(discriminant)) / 2*a;
		result->push_back(to_string(r1) + " + i" + to_string(r2));
		result->push_back(to_string(r1) + " - i" + to_string(r2));
	}
	else {
		result->push_back(to_string(r1 * -1));
		result->push_back(to_string(r1 * -1));
	}
	return result;
}

void ZeroDegreeSolution(vector<float> coeffs) {
	if (coeffs[0] != 0)
		cout << "No Solution" << endl;
	else
		cout << "Any real number is a Solution" << endl;
}

float FirstDegreeSolution(vector<float> coeffs) {
	return (coeffs[0] * -1) / coeffs[1];
}

//to-do: apply second degree equation
// test all possible polinomial Solution cases and validations (gtest)
void Solution(vector<float> coeffs) {
	shared_ptr<vector<string>>	result;
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
			cout << to_string(FirstDegreeSolution(coeffs)) << endl;
			break;
		case 2:
			result = QuadraticEquation(coeffs);
			cout << result->at(0) << endl;
			cout << result->at(1) << endl;
			break;
		default:
			break;
	}
}
