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
		vectorSpeaker1.resize(6);
		vectorSpeaker2.resize(6);
		random_shuffle(vectorSpeaker.begin(), vectorSpeaker.end());
		copy(vectorSpeaker.begin(), vectorSpeaker.begin() +6, vectorSpeaker1.begin());
		copy(vectorSpeaker.begin() + 6, vectorSpeaker.end(), vectorSpeaker2.begin());
	}
	else
	{
		random_shuffle(vectorUpperSpeaker.begin(), vectorUpperSpeaker.end());
	}

	
}

//����ѡ�ִ�ֺ���
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
		vectorUpperSpeaker.clear();
		//��һ����
		mapBuffer.clear();
		for (vector<int>::iterator it = vectorSpeaker1.begin(); 
			it != vectorSpeaker1.end(); it++)
		{
				//����������ѡ����Ϣ��
				mapSpeaker.at(*it).s_score[0] = setSingleScore();

				mapBuffer.insert(make_pair(mapSpeaker.at(*it).s_score[0], *it));
				
		}
		//����
		int index_mapBuffer = 0;
		for (multimap<double, int, greater<double>>::iterator it_mapBuffer = mapBuffer.begin(); index_mapBuffer < 3 && it_mapBuffer != mapBuffer.end(); it_mapBuffer++)
		{
			vectorUpperSpeaker.push_back(it_mapBuffer->second);
			index_mapBuffer++;
		}


		//�ڶ�����
		mapBuffer.clear();
		for (vector<int>::iterator it = vectorSpeaker2.begin();it != vectorSpeaker2.end(); it++)
		{
			//����������ѡ����Ϣ��
			mapSpeaker.at(*it).s_score[0] = setSingleScore();

			
			mapBuffer.insert(make_pair(mapSpeaker.at(*it).s_score[0], *it));
			
		}
		//����
		index_mapBuffer = 0;
		for (multimap<double, int, greater<double>>::iterator it_mapBuffer = mapBuffer.begin(); index_mapBuffer < 3 && it_mapBuffer != mapBuffer.end(); it_mapBuffer++)
		{
			vectorUpperSpeaker.push_back(it_mapBuffer->second);
			index_mapBuffer++;
		}


	}
	else//�ڶ��ֱ������
	{
		vectorWinSpeaker.clear();
		mapBuffer.clear();
		for (vector<int>::iterator it = vectorUpperSpeaker.begin(); it != vectorUpperSpeaker.end(); it++)
		{
			mapSpeaker.at(*it).s_score[1] = setSingleScore();

			//����
			mapBuffer.insert(make_pair(mapSpeaker.at(*it).s_score[1], *it));
			
		}
		int index_mapBuffer = 0;
		for (multimap<double, int, greater<double>>::iterator it_mapBuffer = mapBuffer.begin(); index_mapBuffer < 3 && it_mapBuffer != mapBuffer.end(); it_mapBuffer++)
		{
			vectorWinSpeaker.push_back(it_mapBuffer->second);
			index_mapBuffer++;
		}
	}
}


//չʾѡ����Ϣ����
void SpeakerManager::showInfo()
{
	if (roundNum==1)
	{
		cout << "************��һ�ֱ������************" << endl;
		cout << "****��һ��****" << endl;
		for (vector<int>::iterator it = vectorSpeaker1.begin();
			it != vectorSpeaker1.end(); it++)
		{
			cout << mapSpeaker.at(*it).s_name << ": " << mapSpeaker.at(*it).s_score[0] << " ";
			if (find(vectorUpperSpeaker.begin(),vectorUpperSpeaker.end(),*it)!=vectorUpperSpeaker.end())
			{
				cout << "��ѡ�ֽ���" << endl;
			}
			else
			{
				cout << endl;
			}
		}

		cout << "****�ڶ���****" << endl;
		for (vector<int>::iterator it = vectorSpeaker2.begin();
			it != vectorSpeaker2.end(); it++)
		{
			cout << mapSpeaker.at(*it).s_name << ": " << mapSpeaker.at(*it).s_score[0] << " ";
			if (find(vectorUpperSpeaker.begin(), vectorUpperSpeaker.end(), *it) != vectorUpperSpeaker.end())
			{
				cout << "��ѡ�ֽ���" << endl;
			}
			else
			{
				cout << endl;
			}
		}
	}
	else
	{
		cout << "************�ڶ��ֱ������************" << endl;
		for (vector<int>::iterator it = vectorUpperSpeaker.begin();
			it != vectorUpperSpeaker.end(); it++)
		{
			cout << mapSpeaker.at(*it).s_name << ": " << mapSpeaker.at(*it).s_score[1] << " ";
			if (find(vectorWinSpeaker.begin(), vectorWinSpeaker.end(), *it) != vectorWinSpeaker.end())
			{
				cout << "��ѡ�ֻ�ʤ" << endl;
			}
			else
			{
				cout << endl;
			}
		}
	}
}


//���б�������
void SpeakerManager::runCompetition()
{
	this->roundNum = 1;
	this->createSpeaker();
	this->setGroup();
	this->setAllScore();
	this->showInfo();
	this->roundNum = 2;
	this->setGroup();
	this->setAllScore();
	this->showInfo();
}

