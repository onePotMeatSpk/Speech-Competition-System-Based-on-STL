#pragma once
#include<iostream>
using namespace std;

class Speaker
{
public:
	Speaker();
	~Speaker();
	Speaker(string name, double *score);

	//选手名字
	string s_name;
	//选手分数（二维数组表示两轮比赛分数）
	double s_score[2];
};
