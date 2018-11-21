#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
int main (void)
{
    setlocale(LC_ALL, "Portuguese");
    int op, exit=0;
    float pi=3.1415;
    while (exit != 1)
    {
        system("cls");
        printf("\n\n-----------------------MENU-----------------------------\n");
        printf("\n PARA CALCULAR O TORQUE INTERNO.......................'1' ");
        printf("\n PARA CALCULAR A TENSÃO DE CISALHAMENTO MAX...........'2' ");
        printf("\n PARA CALCULAR O RAIO DA SEÇÃO TRANSVERSAL............'3' ");
        printf("\n PARA DIMENSIONAR UM EIXO.............................'4' ");
        printf("\n PARA CALCULAR A FREQUÊNCIA EM UM EIXO................'5' ");
        printf("\n PARA CALCULAR O ÂNGULO DE TORÇÃO.....................'6' ");
        printf("\n PARA SAIR DIGITE.....................................'0' ");
        printf("\n\n Digite sua Opção: ");
        scanf("%i", &op);
        switch(op)
        {
        case 1:
            {
                system("cls");
                printf("\n TODAS AS ENTRADAS NO S.I \n");
                double TC_M, Rd, Tq,J;
                printf("\n Digite Tensão de Cisalhamento Máxima: ");
                scanf("%lf", &TC_M);
                printf("\n Digite Raio da Seção Transversal: ");
                scanf("%lf", &Rd);
                J=(pi/2)*(pow(Rd, 4));
                printf("\n Momento de inercia polar é: %.12f m^4", J);
                Tq=(J*TC_M)/Rd;
                printf("\n\n O Torque atuando é: %.3f N*m", Tq);
                getch();
                break;
            }
        case 2:
            {
                system("cls");
                printf("\n TODAS AS ENTRADAS NO S.I \n");
                double TC_M, Rd, J, Tq;
                printf("\n Digite o Torque: ");
                scanf("%lf", &Tq);
                printf("\n Digite Raio da Seção Transversal: ");
                scanf("%lf", &Rd);
                J=(pi/2)*pow(Rd, 4);
                printf("\n Momento de inercia polar é: %.12f m^4", J);
                TC_M=((Tq*Rd)/J)*pow(10, 6);
                printf("\n\n A Tensão de Cisalhamento MAX é: %.3f MN/m^2", TC_M);
                getch();
                break;
            }
            case 3:
            {
                system("cls");
                printf("\n TODAS AS ENTRADAS NO S.I \n");
                double TC_M, Rd, J, Tq, a;
                printf("\n Digite o Torque: ");
                scanf("%lf", &Tq);
                printf("\n Digite Tensão de Cisalhamento Máxima: ");
                scanf("%lf", &TC_M);
                a=(pi/2)*TC_M;
                Rd=pow(Tq/a,0.3334);
                printf("\n\n O Raio é: %.3f m", Rd);
                J=(pi/2)*pow(Rd, 4);
                printf("\n Momento de inercia polar é: %.16f m^4", J);
                getch();
                break;
            }
            case 4:
            {
                system("cls");
                printf("\n TODAS AS ENTRADAS NO S.I \n");
                double V_Ang, Pot, TC_M, Tq, Diam;
                printf("\n Digite Tensão de Cisalhamento Máxima: ");
                scanf("%lf", &TC_M);
                printf("\n Digite Velocidade Angular: ");
                scanf("%lf", &V_Ang);
                printf("\n Digite A Potência: ");
                scanf("%lf", &Pot);
                Tq=Pot/V_Ang;
                Diam=2*pow(((2*Tq)/(pi*TC_M)),0.3334);
                printf("O Diametro do Eixo deve ser de: %.6f m", Diam);
                getch();
                break;
            }
            case 5:
                {
                    system("cls");
                    printf("\n ATENÇÃO! TODAS AS ENTRADAS NO S.I \n");
                    int yon;
                    printf("\nO tubo tem 2 diametros? s='1' n='0' ");
                    scanf("%d", &yon);
                    if(yon == 1)
                    {
                        double R_int, R_ext, freq, Pot, TC_M, Tq, DR, J;
                        printf("\n Digite Raio interno da Seção Transversal: ");
                        scanf("%lf", &R_int);
                        printf("\n Digite Raio externo da Seção Transversal: ");
                        scanf("%lf", &R_ext);
                        DR=R_ext-R_int;
                        printf("\n Digite Tensão de Cisalhamento Máxima: ");
                        scanf("%lf", &TC_M);
                        printf("\n Digite Potência: ");
                        scanf("%lf", &Pot);
                        J=(pi/2)*pow(DR, 4);
                        Tq=(J*TC_M)/DR;
                        freq=Pot/(2*pi*Tq);
                        printf("\n A frequência maxima é: %.5f Hz", freq);
                    }
                    else
                    {
                        double V_Ang, Pot, TC_M, Tq, Rd, J, freq;
                        printf("\n Digite Tensão de Cisalhamento Máxima: ");
                        scanf("%lf", &TC_M);
                        printf("\n Digite Raio da Seção Transversal: ");
                        scanf("%lf", &Rd);
                        printf("\n Digite Potência: ");
                        scanf("%lf", &Pot);
                        J=(pi/2)*pow(Rd, 4);
                        Tq=(J*TC_M)/Rd;
                        freq=Pot/(2*pi*Tq);
                        printf("\n A frequência maxima é: %.5f Hz", freq);
                    }
                    getch();
                    break;
                }
            case 6:
            {
                system("cls");
                printf("\n ATENÇÃO! TODAS AS ENTRADAS NO S.I \n");
                double Ang, ME, Tq, Rd, Cmp, J;
                printf("\n Digite o Torque: ");
                scanf("%lf", &Tq);
                printf("\n Digite o Modulo de Elasticidade do material: ");
                scanf("%lf", &ME);
                printf("\n Digite Raio da Seção Transversal: ");
                scanf("%lf", &Rd);
                printf("\n Digite o Comprimento da barra: ");
                scanf("%lf", &Cmp);
                J=(pi/2)*pow(Rd, 4);
                Ang=(Tq*Cmp)/(J*M_E);
                printf("\n O Ângulo de Torção é: %.5f Rad", Ang);
                getch();
                break;
            }
            case 0:
            {
                exit=1;
                break;
            }
        }
    }
return -1;
}
