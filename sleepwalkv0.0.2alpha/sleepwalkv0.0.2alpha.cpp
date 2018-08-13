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
	cout<<endl<<"请做出你的选择"<<endl;
	cout<<"1.用拳头攻击"<<endl;
	cout<<"2.什么都不做"<<endl;
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
		cout<<"玩家：石头    "<<"电脑：石头"<<endl;
		cout<<"平局"<<endl;
		return 0;
	}
	else if (a==1 && b==1)
	{
		cout<<"玩家：剪刀    "<<"电脑：剪刀"<<endl;
		cout<<"平局"<<endl;
		return 0;
	}
	else if (a==2 && b==2)
	{
		cout<<"玩家：布    "<<"电脑：布"<<endl;
		cout<<"平局"<<endl;
		return 0;
	}
	else if (a==0 && b==1)
	{
		cout<<"玩家：石头    "<<"电脑：剪刀"<<endl;
		cout<<"你赢得了选择权"<<endl;
		return 1;
	}
	else if (a==1 && b==0)
	{
		cout<<"玩家：剪刀    "<<"电脑：石头"<<endl;
		cout<<"电脑赢得了选择权"<<endl;
		return 2;
	}
	else if (a==0 && b==2)
	{
		cout<<"玩家：石头    "<<"电脑：布"<<endl;
		cout<<"电脑赢得了选择权"<<endl;
		return 2;
	}
	else if (a==2 && b==0)
	{
		cout<<"玩家：布    "<<"电脑：石头"<<endl;
		cout<<"你赢得了选择权"<<endl;
		return 1;
	}
	else if (a==1 && b==2)
	{
		cout<<"玩家：剪刀    "<<"电脑：布"<<endl;
		cout<<"你赢得了选择权"<<endl;
		return 1;
	}
	else if (a==2 && b==1)
	{
		cout<<"玩家：布    "<<"电脑：剪刀"<<endl;
		cout<<"电脑赢得了选择权"<<endl;
		return 2;
	}
	return 0;
}
int op::gameover(player &player,computer &AI)
{
	cout<<"玩家血量:"<<player.health<<endl;
	cout<<"电脑血量:"<<AI.health<<endl<<endl;
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
	cout<<"                             梦游v0.0.2	                      "<<endl;
	cout<<"                             (测试版本)                        "<<endl;
	cout<<"                     开发者：daniel(超级无敌菜鸟)              "<<endl;
	cout<<"                            代码行数：196                      "<<endl;
	cout<<"                                                               "<<endl;
	cout<<"更新内容：                                                     "<<endl;
	cout<<"1.增加了基础的玩家攻击机制                                     "<<endl;
	cout<<"2.增加了玩家石头剪刀布赢了后的选择界面                         "<<endl;
	cout<<"3.修复石头剪刀布平局会判电脑赢的BUG                            "<<endl;
	cout<<"4.修复AI血量为0还没游戏结束的BUG                               "<<endl;
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
				cout<<"AI胜利了！"<<endl;
				getchar();
				return 0;
			}
			else
			{
				cout<<"你胜利了！"<<endl;
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
