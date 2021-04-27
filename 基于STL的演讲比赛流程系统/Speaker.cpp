#include"Speaker.h"

Speaker::Speaker()
{
	this->s_name = "";
	this->s_score[0] = 0;
	this->s_score[1] = 0;
}

Speaker::~Speaker()
{
}

Speaker::Speaker(string name, double *score)
{
	this->s_name = name;
	for (int i = 0; i < 2; i++)
	{
		this->s_score[i] = score[i];
	}
}