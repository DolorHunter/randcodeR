 #pragma once

 void rand_en_num_type(int bit, char (&code)[10][80])
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

        std::cout << i << "\t" << code[i] << std::endl;
    }
}
