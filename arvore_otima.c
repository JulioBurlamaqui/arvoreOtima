#include <stdio.h>
#include <stdlib.h>

//Teste: 3 1 1 1 3 5 6 1 2 3 4

int main()
{
    short tam, i, j, k, kFinal = 0, minimo, temp, custoOtimo;
    scanf("%hd", &tam);

    int chaves[tam], f[tam], f_[tam+1];
    int tabela[tam+1][tam+1], custo[tam+1][tam+1], soma[tam+1][tam+1];

    for(i = 0; i < tam; i++)
        scanf("%d", &chaves[i]);

    for(i = 0; i < tam; i++)
        scanf("%d", &f[i]);

    for(i = 0; i <= tam; i++)
        scanf("%d", &f_[i]);

    for(i = 0; i <= tam; i++)
    {
        tabela[i][i] = 0;
        custo[i][i] = 0;
        soma[i][i] = f_[i];

        for(j = 0; j < tam - i; j++)
            soma[i][i+1+j] = soma[i][i+j] + f[i+j] + f_[i+j+1];

        if(i < tam)
        {
            tabela[i][i+1] = i+1;
            custo[i][i+1] = soma[i][i+1];
        }     
    }

    for(i = 2; i <= tam ; i++)
    {
        for(j = 0; j <= tam; j++)
           {
                if(i+j <= tam)
                    {
                        minimo = 999;
                        for(k = j + 1; k < j + 3; k++)
                        {
                            temp = custo[j][k-1] + custo[k][i+j] + soma[j][i+j];
                            if(temp < minimo)
                            {
                                minimo = temp;
                                kFinal = k;
                            }
                        }
                        custo[j][i+j] = minimo;
                        tabela[j][i+j] = kFinal;
                    }
                else
                    break;
           }
    }

    for(i = 0; i <= tam ; i++)
    {
        for(j = 0; j <= tam; j++)
           {
                if(i+j <= tam)
                    {
                        printf("Custo[%hd][%hd] = %hd\n", j, i + j, custo[j][i+j]);
                    }
                else
                    break;
           }
    }

    custoOtimo = custo[0][tam];

    printf("Custo ótimo = %hd", custoOtimo);

    return 0;
}