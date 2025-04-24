#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <regex>

using namespace std;

vector<float>	separete_terms(string expr, int mult) {
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

vector<string> parse_expressions(string expr) {
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

string formatFloat(float num) {
	string sign = num < 0? " - " : " + ";
	string number;
	if (num - int(num) == 0.0)
		number = to_string(int(abs(num)));
	else
		number = to_string(abs(num));
	string format_number = sign + number;
	return(format_number);
}

// to-do: use stringstream and print all at the end
// left presission(1)
// validate that exponents are organized
vector<float>	reduce_form(string &expression) {
	vector<string> parts = parse_expressions(expression);
	if (parts.size() != 2)
		throw "Invalid expression";
	vector<float> coef_left = separete_terms(parts[0], 1);
	vector<float> coef_right = separete_terms(parts[1], -1);
	int size_left = coef_left.size();
	int size_right =  coef_right.size();
	vector<float> bigger = size_left >= size_right? coef_left : coef_right;
	vector<float> smaller = size_left < size_right? coef_left : coef_right;
	for (size_t i = 0; i < smaller.size(); i++)
		bigger.at(i) += smaller.at(i);
	cout << "Reduced form: ";
	for (size_t i = 0; i < bigger.size(); i++) {
		string number = formatFloat(bigger.at(i));
		if (!i && bigger.at(i) >= 0)
			number.replace(0, 3, "");
		cout << number << " * X^" << i;
	}
	cout << " = 0"<< endl;
	return bigger;
}



float sqrt(float number) {
	// https://www.cuemath.com/algebra/squares-and-square-roots/
	return number;
}

vector<string> quadratic_equation(vector<float> coeffs) {
	int a, b, c, discriminant;
	vector<string> result;

	a = coeffs[2];
	b = coeffs[1];
	c = coeffs[0];
	discriminant = b * b - 4 * a * c;
	float r1 = -(b/2*a);
	if (discriminant > 0){
		float aux = - b + sqrt(discriminant) / 2 * a;
		result.push_back(to_string(aux));
		aux = - b - sqrt(discriminant) / 2 * a;
		result.push_back(to_string(aux));
	}
	else if (discriminant < 0) {
		float r2 = sqrt(discriminant) / 2*a;
		result.push_back(to_string(r1) + " + i" + to_string(r2));
		result.push_back(to_string(r1) + " - i" + to_string(r2));
	}
	else {
		result.push_back(to_string(r1 * -1));
		result.push_back(to_string(r1 * -1));
	}

	cout << result.at(0) << endl;
	cout << result.at(1) << endl;
	return result;
}

//to-do: apply second degree equation
// test all possible polinomial solution cases and validations (gtest)
void solution(vector<float> coeffs) {
	string	result[2];
	size_t	degree = coeffs.size() - 1;
	float aux;

	if (degree)
		cout << "Polynomial degree: " << degree << endl;
	cout << "The solution is:" << endl;
	switch (degree)
	{
		case 1:
			aux = (coeffs[0] * -1) / coeffs[1];
			result[0] = to_string(aux);
			cout << result[0] << endl;
			break;
		case 2:
			quadratic_equation(coeffs);
			break;
		default:
			break;
	}
}
