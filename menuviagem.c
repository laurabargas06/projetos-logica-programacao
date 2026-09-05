#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct horario
{
    int h;
    int mm;
} horario;
typedef struct data
{
    int d;
    int m;
    int a;
} data;
typedef struct passagens
{
    char origem[4];
    char destino[4];
    float valor;
    data x[2];
    horario y[2];
} passagens;
int main()
{
    passagens *point=(passagens *) malloc(1*sizeof(passagens));
    if (point == NULL)
    {
        printf("Erro ao alocar mem�ria.\n");
        return 1;
    }
    int qt;
    int op;
    printf("Menu:\n");
    printf("Opcao 0: Sair do programa:\n");
    printf("Opcao 1: Cadastro de passagem: \n");
    printf("Opcao 2: Imprimir passagem:\n");
    printf("Opcao 3: Consultar passagem:\n");
    printf("Opcao 4: Exportar para arquivo:\n");
    printf("Opcao 5: Importar para arquivo:\n");
    scanf("%d", &op);
    while(op!=0)
    {
        switch(op)
        {
        case 1:
        {
            int qtd;
            printf("Numero de passagens que voce deseja cadastrar:\n");
            scanf("%d", &qt);
            point= realloc(point, qt*sizeof(passagens));
            for(int i=0; i< qt; i++)
            {
                printf("Digite o valor da passagem:\n");
                scanf("%f", &point[i].valor);
                getchar();
                printf("Digite o local de origem:\n");
                fgets(point[i].origem,4,stdin);
                getchar();
                printf("Digite o local de destino:\n");
                fgets(point[i].destino,4,stdin);
                printf("Digite a data da partida:\n");
                scanf("%d %d %d", &point[i].x[0].d, &point[i].x[0].m, &point[i].x[0].a);
                printf("Digite o horario da partida:\n");
                scanf("%d %d", &point[i].y[0].h, &point[i].y[0].mm);
                printf("Digite a data da chegada:\n");
                scanf("%d %d %d", &point[i].x[1].d, &point[i].x[1].m, &point[i].x[1].a);
                printf("Digite o horario da chegada:\n");
                scanf("%d %d", &point[i].y[1].h, &point[i].y[1].mm);
            }
            break;
        }
        case 2:
        {
            int qtd;
            printf("Numero de passagens que voce deseja imprimir\n");
            scanf("%d", &qt);
            for(int i=0; i< qt; i++)
            {
                printf("Local de origem: %s\n", point[i].origem);
                printf("Local de partida: %s\n", point[i].destino);
                printf("Data de partida: %d/%d/%d\n", point[i].x[0].d, point[i].x[0].m, point[i].x[0].a);
                printf("Data de partida: %d/%d/%d\n", point[i].x[1].d, point[i].x[1].m, point[i].x[1].a);
            }
            break;
        }
        case 3:
        {
            int op;
            printf("\nSub menu:\n");
            printf("Opcao 1: Por aeroporto de origem:\n");
            printf("Opcao 2: Por aeroporto de destino:\n");
            printf("Opcao 3: Por data de partida:\n");
            printf("Opcao 4: Por valor especifico:\n");
            printf("Opcao 5: Voltar ao menu principal\n");
            scanf("%d", &op);
            while(op!=5)
            {
                switch(op)
                {
                case 1:
                {
                    char origem[4];
                    printf("Digite o aeroporto origem desejado:\n");
                    getchar();
                    fgets(origem,4, stdin);
                    for(int i=0; i<qt; i++)
                    {
                        if(strcmp(origem, point[i].origem) == 0 )
                        {
                            printf("Local de origem: %s\n", point[i].origem);
                            printf("Local de partida: %s\n", point[i].destino);
                            printf("Data de partida: %d/%d/%d\n", point[i].x[0].d, point[i].x[0].m, point[i].x[0].a);
                            printf("Data de partida: %d/%d/%d\n", point[i].x[1].d, point[i].x[1].m, point[i].x[1].a);
                        }
                        else
                        {
                            printf("Nao existe uma passagem com essas condicoes\n");
                        }
                    }
                    break;
                }
                case 2:
                {
                    char destino[4];
                    printf("Digite o aeroporto de destino desejado:\n");
                    getchar();
                    fgets(destino,4, stdin);
                    for(int i=0; i<qt; i++)
                    {
                        if(strcmp(destino, point[i].destino) == 0)
                        {
                            printf("Local de origem: %s\n", point[i].origem);
                            printf("Local de partida: %s\n", point[i].destino);
                            printf("Data de partida: %d/%d/%d\n", point[i].x[0].d, point[i].x[0].m, point[i].x[0].a);
                            printf("Data de partida: %d/%d/%d\n", point[i].x[1].d, point[i].x[1].m, point[i].x[1].a);
                        }
                        else
                        {
                            printf("Nao existe uma passagem com essas condicoes\n");
                        }
                    }
                    break;
                }
                case 3:
                {
                    int d, a, m;
                    printf("Digite a data de partida desejada:\n");
                    scanf("%d %d %d", &d, &m, &a);
                    for(int i=0; i<qt; i++)
                    {
                        if(d==point[i].x[0].d && m==point[i].x[0].m && a==point[i].x[0].a)
                        {
                            printf("Local de origem: %s\n", point[i].origem);
                            printf("Local de partida: %s\n", point[i].destino);
                            printf("Data de partida: %d/%d/%d\n", point[i].x[0].d, point[i].x[0].m, point[i].x[0].a);
                            printf("Data de partida: %d/%d/%d\n", point[i].x[1].d, point[i].x[1].m, point[i].x[1].a);
                        }

                    }
                    break;
                }
                case 4:
                {
                    float valor;
                    printf("Digite o valor maximo:\n");
                    scanf("%f", &valor);
                    for(int i=0; i<qt; i++)
                    {
                        if(point[i].valor<=valor)
                        {
                            printf("Local de origem: %s\n", point[i].origem);
                            printf("Local de partida: %s\n", point[i].destino);
                            printf("Data de partida: %d/%d/%d\n", point[i].x[0].d, point[i].x[0].m, point[i].x[0].a);
                            printf("Data de partida: %d/%d/%d\n", point[i].x[1].d, point[i].x[1].m, point[i].x[1].a);
                        }
                    }
                    break;
                }
                }
                printf("\nSub menu:\n");
                printf("Opcao 1: Por aeroporto de origem:\n");
                printf("Opcao 2: Por aeroporto de destino:\n");
                printf("Opcao 3: Por data de partida:\n");
                printf("Opcao 4: Por valor especifico:\n");
                printf("Opcao 5: Voltar ao menu principal\n");
                scanf("%d", &op);
            }
            break;
        }
        case 4:
        {
            FILE *info= fopen("informacoes.txt","w");
            if (info == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }
            for(int i=0; i<qt; i++)
            {
                fputs(point[i].destino, info);
                fputc('\n', info);
                fputs(point[i].origem, info);
                fprintf(info, "\n%d/%d/%d\n", point[i].x[0].d, point[i].x[0].m, point[i].x[0].a);
                fprintf(info, "%d/%d/%d\n", point[i].x[0].d, point[i].x[0].m, point[i].x[0].a);
            }
            fclose(info);
            break;
        }
        case 5:
        {
            FILE *info= fopen("informacoes.txt","r");
            if (info == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }
            char c;
            while((c=fgetc(info))!= EOF)
            {
                printf("%c", c);
            }

            fclose(info);
            break;
        }
        }
        printf("\nMenu:\n");
        printf("Opcao 0: Sair do programa:\n");
        printf("Opcao 1: Cadastro de passagem: \n");
        printf("Opcao 2: Imprimir passagem \n");
        printf("Opcao 3: Consultar passagem:\n");
        printf("Opcao 4: Exportar para arquivo:\n");
        printf("Opcao 5: Importar para arquivo:\n");
        scanf("%d", &op);
    }
    free(point);
    return 1;
}
