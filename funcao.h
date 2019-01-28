///**********************************************************************************    MUNICIPIO  |
Municipio* List_M(Municipio *MUNICIPIO);
void Add_Dados_M(char line[],Municipio *MUNICIPIO);


///**********************************************************************************    ZONA       |
Zona* List_Z(Zona *ZONA);
void Add_Dados_Z(char line[],Zona *ZONA);


///**********************************************************************************    SECAO      |
Secao* List_S(Secao *SECAO);
void Add_Dados_S(char line[],Secao *SECAO);


///**********************************************************************************    PARTIDO    |
PartidoColigacao* List_PC(PartidoColigacao *PARTIDOCOLIGACAO);
void Add_Dados_PC(char line[],PartidoColigacao *PARTIDOCOLIGACAO);


///**********************************************************************************    CANDIDATOS |
Candidatos* List_C(Candidatos *CANDIDATOS);
void Add_Dados_C(char line[],Candidatos *CANDIDATOS);


///**********************************************************************************    VOTOS   |
Votos* List_V(Votos *VOTOS);
void Add_Dados_V(char line[],Votos *VOTOS);
int VotosValidosMunicipio(Votos *VOTOS,int N_Municipio, char Cargo[]);
int VotosBrancosMunicipio(Votos *VOTOS,int N_Municipio, char Cargo[]);
int VotosNulosMunicipio(Votos *VOTOS,int N_Municipio, Zona *ZONA, Secao *SECAO, char Cargo[]);
int VotosPorCandidato(int N_Municipio,int N_Candidato,Votos *VOTOS);


///**********************************************************************************    FILTROS   |
void Lista_Candidatos_Municipio(Municipio *MUNICIPIO, Candidatos *CANDIDATOS);
void Contagem_Secoes_Eleitores(Votos *VOTOS, Municipio *MUNICIPIO, Secao *SECAO);
void Contagem_Votos_Municipio_Cargo(Votos *VOTOS, Municipio *MUNICIPIO, Zona *ZONA, Secao *SECAO);


///**********************************************************************************    APURACAO   |
int QuocienteEleitoralMunicipal(Municipio *MUNICIPIO, int N_Municipio,Votos *VOTOS);
int Calculo_Vagas_Partido(PartidoColigacao *PARTIDO, Votos *VOTOS, Candidatos * CANDIDATOS);
void PrefeitosEleitos_Municipio(Votos *VOTOS, Municipio *MUNICIPIO, Candidatos *CANDIDATOS);


///**********************************************************************************    UTEIS   |
void printM(Municipio* MUNICIPIO);
void printZ(Zona *ZONA);
void printS(Secao *SECAO);
void printPC(PartidoColigacao *PARTIDOCOLIGACAO);
void printC(Candidatos *CANDIDATOS);
void printV(Votos *VOTOS);
int VotosNulosTOTAL(Votos *VOTOS, Zona *ZONA, Secao *SECAO);
int VotosBrancosTOTAL(Votos *VOTOS);
int VotosPartidoColigacao(Votos *VOTOS, Municipio *MUNICIPIO, int N_Municipio, PartidoColigacao *PC, int N_Partido, Candidatos *CANDIDATOS);
void GeralVotosPorMunicipio(Municipio *MUNICIPIO, Votos *VOTOS);
void GeralVotosPorCandidato(Candidatos *CANDIDATOS,Votos *VOTOS, char Cargo[]);
void VotosPorPartido(Candidatos *CANDIDATOS,Votos *VOTOS,PartidoColigacao *PARTIDO);
