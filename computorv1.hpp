#ifndef COMPUTORV1_HPP
#define COMPUTORV1_HPP

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <regex>
#include <variant>

using namespace std;
using ResultType = variant<shared_ptr<vector<string>>, shared_ptr<vector<float>>>;

vector<float>	DetachTerms(string expr, int mult);
vector<string>	ParseExpressions(string expr);
vector<float>	ReduceForm(string &expression);

string	FormatFloat(float num);
float	Sqrt(float number);
void	Solution(vector<float> coeffs);

void		ZeroDegreeSolution(vector<float> coeffs);
float		LinearEquation(vector<float> coeffs);
ResultType	QuadraticEquation(vector<float> coeffs);

#endif //COMPUTORV1_HPP
