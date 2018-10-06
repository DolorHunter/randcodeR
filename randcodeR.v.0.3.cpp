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
    printf("===随机密码生成器===\n");
    printf("选择密码生成规则:\n0.纯数字\n1.数字+英文小写\n2.数字+英文混合\n3.expert_prototype\n请输入选择序号:");
    scanf("%d",&chose);
    srand((int)time(0));
    if(chose<0||chose>3)
    {
        printf("使用的规则错误!");
        return -1;
    }
    else
    {
        printf("请输入密码位数:");
        scanf("%d",&bit);
        printf("\n");
        for(i=0;i<10;i++)   //每组输出10个密码方便强迫症选择
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
