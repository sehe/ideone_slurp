// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-23 20:52:37
// status:	0
// result:	15
// memory:	2064
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int conta(char c, char *s){
    int num_vezes=0;
    while(*s!='\0'){
        if(*s== '\t'){
            num_vezes++;
        }
        s++;
    }
    return num_vezes;
}

int ordenar(int vetorDeNumeros[], int tamanhoVetor){
    int i;
    int j;
    int temp;
    for(i=0;i<tamanhoVetor;i++){
        for(j=0;j<tamanhoVetor;j++){
            if(vetorDeNumeros[i] < vetorDeNumeros[j]){
                temp = vetorDeNumeros[i];
                vetorDeNumeros[i] = vetorDeNumeros[j];
                vetorDeNumeros[j] = temp;
            }
        }
    }

    return vetorDeNumeros[0];
}

void clean(char * s){
     int i=0;
     while(s[i]!='\0'){
          if(s[i]=='\n'){
             s[i]='\0';
          }
          i++;
     }
}

void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

void cleanequal(char * s){
     int i=0;
     while(s[i]!='\0'){
          if(s[i]== '='){
             s[i]=' ';
          }
          i++;
     }
}

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

char* expand_cell_references(const char* f, const char* const l, char* o); /*the magic engine*/
const char* get_cell_value(const char* coordinate_b, const char* coordinate_e);

//localiza pelo numero maximo de coisas que ele vai ler
static char matris[30][26][302] = {{{0}}};

int main() {
    //int tamanho = 0;
    char vetor[302];
    int m;
    int k=0;
    int colunas = 0;
    int vetorDeNumeros[30] = {0};
    //inicia-se o loop
    while(1) {
        if(
                !fgets(vetor, 302, stdin) //Recebe os dados
                || strcmp(vetor, "\n") == 0) //Verifica se tem a quebra de linha
        {
            break;
        }
        //Aqui eu insiro na funcao o vetor
        char *s = vetor;
        //Recebo a quantia de \t
        m = conta('\t', s);
        //Passo pra posicao do vetor, o numero de colunas
        vetorDeNumeros[k] = m+1;
        //Recebo o resultado do bubble sort
        colunas = ordenar(vetorDeNumeros, k+1);
        //faz a colocacao de cada elemento dentro de cada celula, tentei por funcao mas nao deu muito certo
        char *ponteiro;
        int j=0;
        while(j<colunas) {
            ponteiro = strtok(vetor, "\t");
            while(ponteiro != NULL) {
                strcpy(matris[k][j], ponteiro);
                ponteiro = strtok(NULL, "\t");
                //REMOVE OS \N DESNECESSARIOS
                clean(matris[k][j]);
                //REMOVE OS IGUAIS
                cleanequal((matris[k][j]));
                //REMOVE OS ESPAÇOS GERADOS PELOS ESPAÇOS
                RemoveSpaces(matris[k][j]);
                j++;
            }
        }
        //Quantia de linhas que foram
        k++;
    }
    //int L = 0, linha=0;
    //char col;
    int i, c;
    for(i = 0; i < k; i++) {
        for(c = 0; c < colunas; c++) {
            //printf("linha: %d coluna: %c >> |%s|", i, c, matris[i][c]);
            //int line;
            //int offset = 0, readCharCount;
            //char op;
            //char troca[301];
            //char buffer[32];
            char out[1024] = {0};
            const char* value = matris[i][c];
            expand_cell_references(value, value+strlen(value), out);
            printf("%s\t", out); /* Should be fine, really, as long as input fits inside matris */
            // printf("%s\t", matris[i][c]);
        }
        printf("\n");
    }
    /*
        printf("%d lin, %d col\n\n", k, colunas);
        int w,z;
        for(w=0;w<k;w++){
            for(z=0;z<colunas;z++){
                printf("%s\t", matris[w][z]);

            }
            printf("\n");
        }
    */
    printf("\n");
//system("pause");
    return 0;
}

const char* get_cell_value(const char* coordinate_b, const char* coordinate_e)
{
#ifdef DEBUG
    static const size_t maxrows = (sizeof(matris)/sizeof(*matris));
    static const size_t maxcols = (sizeof(matris[0])/sizeof(*matris[0]));
#endif
    size_t col = 0, row = 0;
    const char* it;
    for (it=coordinate_b; it != coordinate_e; ++it)
    {
        if (*it >= 'A' && *it <= 'Z')
            col = 26*col + (*it - 'A');
        if (*it >= '0' && *it <= '9')
            row = 10*row + (*it - '0'); /* or use atoi and friends */
    }
    row--; /* 1-based row nums in Excel */

#ifdef DEBUG
    assert(col>=0 && col < maxcols);
    assert(row>=0 && row < maxrows);
#endif

    return matris[row][col]; /* 1-based indexes in Excel */
}

char* expand_cell_references(const char* f, const char* const l, char* o)
{
    enum parser_state {
        other,
        in_coord_col,
        in_coord_row
    } state = other;

    /*temporary storage for coordinates being parsed:*/
    char accum[16] = {0};
    char* accit = accum;
    while (f!=l)
    {
        switch(state) /*dummy, the transitions flow in fallthrough order for now*/
        {
            case other:
                *(accit = accum) = 0; /*reset the accumulator*/
                while (f!=l && !(*f>='A' && *f<='Z'))
                    *o++ = *f++;
                /*fallthrough*/
            case in_coord_col:
                while (f!=l && *f>='A' && *f<='Z')
                    *accit++ = *f++;
                /*fallthrough*/
            case in_coord_row:
                {
                    const char* expanded = accum;
                    if (f!=l && *f>='0' && *f<='9')
                    {
                        while (f!=l && *f>='0' && *f<='9')
                            *accit++ = *f++;
                        expanded = get_cell_value(accum, accit);
                    }
                    else
                    {
                        *accit = 0;
                    }
                    while (*expanded)
                        *o++ = *expanded++;
                    continue; /*state = other;*/
                }
        }
    }
    return o;
}

// ------------------------------------------------
#if 0 // stdin
1	2	3
A1	B1	C1

#endif
#if 0 // stdout
1	2	3	
1	2	3	


#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
