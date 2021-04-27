#pragma once
#include<iostream>
using namespace std;

class Speaker
{
public:
	Speaker();
	~Speaker();
	Speaker(string name, double *score);

	//
	string s_name;
	double s_score[2];
};
