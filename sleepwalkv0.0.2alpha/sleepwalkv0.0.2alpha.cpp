#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class generalplayer
{
	protected:
		int health=100;
		int shield=0;
};
class player:public generalplayer
{
	public:
		friend class op;
		int choosemenu();
		void injured(int damage);
};
int player::choosemenu()
{
	cout<<endl<<"���������ѡ��"<<endl;
	cout<<"1.��ȭͷ����"<<endl;
	cout<<"2.ʲô������"<<endl;
	char a;
	while (true)
	{
		a=getchar();
		if (a=='1' || a=='2')
		{
			if (a=='1')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	return 0;
}
void player::injured(int damage)
{
	health-=damage;
}
class computer:public generalplayer
{
	public:
		friend class op;
		int AIchoose();
		void injured(int damage);
};
int computer::AIchoose()
{
	return 0;
}
void computer::injured(int damage)
{
	health-=damage;
}
class op
{
	public:
		int rps();
		int gameover(player &player,computer &AI);
		void introduce();
};
int op::rps()
{
	int a=rand()%3,b=rand()%3;
	if (a==0 && b==0)
	{
		cout<<"��ң�ʯͷ    "<<"���ԣ�ʯͷ"<<endl;
		cout<<"ƽ��"<<endl;
		return 0;
	}
	else if (a==1 && b==1)
	{
		cout<<"��ң�����    "<<"���ԣ�����"<<endl;
		cout<<"ƽ��"<<endl;
		return 0;
	}
	else if (a==2 && b==2)
	{
		cout<<"��ң���    "<<"���ԣ���"<<endl;
		cout<<"ƽ��"<<endl;
		return 0;
	}
	else if (a==0 && b==1)
	{
		cout<<"��ң�ʯͷ    "<<"���ԣ�����"<<endl;
		cout<<"��Ӯ����ѡ��Ȩ"<<endl;
		return 1;
	}
	else if (a==1 && b==0)
	{
		cout<<"��ң�����    "<<"���ԣ�ʯͷ"<<endl;
		cout<<"����Ӯ����ѡ��Ȩ"<<endl;
		return 2;
	}
	else if (a==0 && b==2)
	{
		cout<<"��ң�ʯͷ    "<<"���ԣ���"<<endl;
		cout<<"����Ӯ����ѡ��Ȩ"<<endl;
		return 2;
	}
	else if (a==2 && b==0)
	{
		cout<<"��ң���    "<<"���ԣ�ʯͷ"<<endl;
		cout<<"��Ӯ����ѡ��Ȩ"<<endl;
		return 1;
	}
	else if (a==1 && b==2)
	{
		cout<<"��ң�����    "<<"���ԣ���"<<endl;
		cout<<"��Ӯ����ѡ��Ȩ"<<endl;
		return 1;
	}
	else if (a==2 && b==1)
	{
		cout<<"��ң���    "<<"���ԣ�����"<<endl;
		cout<<"����Ӯ����ѡ��Ȩ"<<endl;
		return 2;
	}
	return 0;
}
int op::gameover(player &player,computer &AI)
{
	cout<<"���Ѫ��:"<<player.health<<endl;
	cout<<"����Ѫ��:"<<AI.health<<endl<<endl;
	if (player.health<=0)
	{
		return 1;
	}
	else if (AI.health<=0)
	{
		return 2;
	}
	return 0;
}
void op::introduce()
{
	cout<<endl;
	cout<<"                             ����v0.0.2	                      "<<endl;
	cout<<"                             (���԰汾)                        "<<endl;
	cout<<"                     �����ߣ�daniel(�����޵в���)              "<<endl;
	cout<<"                            ����������196                      "<<endl;
	cout<<"                                                               "<<endl;
	cout<<"�������ݣ�                                                     "<<endl;
	cout<<"1.�����˻�������ҹ�������                                     "<<endl;
	cout<<"2.���������ʯͷ������Ӯ�˺��ѡ�����                         "<<endl;
	cout<<"3.�޸�ʯͷ������ƽ�ֻ��е���Ӯ��BUG                            "<<endl;
	cout<<"4.�޸�AIѪ��Ϊ0��û��Ϸ������BUG                               "<<endl;
	getchar();
	system("cls");
}
int main()
{
	srand((unsigned int)(time(NULL)));
	op op;
	player player;
	computer AI;
	int over,rps;
	op.introduce();
	while (true)
	{
		over=op.gameover(player,AI);
		if (over!=0)
		{
			if (over==1)
			{
				cout<<"AIʤ���ˣ�"<<endl;
				getchar();
				return 0;
			}
			else
			{
				cout<<"��ʤ���ˣ�"<<endl;
				getchar();
				return 0;
			}
		}
		rps=op.rps();
		if (rps==1)
		{
			if (player.choosemenu()==1) AI.injured(10);
		}
		else if (rps==2)
		{
			AI.AIchoose();
		}
		getchar();
		system("cls");
	}
	return 0;
}
