#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void rand_num_type(int bit);
void rand_en_num_type(int bit);
void rand_en_num_pro_type(int bit);
void rand_expert(int bit);

int main(void)
{
    int bit,chose;
    int i,j;
    printf("===�������������===\n");
    printf("ѡ���������ɹ���:\n0.������\n1.����+Ӣ��Сд\n2.����+Ӣ�Ļ��\n3.expert_prototype\n������ѡ�����:");
    scanf("%d",&chose);
    srand((int)time(0));
    if(chose<0||chose>3)
    {
        printf("ʹ�õĹ������!");
        return -1;
    }
    else
    {
        printf("����������λ��:");
        scanf("%d",&bit);
        printf("\n");
        for(i=0;i<10;i++)   //ÿ�����10�����뷽��ǿ��֢ѡ��
        {
            if(chose==0)
            {
                rand_num_type(bit);
            }
            else
                if(chose==1)
                {
                    rand_en_num_type(bit);
                }
                else
                    if(chose==2)
                    {
                        rand_en_num_pro_type(bit);
                    }
                    else
                    {
                        rand_expert(bit);
                    }

            printf("\n");
        }
    }
return 0;
}

void rand_num_type(int bit)
{
    int j;
    for(j=0;j<bit;j++)
    {
        printf("%d",rand()%10);
    }
}


void rand_en_num_type(int bit)
{
    int j;
    for(j=0;j<bit;j++)
    {
        if(rand()%2==0)
        {
            printf("%d",rand()%10);
        }
        else
        {
            printf("%c",rand()%26+65);
        }
    }

}


void rand_en_num_pro_type(int bit)
{
    int j;
    for(j=0;j<bit;j++)
    {
        if(rand()%3==0)
        {
            printf("%d",rand()%10);
        }
        else
            if(rand()%3==1)
            {
            printf("%c",rand()%26+65);
            }
            else
            {
                printf("%c",rand()%26+97);
            }
    }
}


void rand_expert(int bit)
{
    int j;
    for(j=0;j<bit;j++)
    {
        printf("%c",rand()%95+32);
    }
}
