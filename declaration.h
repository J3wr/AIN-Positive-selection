#ifndef DEFINITION_H
#define DEFINITION_H

#include <iostream>
#include <vector>

using std::vector;
using std::string;

void init(vector<vector<int> > &S,
	vector<vector<int> > &R);

int affinity(vector<int> &S,
	vector<int> &R);

bool compare(vector<int> &S,
	vector<int> &R);

void createDetectors(vector<vector<int> > &S,
	vector<vector<int> > &R);

void algorithm(vector<vector<int> > &S,
	vector<vector<int> > &R);

void print(const string &str);

vector<int> generateCandidateToDetector();

#endif 
