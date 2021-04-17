#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>


//输出二维数组信息

void Print_arr(int arr[][4],int row,int col)//优化，试着让时间复杂度为O(n)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%2d   ",arr[i][j]);
		}
		printf("\n");
	}
}

bool Move_up(int arr[][4])//将数组整体向上移动
{
	int flg=0;
	for(int i=1;i<4;i++)//整个数组内容向上移动。从第一行开始，不必要看0行内容。
	{
		for(int j=0;j<4;j++)
		{
			int k=0;
			if(arr[i][j]!=0&&arr[i-1][j]==0)//上行由空位置，则必然要向上移动。
			{
				flg=1;
				while(arr[k][j]!=0)//从0行开始查找，看哪行的这一列是空位置。
				{
					k++;
				}
				arr[k][j]=arr[i][j];
				arr[i][j]=0;
			}
		}
	}
	if(flg==1)
	{
		return true;
	}
	return false;
}

bool Move_down(int arr[][4])//将数组整体向下移动
{
	int flg=0;
	for(int i=2;i>=0;i--)//整个数组内容向下移动。从倒数第2行开始，不必要看倒数第一行内容。
	{
		for(int j=0;j<4;j++)
		{
			int k=3;
			if(arr[i][j]!=0&&arr[i+1][j]==0)//下行有空位置，则必然要向下移动。
			{
				flg=1;
				while(arr[k][j]!=0)//从最后一行开始查找，看哪行的这一列是空位置。
				{
					k--;
				}
				arr[k][j]=arr[i][j];
				arr[i][j]=0;
			}
		}
	}
	if(flg==1)
	{
		return true;
	}
	return false;
}


bool Move_left(int arr[][4])//将数组整体向左移动
{
	int flg=0;
	for(int j=1;j<=3;j++)//整个数组内容向左移动。从第二列开始，不必要看第一列内容。
	{
		for(int i=0;i<4;i++)
		{
			int k=0;
			if(arr[i][j]!=0&&arr[i][j-1]==0)//左列有空位置，则必然要向左移动。
			{
				flg=1;
				while(arr[i][k]!=0)//从最左一列开始查找，看哪列的这一行是空位置。
				{
					k++;
				}
				arr[i][k]=arr[i][j];
				arr[i][j]=0;
			}
		}
	}
	if(flg==1)
	{
		return true;
	}
	return false;
}

bool Move_right(int arr[][4])//将数组整体向右移动
{
	int flg=0;
	for(int j=2;j>=0;j--)//整个数组内容向右移动。从倒数第二列开始，不必要看最后一列内容。
	{
		for(int i=0;i<4;i++)
		{
			int k=3;
			if(arr[i][j]!=0&&arr[i][j+1]==0)//右列有空位置，则必然要向右移动。
			{
				flg=1;
				while(arr[i][k]!=0)//从最右一列开始查找，看哪列的这一行是空位置。
				{
					k--;
				}
				arr[i][k]=arr[i][j];
				arr[i][j]=0;
			}
		}
	}
	if(flg==1)
	{
		return true;
	}
	return false;
}

bool merg_up(int arr[][4])//向上合并
{
	int flg=0;
	for(int i=1;i<4;i++)//向上方向上若有靠近极限上的相邻两个数字相同，则将两个数字合并到靠近极限的位置上。
	{
		for(int j=0;j<4;j++)//合并相同数
		{
			if(arr[i][j]!=0&&arr[i][j]==arr[i-1][j])
			{
				flg=1;
				arr[i-1][j]=2*arr[i][j];
				arr[i][j]=0;
			}
		}
	}
	if(flg==1)
	{
		return true;
	}
	return false;
}

bool merg_down(int arr[][4])//向下合并
{
	int flg=0;
	for(int i=2;i>=0;i--)//向下方向下若有靠近极限上的相邻两个数字相同，则将两个数字合并到靠近极限的位置上。
	{
		for(int j=0;j<4;j++)//合并相同数
		{
			if(arr[i][j]!=0&&arr[i][j]==arr[i+1][j])
			{
				flg=1;
				arr[i+1][j]=2*arr[i][j];
				arr[i][j]=0;
			}
		}
	}
	if(flg==1)
	{
		return true;
	}
	return false;
}



bool merg_left(int arr[][4])//向左合并
{
	int flg=0;
	for(int i=0;i<4;i++)//向左方向上若有靠近极限上的相邻两个数字相同，则将两个数字合并到靠近极限的位置上。
	{
		for(int j=1;j<4;j++)//合并相同数
		{
			if(arr[i][j]!=0&&arr[i][j]==arr[i][j-1])
			{
				flg=1;
				arr[i][j-1]=2*arr[i][j];
				arr[i][j]=0;
			}
		}
	}
	if(flg==1)
	{
		return true;
	}
	return false;
}

bool merg_right(int arr[][4])//向右合并
{
	int flg=0;
	for(int i=0;i<4;i++)//向右方向上若有靠近极限上的相邻两个数字相同，则将两个数字合并到靠近极限的位置上。
	{
		for(int j=2;j>=0;j--)//合并相同数,从倒数第二列开始算起合并
		{
			if(arr[i][j]!=0&&arr[i][j]==arr[i][j+1])
			{
				flg=1;
				arr[i][j+1]=2*arr[i][j];
				arr[i][j]=0;
			}
		}
	}
	if(flg==1)
	{
		return true;
	}
	return false;
}


void Newnumber(int arr[][4])//在数组空位置上产生新数字。
{
	int row,col;
	while(1)//产生一个新数字
	{
		int j=rand()%16+1;//[1,17)//随机产生第几个格子
		row=(j-1)/4;
		col=(j-1)%4;//由产生的格子数，计算出相应在数组中的位置。
		if(arr[row][col]==0)//若产生的格子中已经存在数字，则要重新随机产生数字。
		{
			break;
		}
	}
	int num=rand()%3+1;//产生[1,3)的随机数
	if(num%2!=0)
	{
		 num++;
	}
	arr[row][col]=num;
}

void Init_game(int arr[][4])//初始化游戏
{
	int row,col;
	for(int k=0;k<2;k++)//游戏刚开始，先产生两个随机数
	{
		while(1)
		{
			int j=rand()%16+1;//[1,17)//随机产生第几个格子
			row=(j-1)/4;
			col=(j-1)%4;//由产生的格子数，计算出相应在数组中的位置。
			if(arr[row][col]==0)//若产生的格子中已经存在数字，则要重新随机产生数字。
			{
				break;
			}
		}
		int num=rand()%3+1;//产生[1,3)的随机数
		if(num%2!=0)
		{
			 num++;
		}
		arr[row][col]=num;
	}
}

bool total_Move_up(int arr[][4])//数组整体向上移动，该合并的合并
{
	bool a=Move_up(arr);//有可能向上不能再移动了，但是向上方向上有可以合并的数子，也可以使用下方的函数代码段，实现。
	bool b=merg_up(arr);
	Move_up(arr);
	if(a==true||b==true)
	{
		return true;
	}
	return false;
}

bool total_Move_down(int arr[][4])//数组整体向下移动，该合并的合并
{
	bool a=Move_down(arr);//有可能向上不能再移动了，但是向上方向上有可以合并的数子，也可以使用下方的函数代码段，实现。
	bool b=merg_down(arr);
	Move_down(arr);
	if(a==true||b==true)
	{
		return true;
	}
	return false;
}

bool total_Move_left(int arr[][4])//数组整体向左移动，该合并的合并
{
	
	bool a=Move_left(arr);
	bool b=merg_left(arr);
	Move_left(arr);
	if(a==true||b==true)
	{
		return true;
	}
	return false;
}

bool total_Move_right(int arr[][4])//数组整体向左移动，该合并的合并,只要有数据的改变则就返回真，否则返回假
{
	bool a=Move_right(arr);
	bool b=merg_right(arr);
	Move_right(arr);
	if(a||b)
	{
		return true;
	}
	return false;
}

void Up(int arr[][4])//将向上移动封装
{
	if(total_Move_up(arr))
	{
		Newnumber(arr);//在数组空位置上产生新数字。
		system("CLS");
		Print_arr(arr,4,4);
		//system("PAUSE");
	}
}

void Down(int arr[][4])//将向下移动封装
{
	if(total_Move_down(arr))
	{
		Newnumber(arr);//在数组空位置上产生新数字。
		system("CLS");
		Print_arr(arr,4,4);
		//system("PAUSE");
	}
}

void Left(int arr[][4])//将向左移动封装
{
		if(total_Move_left(arr))
		{
			Newnumber(arr);//在数组空位置上产生新数字。
			system("CLS");
			Print_arr(arr,4,4);
		}
}

void Right(int arr[][4])//将向右移动封装
{
		if(total_Move_right(arr))//整体移动并合并
		{
			Newnumber(arr);//在数组空位置上产生新数字。
			system("CLS");
			Print_arr(arr,4,4);
		}
}

void My_copy(int arr[][4],int brr[][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			brr[i][j]=arr[i][j];
		}
	}
}

int main()
{
	int arr[4][4]={0};
	int brr[4][4]={0};
	srand(time(NULL));//骰子

	Init_game(arr);//初始化游戏
	Print_arr(arr,4,4);

	int key; //定义key,用于接收按键键值
	
	while(key = getch()) //等待按键
	{
		switch(key)
		{
			case 72: Up(arr); break;
			case 80: Down(arr); break;
			case 75: Left(arr); break;
			case 77: Right(arr); break;
			case 27: return 0; //键值27为Esc键，当按下这个键时退出程序
		}

		My_copy(arr,brr);
		if((total_Move_right(brr)||total_Move_left(brr)||total_Move_up(brr)||total_Move_down(brr))==false)
		{
			printf("Game Over   技不如人，再接再厉——哈哈哈\n");
			return 0;
		}

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(arr[i][j]==2048)
				{
					printf("恭喜通关\n");
					return 0;
				}
			}
		}
	}
	return 0; 
}

/*
1、刚进入游戏，先随机选择两个位置，在两个位置上随机产生数字2或4。要满足两次产生的位置不同。
   可以由产生位置的数字是否是0进行判断此处是否已经有数字。
2、用system函数让屏幕暂停。
3、通过方向键使数组中已经存在的数字向你输入的方向极限整体移动。
4、寻找最边界的空位置。
5、如果在移动到极限后，靠最边的两个数字值相同，则合并这两个数放到接近极限边的位置。
6、产生新数，随机在二维数组中选择一个位置，这个位置上的数字要满足初始值不为0，然后再在这个位置上随机产生数字2或4存入这个位置。

//在产生新数字之前就要先判断游戏是否已经结束，也就是判断当前数组中是否还有空位置，这样就避免了陷入产生新数字的死循环中。


如何判断游戏结束:如果向上下左右都无法产生新数字，即数组整体都无法在向任意方向移动则游戏结束。
将游戏中的数组完全拷贝到另一个新数组中，然后对新数组进行上下左右的完全移动，若都没有移动成功，则说明游戏结束。

*/
