/**< Structs */

typedef struct municipio
{
    int numeroMunicipio;
    char nome[50];
    int vagas;
    struct municipio *prox;
}Municipio;

typedef struct zona
{

    int numeroZona;
    char local[200];
    struct zona *prox;
}Zona;


typedef struct secao
{

    int numeroZona;
    int numeroSecao;
    int numeroMunicipio;
    char local[100];
    int eleitores;
    struct secao *prox;
} Secao;

typedef struct partidocoligacao
{
    int numeroPartido;
    char Partido[20];
    int Coligacao;
    struct partidocoligacao  *prox;
}PartidoColigacao;

typedef struct candidatos
{
    int numeroCandidato;
    char nome[200];
    char cargoEletivo[20];
    char Partido[20];
    int numeroMunicipio;
    struct candidatos *prox;
}Candidatos;

typedef struct votos
{
    int numeroCandidato;
    int numeroZona;
    int numeroSecao;
    int numeroMunicipio;
    char cargoEletivo[20];
    struct votos *prox;
}Votos;
