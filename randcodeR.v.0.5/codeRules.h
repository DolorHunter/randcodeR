#pragma once
#include<iostream>
#define MAXLEN 1024

using namespace std;

//数字
void rand_num(const int bit, char (&code)[10][MAXLEN])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<bit;j++)
        {
            code[i][j] = rand()%10+'0'-0;
            code[i][j+1] = '\0';
        }

        cout << i << "\t" << code[i] << endl;
    }
}

//数字+英文小写
void rand_en_num(const int bit, char (&code)[10][MAXLEN])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<bit;j++)
        {
            if(rand()%2==0)
            {
                code[i][j] = rand()%10+'0'-0;
                code[i][j+1] = '\0';
            }
            else
            {
                code[i][j] = rand()%26 + 97;
                code[i][j+1] = '\0';
            }
        }

        cout << i << "\t" << code[i] << endl;
    }
}

//数字+英文大小写
void rand_en_num_pro(const int bit, char (&code)[10][MAXLEN])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<bit;j++)
        {
            if(rand()%3==0)
            {
                code[i][j] = rand()%10+'0'-0;
                code[i][j+1] = '\0';
            }
            else
                if(rand()%3==1)
                {
                    code[i][j] = rand()%26 + 65;
                    code[i][j+1] = '\0';
                }
                else
                {
                    code[i][j] = rand()%26 + 97;
                    code[i][j+1] = '\0';
                }
        }

        cout << i << "\t" << code[i] << endl;
    }
}

//专家(字符型)
void rand_expert(const int bit, char (&code)[10][MAXLEN])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<bit;j++)
        {
            code[i][j] = rand()%95 + 32;
            code[i][j+1] = '\0';
        }

        cout << i << "\t" << code[i] <<endl;
    }
}
