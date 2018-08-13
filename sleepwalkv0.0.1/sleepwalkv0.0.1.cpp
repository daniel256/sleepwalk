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
	cout<<"                             梦游v0.0.1	                      "<<endl;
	cout<<"                             (初始版本)                        "<<endl;
	cout<<"                     开发者：daniel(超级无敌菜鸟)              "<<endl;
	cout<<"                            代码行数：69                       "<<endl;
	cout<<"                                                               "<<endl;
	cout<<"初始版本内容：                                                 "<<endl;
	cout<<"1.修复中文乱码BUG                                              "<<endl;
	cout<<"2.编写了基础骨架                                               "<<endl;
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
