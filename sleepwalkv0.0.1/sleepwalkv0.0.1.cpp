#include <iostream>
using namespace std;
class op
{
	public:
		int rps();
		int gameover(int playerhealth,int computerhealth);
		void gamemenu();
};
int op::rps()
{
	return 0;
}
int op::gameover(int playerhealth,int computerhealth)
{
	if (playerhealth<0)
	{
		return 1;
	}
	else if (computerhealth<0)
	{
		return 2;
	}
	return 0;
}
void op::gamemenu()
{
	cout<<endl;
	cout<<"                             ����v0.0.1	                      "<<endl;
	cout<<"                             (��ʼ�汾)                        "<<endl;
	cout<<"                     �����ߣ�daniel(�����޵в���)              "<<endl;
	cout<<"                            ����������69                       "<<endl;
	cout<<"                                                               "<<endl;
	cout<<"��ʼ�汾���ݣ�                                                 "<<endl;
	cout<<"1.�޸���������BUG                                              "<<endl;
	cout<<"2.��д�˻����Ǽ�                                               "<<endl;
}
class generalplayer
{
	protected:
		int health=100;
		int shield=0;
};
class player:public generalplayer
{
	public:
		int choosemenu();
};
int player::choosemenu()
{
	return 0;
}
class computer:public generalplayer
{
	public:
		int AIchoose();
};
int computer::AIchoose()
{
	return 0;
}
int main()
{
	op op1;
	op1.gamemenu();
	getchar();
	return 0;
}
