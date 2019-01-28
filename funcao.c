#include <stdio.h>
#include <stdlib.h>
#include <string.h>        /// JOSÉ MIGUEL DE ARAÚJO FILHO
#include "struct.h"

///*****************************************  MUNICIPIO  ***********************************************

Municipio* List_M(Municipio *MUNICIPIO)
{
    MUNICIPIO = malloc(sizeof(Municipio));          /// parte I e parte II foi feito ajustes e correções,
    MUNICIPIO->prox = NULL;
    return MUNICIPIO;                                ///REFERENCIA: CPLUS PLUS
}

void Add_Dados_M(char line[],Municipio *MUNICIPIO)
{
    Municipio *Novo = malloc(sizeof(Municipio));
    Municipio *aux = MUNICIPIO;

    char *token;
    token = strtok(line," ,;\n");
    while(token != NULL)
    {
        Novo->numeroMunicipio = atoi(token);
        token = strtok(NULL,",;\n");
        strcpy(Novo->nome,token);
        token = strtok(NULL," ,;\n");0
        Novo->vagas = atoi(token);
        token = strtok(NULL," ,;\n");
    }
    Novo->prox = aux->prox;
    aux->prox = Novo;
    }

///*****************************************  ZONA       ***********************************************

Zona* List_Z(Zona *ZONA)
{
    ZONA = malloc(sizeof(Zona));
    ZONA->prox = NULL;
    return ZONA;
}

void Add_Dados_Z(char line[],Zona *ZONA)
{
    Zona *Novo = malloc(sizeof(Zona));
    Zona *aux = ZONA;

    char *token;
    token = strtok(line," ,;\n");
    while(token != NULL)
    {
        Novo->numeroZona = atoi(token);
        token = strtok(NULL,",;\n");
        strcpy(Novo->local,token);
        token = strtok(NULL," ,;\n");
    }
    Novo->prox = aux->prox;
    aux->prox = Novo;
}

///*****************************************  SECAO       ***********************************************

Secao* List_S(Secao *SECAO)
{
    SECAO = malloc(sizeof(Secao));
    SECAO->prox = NULL;
    return SECAO;
}

void Add_Dados_S(char line[],Secao *SECAO)
{
    Secao *Novo = malloc(sizeof(Secao));
    Secao *aux = SECAO;

    char *token;
    token = strtok(line," ,;\n");
    while(token != NULL)
    {
        Novo->numeroZona = atoi(token);
        token = strtok(NULL," ,;\n");
        Novo->numeroSecao = atoi(token);
        token = strtok(NULL," ,;\n");
        Novo->numeroMunicipio = atoi(token);
        token = strtok(NULL,",;\n");
        strcpy(Novo->local,token);
        token = strtok(NULL," ,;\n");
        Novo->eleitores = atoi(token);
        token = strtok(NULL," ,;\n");
    }
    Novo->prox = aux->prox;
    aux->prox = Novo;
}

///*****************************************  PARTIDO       ***********************************************

PartidoColigacao* List_PC(PartidoColigacao *PARTIDO)
{
    PARTIDO = malloc(sizeof(PartidoColigacao));
    PARTIDO->prox = NULL;
    return PARTIDO;
}

void Add_Dados_PC(char line[],PartidoColigacao *PARTIDO)
{
    PartidoColigacao *Novo = malloc(sizeof(PartidoColigacao));
    PartidoColigacao *aux = PARTIDO;

    char *token;
    token = strtok(line," ,;\n");
    while(token != NULL)
    {
        Novo->numeroPartido = atoi(token);
        token = strtok(NULL,",;\n");
        strcpy(Novo->Partido,token);
        token = strtok(NULL," ,;\n");
        Novo->Coligacao = atoi(token);
        token = strtok(NULL," ,;\n");
    }
    Novo->prox = aux->prox;
    aux->prox = Novo;
}

///*****************************************  CANDIDATOS       ***********************************************

Candidatos* List_C(Candidatos *CANDIDATOS)
{
    CANDIDATOS = malloc(sizeof(Candidatos));
    CANDIDATOS->prox = NULL;
    return CANDIDATOS;
}

void Add_Dados_C(char line[],Candidatos *CANDIDATOS)
{
    Candidatos *Novo = malloc(sizeof(Candidatos));
    Candidatos *aux = CANDIDATOS;

    char *token;
    token = strtok(line," ,;\n");
    while(token != NULL)
    {
        Novo->numeroCandidato = atoi(token);
        token = strtok(NULL,",;\n");
        strcpy(Novo->nome,token);
        token = strtok(NULL,",;\n");
        strcpy(Novo->cargoEletivo,token);
        token = strtok(NULL,",;\n");
        strcpy(Novo->Partido,token);
        token = strtok(NULL," ,;\n");
        Novo->numeroMunicipio = atoi(token);
        token = strtok(NULL," ,;\n");
    }
    Novo->prox = aux->prox;
    aux->prox = Novo;
}

///*****************************************  VOTOS       ***********************************************

Votos* List_V(Votos *VOTOS)
{
    VOTOS = malloc(sizeof(Votos));
    VOTOS->prox = NULL;
    return VOTOS;
}

void Add_Dados_V(char line[],Votos *VOTOS)
{
    Votos *Novo = malloc(sizeof(Votos));
    Votos *aux = VOTOS;
    /// A insercao no fim da lista tarna o trabalho demorado por conta grande quantidade de dados e isto nao e viavel.
   // for(aux = VOTOS; aux->prox != NULL; aux = aux->prox);

    char *token;
    token = strtok(line," ,;\n");
    while(token != NULL)
    {
        Novo->numeroCandidato = atoi(token);
        token = strtok(NULL," ,;\n");
        Novo->numeroZona = atoi(token);
        token = strtok(NULL," ,;\n");
        Novo->numeroSecao = atoi(token);
        token = strtok(NULL," ,;\n");
        Novo->numeroMunicipio = atoi(token);
        token = strtok(NULL,",;\n");
        strcpy(Novo->cargoEletivo,token);
        token = strtok(NULL," ,;\n");
    }

    Novo->prox = aux->prox;
    aux->prox = Novo;
}

/// Retorna o número de VOTOS VALIDOS de um municipio de extrama importacia para a apuração
int VotosValidosMunicipio(Votos *VOTOS, int N_Municipio, char Cargo[])
{
    int V_Municipio = 0;
    Votos *aux;
    for(aux = VOTOS; aux != NULL; aux = aux->prox)
        if(aux->numeroMunicipio == N_Municipio)
            V_Municipio++;

    return V_Municipio;
}

/// Retorna o número de VOTOS BRANCOS de um municipio de extrama importacia para a apuração
int VotosBrancosMunicipio(Votos *VOTOS, int N_Municipio, char Cargo[])
{
    int V_Brancos = 0;
    Votos *aux;

    for(aux = VOTOS; aux != NULL; aux = aux->prox)
        if(N_Municipio == aux->numeroMunicipio && aux->numeroCandidato == -1 && !strcmp(aux->cargoEletivo,Cargo))
            V_Brancos++;

    return V_Brancos;
}

/// Retorna o número de VOTOS NULOS de um municipio de extrama importacia para a apuração
int VotosNulosMunicipio(Votos *VOTOS, int N_Municipio, Zona *ZONA, Secao *SECAO, char Cargo[])
{
    int V_Nulos = 0;
    int key = 0;
    int key2 = 0;
    Votos *aux;
    Zona  *aux2;
    Secao *aux3;

    for(aux = VOTOS; aux != NULL; aux = aux->prox)
    {
        if(aux->numeroMunicipio == N_Municipio && !strcmp(aux->cargoEletivo,Cargo) && aux->numeroCandidato != -1)
        {
            for(aux2 = ZONA; aux2 != NULL; aux2 = aux2->prox)
            {
                if(aux->numeroZona == aux2->numeroZona)
                {
                    key2 = 1;
                    for(aux3 = SECAO; aux3 != NULL; aux3 = aux3->prox)
                    {
                        if(aux->numeroSecao == aux3->numeroSecao)
                        {
                            key = 1;
                            break;
                        }
                    }
                        if(key == 1);
                        else
                        {
                            V_Nulos++;
                        }
                            key = 0;

                }
            }
                if(key2 == 1);
                else
                {
                V_Nulos++;
                }
                key2 = 0;
        }
    }

    return V_Nulos;
}

/// Retorna os votos por candido de um municipio no cargo PREFEITO de extrama importacia para a apuração
int VotosPorCandidato(int N_Municipio,int N_Candidato,Votos *VOTOS)
{
    int V_Candidato = 0;
    Votos *aux2;

                for(aux2 = VOTOS; aux2 != NULL; aux2 = aux2->prox)
                {
                    if(strcmp(aux2->cargoEletivo," PREFEITO") == 0 && aux2->numeroCandidato == N_Candidato &&
                       aux2->numeroMunicipio == N_Municipio)
                        V_Candidato++;
                }

    return V_Candidato;
}
///*****************************************  FILTROS       ***********************************************

///[ 1 ] Listagem de Candidatos Por Municipio

void Lista_Candidatos_Municipio(Municipio *MUNICIPIO, Candidatos *CANDIDATOS)
{
    Municipio *aux;
    Candidatos *aux2;
    char BM[50],BCarg[50];
    char BuscaM[50] = " ";
    char BuscaCarg[50] = " ";

    printf("Ex'Aracati' MUNICIPIO    : ");gets(BM);
    printf("Ex'PREFEITO'CARGO ELETIVO: ");gets(BCarg);
    strcat(BuscaM,BM);
    strcat(BuscaCarg,BCarg);

    for(aux = MUNICIPIO; aux != NULL; aux = aux->prox)
    {
        if(!strcmp(aux->nome,BuscaM))
        {
            for(aux2 = CANDIDATOS; aux2 != NULL; aux2 = aux2->prox)
                if(aux->numeroMunicipio == aux2->numeroMunicipio && !strcmp(aux2->cargoEletivo,BuscaCarg))
                    printf("Canditado(a): %d, %s, %s\n",aux2->numeroCandidato,aux2->nome,aux2->Partido);
        }
    }
        getchar();
        system("clear || cls");
}

///[ 2 ] Contagem de Secoes Por Municipio - DONE

void Contagem_Secoes_Eleitores(Votos *VOTOS, Municipio *MUNICIPIO, Secao *SECAO)
{
    int secoes = 0;
    int votos = 0;

    Municipio *aux;
    Secao *aux2;
    Votos *aux3;

    for(aux = MUNICIPIO; aux != NULL; aux = aux->prox)
    {
        for(aux2 = SECAO; aux2 != NULL; aux2 = aux2->prox)
        {
            if(aux->numeroMunicipio == aux2->numeroMunicipio)
                secoes++;
        }

        for(aux3 = VOTOS; aux3 != NULL; aux3 = aux3->prox)
        {
            if(aux->numeroMunicipio == aux3->numeroMunicipio)
                votos++;
        }

        printf("MUNICIPIO: %s, SECOES: %d,\nELEITORES: %d\n\n",aux->nome,secoes,votos);
        secoes = 0;
        votos = 0;
    }
        getchar();
        system("clear || cls");
}

///[ 3 ] Contagem de Votos Validos, nulos e brancos Por Municipio

void Contagem_Votos_Municipio_Cargo(Votos *VOTOS, Municipio *MUNICIPIO, Zona *ZONA, Secao *SECAO)
{
    Municipio *aux;
    Zona *aux2;
    Secao *aux3;
    int V_Validos = 0;
    int V_Brancos = 0;
    int V_Nulos = 0;
    int N_ZONA = 0;
    int N_SECAO = 0;
    char BM[50],BCarg[50];
    char BuscaM[50] = " ";
    char BuscaCarg[50] = " ";

    printf("Ex'Aracati' MUNICIPIO    : ");gets(BM);
    printf("Ex'PREFEITO'CARGO ELETIVO: ");gets(BCarg);
    strcat(BuscaM,BM);
    strcat(BuscaCarg,BCarg);

        for(aux = MUNICIPIO; aux != NULL; aux = aux->prox)
        {

            if(!strcmp(aux->nome,BuscaM))
            {

               V_Validos = VotosValidosMunicipio(VOTOS,aux->numeroMunicipio,BuscaCarg);
               V_Brancos = VotosBrancosMunicipio(VOTOS,aux->numeroMunicipio,BuscaCarg);
               V_Nulos   = VotosNulosMunicipio(VOTOS,aux->numeroMunicipio,ZONA,SECAO,BuscaCarg);

                for(aux2 = ZONA; aux2 != NULL; aux2 = aux2->prox)
                    {
                        if(!strcmp(aux2->local,BuscaM))
                        {
                            N_ZONA = aux2->numeroZona;
                        }
                    }

                 for(aux3 = SECAO; aux3 != NULL; aux3 = aux3->prox)
                    {
                        if(aux->numeroMunicipio == aux3->numeroMunicipio)
                        N_SECAO++;
                    }

            }
        }
        printf("ZONA: %d, SECAO: %d, ELEITORES: %d,\nVOTOS: %d, BRANCOS: %d, NULOS: %d",N_ZONA ,N_SECAO,(V_Validos+V_Brancos+V_Nulos),V_Validos,V_Brancos,V_Nulos);
        getchar();
        system("clear || cls");
}


///*****************************************  APURACAO       ***********************************************
/*Calculo do Quociente Eleitoral para ver se o municipio atinge o QE e poderar ter cadeiras
para vereadores de seus partidos de cada municipio */
int QuocienteEleitoralMunicipal(Municipio *MUNICIPIO, int N_Municipio,Votos *VOTOS)
{
    float QEM;
    Municipio *aux;

    for(aux = MUNICIPIO; aux != NULL; aux = aux->prox)
        if(aux->numeroMunicipio == N_Municipio)
            QEM = VotosValidosMunicipio(VOTOS,N_Municipio," VEREADOR")/ aux->vagas;

    return QEM;
}

/*Seria Utilizado para calcular o Quociente Eleitoral para ver quais partidos por municipio atigem o QE */
int VotosPartidoColigacao(Votos *VOTOS, Municipio *MUNICIPIO, int N_Municipio, PartidoColigacao *PC, int N_Partido, Candidatos *CANDIDATOS)
{
    int V_partido;
    Votos *aux;
    Candidatos *aux2;
    PartidoColigacao *aux3;

        for(aux = VOTOS; aux != NULL; aux = aux->prox)
        {
            if(aux->numeroCandidato != -1)
            {
                for(aux2 = CANDIDATOS; aux2 != NULL; aux2 = aux2->prox)
                    if(!strcpy(aux2->cargoEletivo," VEREADOR"))
                    {
                        for(aux3 = PC; aux3 != NULL; aux3 = aux3->prox)
                            if(N_Partido == aux3->numeroPartido)
                                V_partido++;
                    }

            }
        }

return V_partido;
}

/*Apuração de Prefeitos por Voto Siples visto que pois a maioria absoluta nunca é atiginda nesta apuração
por conta disto o código funciona perfeitamente faltando calcular o caso de segundo turno.  */
void PrefeitosEleitos_Municipio(Votos *VOTOS, Municipio *MUNICIPIO, Candidatos *CANDIDATOS)
{
        int Vencendo = 0;
        int Prox = 0;
        Municipio *aux;
        Candidatos *aux2;
        Candidatos *Eleito;


        for(aux = MUNICIPIO; aux != NULL; aux = aux->prox)
        {

            if(VotosValidosMunicipio(VOTOS,aux->numeroMunicipio," PREFEITO") < 200000)
            {

                for(aux2 = CANDIDATOS; aux2 != NULL; aux2 = aux2->prox)
                {
                    if(aux->numeroMunicipio == aux2->numeroMunicipio && !strcmp(aux2->cargoEletivo," PREFEITO"))
                    {
                        Prox = VotosPorCandidato(aux2->numeroCandidato,aux2->numeroMunicipio,VOTOS);
                        if(Prox < Vencendo);
                            else
                            {
                                Vencendo = Prox;
                                Eleito = aux2;
                            }
                    }
                }
                Vencendo = 0;

            printf("Municipio: %s \nPREFEITO ELEITO:  %d, %s, %s\n\n"
                                                                ,aux->nome
                                                                ,Eleito->numeroCandidato
                                                                ,Eleito->nome
                                                                ,Eleito->Partido);

            /// Teste para constar que o Prefeito existe no Municipio Apurado;
            ///Lista_Candidatos_Municipio(MUNICIPIO,CANDIDATOS);
            ///puts("");
            }
        }
        getchar();
        system("clear || cls");
}

///*****************************************  UTEIS       ***********************************************


/// Testes para ver se os dados estam sendo armazenados nas structs corretamente
void printM(Municipio* MUNICIPIO)
{
    Municipio *aux;
    for(aux = MUNICIPIO; aux != NULL; aux = aux->prox)
    printf("teste |M|%d,%s,%d;\n",aux->numeroMunicipio
                                    ,aux->nome
                                    ,aux->vagas);
}


void printZ(Zona *ZONA)
{
    Zona *aux;
    for(aux = ZONA; aux != NULL; aux = aux->prox)
    printf("teste |Z| %d, %s;\n",aux->numeroZona
                                ,aux->local);
}

void printS(Secao *SECAO)
{
    Secao *aux;
    for(aux = SECAO; aux != NULL; aux = aux->prox)
    printf("teste |S| %d, %d, %d, %s, %d;\n",aux->numeroZona
                                            ,aux->numeroSecao
                                            ,aux->numeroMunicipio
                                            ,aux->local
                                            ,aux->eleitores);
}

void printC(Candidatos *CANDIDATOS)
{
    Candidatos *aux;
    for(aux = CANDIDATOS; aux != NULL; aux = aux->prox)
    printf("teste |C| %d, %s, %s, %s, %d;\n",aux->numeroCandidato
                                            ,aux->nome
                                            ,aux->cargoEletivo
                                            ,aux->Partido
                                            ,aux->numeroMunicipio);
}

void printPC(PartidoColigacao *PARTIDO)
{
    PartidoColigacao *aux;
    for(aux = PARTIDO; aux != NULL; aux = aux->prox)
    printf("teste |PC| %d, %s, %d;\n",aux->numeroPartido
                                     ,aux->Partido
                                     ,aux->Coligacao);
}

void printV(Votos *VOTOS)
{
    Votos *aux;
    for(aux = VOTOS; aux != NULL; aux = aux->prox)
    printf("teste |V| %d, %d, %d, %d, %s;\n",aux->numeroCandidato
                                            ,aux->numeroZona
                                            ,aux->numeroSecao
                                            ,aux->numeroMunicipio
                                            ,aux->cargoEletivo);
}

/// teste ....

/// Votos por partido em GERAL
void VotosPorPartido(Candidatos *CANDIDATOS,Votos *VOTOS, PartidoColigacao *PARTIDO)
{
    int V_Candidato = 0;
    int V_Partido = 0;
    Candidatos *aux;
    Votos *aux2;
    PartidoColigacao *aux3;

        for(aux3 = PARTIDO; aux3 != NULL; aux3 = aux3->prox)
        {
            for(aux = CANDIDATOS; aux != NULL; aux = aux->prox)
            {
                if(!strcmp(aux->Partido,aux3->Partido))
                for(aux2 = VOTOS; aux2 != NULL; aux2 = aux2->prox)
                    if(aux2->numeroCandidato == aux3->numeroPartido)
                    V_Partido++;
                    else if(aux->numeroCandidato == aux2->numeroCandidato)
                        V_Candidato++;

            }
                printf("Partido : %d, %s, %d, Votos : %d\n",aux3->numeroPartido
                                                             ,aux3->Partido
                                                             ,aux3->Coligacao
                                                             ,V_Candidato + V_Partido);
                                                              V_Candidato = 0;
                                                              V_Partido = 0;
        }
}
/// Retorna todos os votos brancos
int VotosBrancosTOTAL(Votos *VOTOS)
{
    int V_Brancos = 0;
    Votos *aux;
    for(aux = VOTOS; aux != NULL; aux = aux->prox)
        if(aux->numeroCandidato == -1)
            V_Brancos++;

    return V_Brancos;
}

/// Retorna todos os votos nulos
int VotosNulosTOTAL(Votos *VOTOS, Zona *ZONA, Secao *SECAO)
{
    int V_Nulos = 0;
    int key = 0;
    int key2 = 0;
    Votos *aux;
    Zona  *aux2;
    Secao *aux3;

    for(aux = VOTOS; aux != NULL; aux = aux->prox)
    {
        if(aux->numeroCandidato != -1)
        {
            for(aux2 = ZONA; aux2 != NULL; aux2 = aux2->prox)
            {
                if(aux->numeroZona == aux2->numeroZona)
                {
                    key2 = 1;
                    for(aux3 = SECAO; aux3 != NULL; aux3 = aux3->prox)
                    {
                        if(aux->numeroSecao == aux3->numeroSecao)
                        {
                            key = 1;
                            break;
                        }
                    }
                        if(key == 1);
                        else
                        {
                            V_Nulos++;
                        }
                            key = 0;

                }
            }
                if(key2 == 1);
                else
                {
                V_Nulos++;
                }
                key2 = 0;
        }
    }

    return V_Nulos;
}


/// Votos Válidos por cada municipio
void GeralVotosPorMunicipio(Municipio *MUNICIPIO, Votos *VOTOS)
{
    puts("\n\nVotos Validos Por MUNICIPIO");
            int i = 1;
        while(i <= 20)
        {
            Municipio *aux;
            for(aux = MUNICIPIO; aux != NULL; aux = aux->prox)
                if(aux->numeroMunicipio == i)
                break;
           // printf("Total de Votos do Municipio de | %s |: %d\n",aux->nome,VotosValidosMunicipio(i++,VOTOS));
        }
}

///VOTOS POR CANDIDATO EM GERAL - Imprime os votos de cada candidato independente do municipio
void GeralVotosPorCandidato(Candidatos *CANDIDATOS,Votos *VOTOS, char Cargo[])
{
    int V_Candidato = 0;
    Candidatos *aux;
    Votos *aux2;
            for(aux = CANDIDATOS; aux != NULL; aux = aux->prox)
            {
                for(aux2 = VOTOS; aux2 != NULL; aux2 = aux2->prox)
                {
                    if(!strcmp(aux2->cargoEletivo,Cargo) && aux->numeroCandidato == aux2->numeroCandidato)
                    V_Candidato++;
                }
                     if(!strcmp(aux->cargoEletivo,Cargo))
                            printf("Candidato(a): %d, %s, %s, Votos : %d\n",aux->numeroCandidato
                                                                         ,aux->nome
                                                                         ,aux->cargoEletivo
                                                                         ,V_Candidato);
                            V_Candidato = 0;


            }
}


