#include <stdio.h>

int odd_ones(unsigned int x, int *contBit1 )//Mudei o parâmetro para receber o contador na main
{
    int contadorBitsUm = 0;
    while (x != 0)
    {
        if( (x&1) == 1)
        {
            contadorBitsUm++;
        }
        x >>= 1;
    }

    *contBit1 = contadorBitsUm;

    int verfOdd_Con = contadorBitsUm & 1;

    return (verfOdd_Con == 1) ? 1 : 0;
}

//Na função temos um int (4 bytes = 32 bits)
// No qual eu vefico bit a bit e faço um shift uma casa de bit para a direita
// Contando a cada vez que eu encontrar um bit = 1
// De pois que eu tenho esse valor em decimal interiro de quantos bit's 1 eu tenho
// Verifico se esse número termina com o bit 0 ou com o bit 1
// Se terminar com o bit zero é por que é par e se terminar com o bit 1 é ímpar (digo "terminar" lendo da esquerda pra direita)



int main(void)
{
    unsigned int x = 7;
    int contBit1 = 0;

    int odd_con = odd_ones(x, &contBit1);

    printf("Número verificado foi: %u \n\n", x);

    printf("O contador de bits 1 foi: %d --> ", contBit1);
    if(odd_con == 1)
    {
        printf("É Ímpar\n\n");
    }
    else
    {
        printf("É par\n\n");
    }
    
    printf("Num contador de Bits em binário: %08b\n", contBit1);

    return 0;
}



//Exemplo:

// Primeira interação:
// contador = 0
//x = 6:  0000 0000 0000 0000 0000 0000 0000 0110
//Oper:  &
//Mask:   0000 0000 0000 0000 0000 0000 0000 0001
//-------------------------------------------------
//        0000 0000 0000 0000 0000 0000 0000 0000
// shift >>=1

// Segunda interação:
//
//x = 3:  0000 0000 0000 0000 0000 0000 0000 0011
//Oper:  &
//Mask:   0000 0000 0000 0000 0000 0000 0000 0001
//-------------------------------------------------
//        0000 0000 0000 0000 0000 0000 0000 0001
// contador = 1
// shift >>= 1

//E por ai segue. No exemplo do 6 o contador vai contar 2 números de bit 1.

