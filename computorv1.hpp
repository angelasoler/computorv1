#ifndef COMPUTORV1_HPP
#define COMPUTORV1_HPP

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <regex>

using namespace std;

vector<float>	DetachTerms(string expr, int mult);
vector<string>	ParseExpressions(string expr);
vector<float>	ReduceForm(string &expression);

string	FormatFloat(float num);
float	Sqrt(float number);
void	ResolveEquation(vector<float> coeffs);
void	Solution(vector<float> coeffs);

auto	QuadraticEquation(vector<float> coeffs);

#endif //COMPUTORV1_HPP
