#include"Speaker.h"

Speaker::Speaker()
{
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