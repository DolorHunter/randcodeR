#pragma once

void rand_num_type(int bit, char (&code)[10][80])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<bit;j++)
        {
            code[i][j] = rand()%10+'0'-0;
            code[i][j+1] = '\0';
        }

        std::cout << i << "\t" << code[i] << std::endl;
    }
}
