#pragma once
#include<iostream>
using namespace std;

class Speaker
{
public:
	Speaker();
	~Speaker();
	Speaker(string name, double *score);

	//ѡ������
	string s_name;
	//ѡ�ַ�������ά�����ʾ���ֱ���������
	double s_score[2];
};
