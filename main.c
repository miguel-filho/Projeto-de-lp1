#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "funcao.h"

int main()
{
    FILE *file;
    char line[256];
    int menu = 0;
    Municipio *MUNICIPIO;
    Zona *ZONA;
    Secao *SECAO;
    PartidoColigacao *PARTIDO;
    Candidatos *CANDIDATOS;
    Votos *VOTOS;

    ///Inicializando Listas;
    MUNICIPIO  = List_M(MUNICIPIO);
    ZONA       = List_Z(ZONA);
    SECAO      = List_S(SECAO);
    PARTIDO    = List_PC(PARTIDO);
    CANDIDATOS = List_C(CANDIDATOS);
    VOTOS      = List_V(VOTOS);

    if((file = fopen("apuracao.txt","r"))!= NULL)
        while(!feof(file))
        {
            fgets(line,256,file);
            if(!strcmp("*municipio*\n",line))
            {
                while(1)
                {
                    fgets(line,256,file);
                    if(!strcmp("\n",line))break;
                    Add_Dados_M(line,MUNICIPIO);
                }
            }
            else if(!strcmp("*zona*\n",line))
            {
                while(1)
                {
                    fgets(line,256,file);
                    if(!strcmp("\n",line))break;
                    Add_Dados_Z(line,ZONA);
                }
            }
            else if(!strcmp("*secao*\n",line))
            {
                while(1)
                {
                    fgets(line,256,file);
                    if(!strcmp("\n",line))break;
                    Add_Dados_S(line,SECAO);
                }
            }
            else if(!strcmp("*partido*\n",line))
            {
                while(1)
                {
                    fgets(line,256,file);
                    if(!strcmp("\n",line))break;
                    Add_Dados_PC(line,PARTIDO);
                }
            }
            else if(!strcmp("*candidatos*\n",line))
            {
                while(1)
                {
                    fgets(line,256,file);
                    if(!strcmp("\n",line))break;
                    Add_Dados_C(line,CANDIDATOS);
                }
            }
            else if(!strcmp("*votos*\n",line))
            {
                while(1)
                {
                    fgets(line,256,file);
                    if(!strcmp("\n",line))break;
                    Add_Dados_V(line,VOTOS);
                }
            }
        }
    else puts("Arquivo nao encontrado!");
    fclose(file);

    do
    {
        printf("Sair..........................................................[ 0 ]\n");
        printf("Lista de Candidatos por Municipio.............................[ 1 ]\n");
        printf("Contagem de Secoes e eleitores por Municipio..................[ 2 ]\n");
        printf("Contagem de Votos Validos/Brancos/Nulos por Municipio e Cargo.[ 3 ]\n");
        printf("Apuracao de Prefeitos Eleitos por Municipio...................[ 4 ]\n");
        printf("Digite: ");
        scanf("%d",&menu);
        getchar();
        switch(menu)
        {
        case 0 :
            break;
        case 1 :
            Lista_Candidatos_Municipio(MUNICIPIO->prox,CANDIDATOS->prox);
            break;
        case 2 :
            Contagem_Secoes_Eleitores(VOTOS->prox,MUNICIPIO->prox,SECAO->prox);
            break;
        case 3 :
            Contagem_Votos_Municipio_Cargo(VOTOS->prox,MUNICIPIO->prox,ZONA->prox,SECAO->prox);
            break;
        case 4 :
            PrefeitosEleitos_Municipio(VOTOS->prox,MUNICIPIO->prox,CANDIDATOS->prox);
            break;
        default:
            puts("Valor invalido!");
            getchar();
            getchar();
            system("clear || cls");
            /// Todos os getchar e system sao utilizados para finalidades do menu nao interferem no codigo
        }
    }
    while(menu);


/// DEMAIS TESTES ABAIXO

    /// Verificacao dos dados extraidos
    ///printM(MUNICIPIO->prox);
    ///printZ(ZONA->prox);
    ///printS(SECAO->prox);
    ///printC(CANDIDATOS->prox);
    ///printPC(PARTIDO->prox);
    ///printV(VOTOS->prox);

    /// Testes
    ///VotosPorPartido(CANDIDATOS->prox,VOTOS->prox,PARTIDO->prox);
    ///printf("Total de Votos Na Eleicao Brancos: %d\n",VotosBrancosTOTAL(VOTOS->prox));
    ///printf("Total de Votos Na Eleicao Nulos: %d\n",VotosNulosTOTAL(VOTOS->prox,ZONA->prox,SECAO->prox));
    ///printf("Votos Validos por Municipio VEREADOR: %d\n",VotosValidosMunicipio(VOTOS->prox,2," VEREADOR"));
    ///printf("Votos Validos por Municipio PREFEITO: %d\n",VotosValidosMunicipio(VOTOS->prox,2," PREFEITO"));
    ///printf("Votos Brancos por Municipio VEREADOR: %d\n",VotosBrancosMunicipio(VOTOS->prox,2," VEREADOR"));
    ///printf("Votos Brancos por Municipio PREFEITO: %d\n",VotosBrancosMunicipio(VOTOS->prox,2," PREFEITO"));
    ///printf("Votos Nulos por Municipio VEREADOR: %d\n",VotosNulosMunicipio(VOTOS->prox,2,ZONA->prox,SECAO->prox," VEREADOR"));
    ///printf("Votos Nulos por Municipio PREFEITO: %d\n",VotosNulosMunicipio(VOTOS->prox,2,ZONA->prox,SECAO->prox," PREFEITO"));

    return 0;
}
