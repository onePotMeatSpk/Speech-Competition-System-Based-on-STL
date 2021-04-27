#include"SpeakerManager.h"


SpeakerManager::SpeakerManager()
{
	this->initSystem();
}

SpeakerManager::~SpeakerManager()
{
}

//��ʼ��ϵͳ����
void SpeakerManager::initSystem()
{
	//�������
	vectorSpeaker.clear();
	vectorSpeaker1.clear();
	vectorSpeaker2.clear();
	vectorUpperSpeaker.clear();
	vectorWinSpeaker.clear();
	mapSpeaker.clear();
	dequeScore.clear();

	//�����������
	roundNum = 0;
}

//��ʾ�����溯��
void SpeakerManager::showMenu()
{
	cout << "**************************************" << endl;
	cout << "**/----------��������ϵͳ----------\\**" << endl;
	cout << "**|          1.��ʼ����            |**" << endl;
	cout << "**|          2.�鿴�����¼        |**" << endl;
	cout << "**|          3.��ձ�����¼        |**" << endl;
	cout << "**|          0.�˳�ϵͳ            |**" << endl;
	cout << "**\\--------------------------------/**" << endl;
	cout << "**************************************" << endl;
}

//�˳�ϵͳ����
void SpeakerManager::exitMenu()
{
	cout << "**************************************" << endl;
	cout << "******  ллʹ�ã�ϵͳ���ڹر�  ******"<<endl;
	cout << "**************************************" << endl;
	system("pause");
	exit(0);
}

//����ѡ�ֺ���
void SpeakerManager::createSpeaker()
{
	//����ѡ�ֲ�����������
	for (int i = 0; i < 12; i++)
	{
		//��ʼ��ѡ��
		Speaker s;
		
		//Ϊѡ��ȡ����
		//��
		int randNum = rand() % 16;
		s.s_name += FIRST_NAME[randNum * 2];//������ռ�����ֽڵ��ַ����ʶ���Ҫ�����β��ܵõ�һ�������ĺ����ַ�
		s.s_name += FIRST_NAME[randNum * 2 + 1];//ֻ��һ�Σ����һ�����һЩ����ֵֹ���Ƨ����
		//������
		randNum = rand() % 16;
		s.s_name += MID_NAME[randNum * 2];
		s.s_name += MID_NAME[randNum * 2 + 1];
		//��β��
		randNum = rand() % 16;
		s.s_name += LAST_NAME[randNum * 2];
		s.s_name += LAST_NAME[randNum * 2 + 1];

		//��ѡ�ֵı��װ���vector������
		vectorSpeaker.push_back(i);

		//��ѡ�ֱ�ź�ѡ����ԣ�װ���pair��
		pair<int, Speaker>p(i, s);

		//��pairװ���map������
		mapSpeaker.insert(p);
	}
}

//��ǩ���麯��
void SpeakerManager::setGroup()
{
	if (roundNum == 1)
	{
		random_shuffle(vectorSpeaker.begin(), vectorSpeaker.end());
		copy(vectorSpeaker.begin(), vectorSpeaker.begin() + 6, vectorSpeaker1.begin());
		copy(vectorSpeaker.begin() + 6, vectorSpeaker.end(), vectorSpeaker2.begin());
	}
	else
	{
		random_shuffle(vectorUpperSpeaker.begin(), vectorUpperSpeaker.end());
	}
	

}

//������ֺ���
double SpeakerManager::setSingleScore()
{
	dequeScore.clear();//��մ�ֱ�
	for (int i = 0; i < 10; i++)
	{
		dequeScore.push_back(rand() % 100);//������
	}
	sort(dequeScore.begin(), dequeScore.end());//�ӵ͵������з���
	dequeScore.pop_front();//ȥ����ͷ�
	dequeScore.pop_back();//ȥ����߷�
	double score = accumulate(dequeScore.begin(), dequeScore.end(), 0) / 8;//����ƽ����
	return score;
}

//ȫԱ��ֽ�������
void SpeakerManager::setAllScore()
{
	multimap<double, int, greater<double>>mapBuffer;
	if (roundNum == 1)//��һ�ֱ������
	{
		//��һ����
		mapBuffer.clear();
		for (vector<int>::iterator it_vectorSpeaker = vectorSpeaker1.begin(); 
			it_vectorSpeaker != vectorSpeaker1.end(); it_vectorSpeaker++)
		{
				//����������ѡ����Ϣ��
				mapSpeaker.at(*it_vectorSpeaker).s_score[0] = setSingleScore();

				//����
				mapBuffer.insert(make_pair(mapSpeaker.at(*it_vectorSpeaker).s_score[0], *it_vectorSpeaker));
				for (multimap<double, int, greater<double>>::iterator it_mapBuffer=mapBuffer.begin(),int index_mapBuffer=0;
					index_mapBuffer<3&& it_mapBuffer!=mapBuffer.end(); it_mapBuffer++,index_mapBuffer++)
				{
					vectorUpperSpeaker.push_back(it_mapBuffer->second);
				}
		}
		//�ڶ�����
		mapBuffer.clear();
		for (vector<int>::iterator it_vectorSpeaker = vectorSpeaker2.begin();
			it_vectorSpeaker != vectorSpeaker2.end(); it_vectorSpeaker++)
		{
			//����������ѡ����Ϣ��
			mapSpeaker.at(*it_vectorSpeaker).s_score[0] = setSingleScore();

			//����
			mapBuffer.insert(make_pair(mapSpeaker.at(*it_vectorSpeaker).s_score[0], *it_vectorSpeaker));
			for (multimap<double, int, greater<double>>::iterator it_mapBuffer = mapBuffer.begin(), int index_mapBuffer = 0;
				index_mapBuffer < 3 && it_mapBuffer != mapBuffer.end(); it_mapBuffer++, index_mapBuffer++)
			{
				vectorUpperSpeaker.push_back(it_mapBuffer->second);
			}
		}

	}
	else//�ڶ��ֱ������
	{
		for (vector<int>::iterator it = vectorUpperSpeaker.begin(); it != vectorUpperSpeaker.end(); it++)
		{
			mapSpeaker.at(*it).s_score[1] = setSingleScore();
		}
	}
}



//չʾѡ����Ϣ����
void SpeakerManager::showInfo()
{

}

