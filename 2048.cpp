#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>


//�����ά������Ϣ

void Print_arr(int arr[][4],int row,int col)//�Ż���������ʱ�临�Ӷ�ΪO(n)
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

bool Move_up(int arr[][4])//���������������ƶ�
{
	int flg=0;
	for(int i=1;i<4;i++)//�����������������ƶ����ӵ�һ�п�ʼ������Ҫ��0�����ݡ�
	{
		for(int j=0;j<4;j++)
		{
			int k=0;
			if(arr[i][j]!=0&&arr[i-1][j]==0)//�����ɿ�λ�ã����ȻҪ�����ƶ���
			{
				flg=1;
				while(arr[k][j]!=0)//��0�п�ʼ���ң������е���һ���ǿ�λ�á�
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

bool Move_down(int arr[][4])//���������������ƶ�
{
	int flg=0;
	for(int i=2;i>=0;i--)//�����������������ƶ����ӵ�����2�п�ʼ������Ҫ��������һ�����ݡ�
	{
		for(int j=0;j<4;j++)
		{
			int k=3;
			if(arr[i][j]!=0&&arr[i+1][j]==0)//�����п�λ�ã����ȻҪ�����ƶ���
			{
				flg=1;
				while(arr[k][j]!=0)//�����һ�п�ʼ���ң������е���һ���ǿ�λ�á�
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


bool Move_left(int arr[][4])//���������������ƶ�
{
	int flg=0;
	for(int j=1;j<=3;j++)//�����������������ƶ����ӵڶ��п�ʼ������Ҫ����һ�����ݡ�
	{
		for(int i=0;i<4;i++)
		{
			int k=0;
			if(arr[i][j]!=0&&arr[i][j-1]==0)//�����п�λ�ã����ȻҪ�����ƶ���
			{
				flg=1;
				while(arr[i][k]!=0)//������һ�п�ʼ���ң������е���һ���ǿ�λ�á�
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

bool Move_right(int arr[][4])//���������������ƶ�
{
	int flg=0;
	for(int j=2;j>=0;j--)//�����������������ƶ����ӵ����ڶ��п�ʼ������Ҫ�����һ�����ݡ�
	{
		for(int i=0;i<4;i++)
		{
			int k=3;
			if(arr[i][j]!=0&&arr[i][j+1]==0)//�����п�λ�ã����ȻҪ�����ƶ���
			{
				flg=1;
				while(arr[i][k]!=0)//������һ�п�ʼ���ң������е���һ���ǿ�λ�á�
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

bool merg_up(int arr[][4])//���Ϻϲ�
{
	int flg=0;
	for(int i=1;i<4;i++)//���Ϸ��������п��������ϵ���������������ͬ�����������ֺϲ����������޵�λ���ϡ�
	{
		for(int j=0;j<4;j++)//�ϲ���ͬ��
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

bool merg_down(int arr[][4])//���ºϲ�
{
	int flg=0;
	for(int i=2;i>=0;i--)//���·��������п��������ϵ���������������ͬ�����������ֺϲ����������޵�λ���ϡ�
	{
		for(int j=0;j<4;j++)//�ϲ���ͬ��
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



bool merg_left(int arr[][4])//����ϲ�
{
	int flg=0;
	for(int i=0;i<4;i++)//�����������п��������ϵ���������������ͬ�����������ֺϲ����������޵�λ���ϡ�
	{
		for(int j=1;j<4;j++)//�ϲ���ͬ��
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

bool merg_right(int arr[][4])//���Һϲ�
{
	int flg=0;
	for(int i=0;i<4;i++)//���ҷ��������п��������ϵ���������������ͬ�����������ֺϲ����������޵�λ���ϡ�
	{
		for(int j=2;j>=0;j--)//�ϲ���ͬ��,�ӵ����ڶ��п�ʼ����ϲ�
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


void Newnumber(int arr[][4])//�������λ���ϲ��������֡�
{
	int row,col;
	while(1)//����һ��������
	{
		int j=rand()%16+1;//[1,17)//��������ڼ�������
		row=(j-1)/4;
		col=(j-1)%4;//�ɲ����ĸ��������������Ӧ�������е�λ�á�
		if(arr[row][col]==0)//�������ĸ������Ѿ��������֣���Ҫ��������������֡�
		{
			break;
		}
	}
	int num=rand()%3+1;//����[1,3)�������
	if(num%2!=0)
	{
		 num++;
	}
	arr[row][col]=num;
}

void Init_game(int arr[][4])//��ʼ����Ϸ
{
	int row,col;
	for(int k=0;k<2;k++)//��Ϸ�տ�ʼ���Ȳ������������
	{
		while(1)
		{
			int j=rand()%16+1;//[1,17)//��������ڼ�������
			row=(j-1)/4;
			col=(j-1)%4;//�ɲ����ĸ��������������Ӧ�������е�λ�á�
			if(arr[row][col]==0)//�������ĸ������Ѿ��������֣���Ҫ��������������֡�
			{
				break;
			}
		}
		int num=rand()%3+1;//����[1,3)�������
		if(num%2!=0)
		{
			 num++;
		}
		arr[row][col]=num;
	}
}

bool total_Move_up(int arr[][4])//�������������ƶ����úϲ��ĺϲ�
{
	bool a=Move_up(arr);//�п������ϲ������ƶ��ˣ��������Ϸ������п��Ժϲ������ӣ�Ҳ����ʹ���·��ĺ�������Σ�ʵ�֡�
	bool b=merg_up(arr);
	Move_up(arr);
	if(a==true||b==true)
	{
		return true;
	}
	return false;
}

bool total_Move_down(int arr[][4])//�������������ƶ����úϲ��ĺϲ�
{
	bool a=Move_down(arr);//�п������ϲ������ƶ��ˣ��������Ϸ������п��Ժϲ������ӣ�Ҳ����ʹ���·��ĺ�������Σ�ʵ�֡�
	bool b=merg_down(arr);
	Move_down(arr);
	if(a==true||b==true)
	{
		return true;
	}
	return false;
}

bool total_Move_left(int arr[][4])//�������������ƶ����úϲ��ĺϲ�
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

bool total_Move_right(int arr[][4])//�������������ƶ����úϲ��ĺϲ�,ֻҪ�����ݵĸı���ͷ����棬���򷵻ؼ�
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

void Up(int arr[][4])//�������ƶ���װ
{
	if(total_Move_up(arr))
	{
		Newnumber(arr);//�������λ���ϲ��������֡�
		system("CLS");
		Print_arr(arr,4,4);
		//system("PAUSE");
	}
}

void Down(int arr[][4])//�������ƶ���װ
{
	if(total_Move_down(arr))
	{
		Newnumber(arr);//�������λ���ϲ��������֡�
		system("CLS");
		Print_arr(arr,4,4);
		//system("PAUSE");
	}
}

void Left(int arr[][4])//�������ƶ���װ
{
		if(total_Move_left(arr))
		{
			Newnumber(arr);//�������λ���ϲ��������֡�
			system("CLS");
			Print_arr(arr,4,4);
		}
}

void Right(int arr[][4])//�������ƶ���װ
{
		if(total_Move_right(arr))//�����ƶ����ϲ�
		{
			Newnumber(arr);//�������λ���ϲ��������֡�
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
	srand(time(NULL));//����

	Init_game(arr);//��ʼ����Ϸ
	Print_arr(arr,4,4);

	int key; //����key,���ڽ��հ�����ֵ
	
	while(key = getch()) //�ȴ�����
	{
		switch(key)
		{
			case 72: Up(arr); break;
			case 80: Down(arr); break;
			case 75: Left(arr); break;
			case 77: Right(arr); break;
			case 27: return 0; //��ֵ27ΪEsc���������������ʱ�˳�����
		}

		My_copy(arr,brr);
		if((total_Move_right(brr)||total_Move_left(brr)||total_Move_up(brr)||total_Move_down(brr))==false)
		{
			printf("Game Over   �������ˣ��ٽ���������������\n");
			return 0;
		}

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(arr[i][j]==2048)
				{
					printf("��ϲͨ��\n");
					return 0;
				}
			}
		}
	}
	return 0; 
}

/*
1���ս�����Ϸ�������ѡ������λ�ã�������λ���������������2��4��Ҫ�������β�����λ�ò�ͬ��
   �����ɲ���λ�õ������Ƿ���0�����жϴ˴��Ƿ��Ѿ������֡�
2����system��������Ļ��ͣ��
3��ͨ�������ʹ�������Ѿ����ڵ�������������ķ����������ƶ���
4��Ѱ����߽�Ŀ�λ�á�
5��������ƶ������޺󣬿���ߵ���������ֵ��ͬ����ϲ����������ŵ��ӽ����ޱߵ�λ�á�
6����������������ڶ�ά������ѡ��һ��λ�ã����λ���ϵ�����Ҫ�����ʼֵ��Ϊ0��Ȼ���������λ���������������2��4�������λ�á�

//�ڲ���������֮ǰ��Ҫ���ж���Ϸ�Ƿ��Ѿ�������Ҳ�����жϵ�ǰ�������Ƿ��п�λ�ã������ͱ�����������������ֵ���ѭ���С�


����ж���Ϸ����:������������Ҷ��޷����������֣����������嶼�޷��������ⷽ���ƶ�����Ϸ������
����Ϸ�е�������ȫ��������һ���������У�Ȼ�������������������ҵ���ȫ�ƶ�������û���ƶ��ɹ�����˵����Ϸ������

*/
