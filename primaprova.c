#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*frase, grandezza, array*/
void creaArr(char*,int,int*);
void creaArr(char* frase, int n, int *arr){
    int cont = 0;
    while(cont != n){
        char c = frase[cont];
        if(c == ' '){
            arr[cont] = 0;
            cont++;
            continue;
        }
        int frequenza = 0;
        //conto la frequenza del carattere c
        for(int i = 0; i < n; i++){
            if(frase[i] == c){
                frequenza++;
            }
        }
        arr[cont] = frequenza;
        cont++;
    }
    return;
}

/*frase, array, grandezza, soluzione*/
void crypt(char*,int*, int,char*);
void crypt(char* frase, int* arr, int size, char* sol){
    printf("\n\n--- crypt ---\n\n");
    //se scorro la frase devo eliminare le lettere che sostituisco altrimenti 
    //si invertono a numeri pari e tornano come erano all'inizio eheh
    int contatore = 0;
    char carattere;
    int frequenza = 0;
    int i = 0;
    while(contatore < size/2 + 1){
        printf("\n--crypt-- carattere num = %d",contatore);
        if(frase[contatore] == ' '){
            contatore++;
            continue;
        }
        carattere = frase[contatore];
        frequenza = arr[contatore];
        printf("\n--crypt-- char = %c freq= %d",carattere,frequenza);

        //partendo dal fondo scorro le posizioni i
        for(i = size-1; 0 <= i; i--){ //to remove il -1
            
            //se non trovo altri con stessa frequenza prima di contatore allora continuo
            //scherzavo.. non funziona
            if(contatore == i){
                contatore++;
                i = 0;
            }
            
            //se il carattere ha la stessa frequenza ed è diverso da se stesso o " " allora:
            //li sostituisco ed tolgo i caratteri altrimenti continuo a scorrere frase;
            if(arr[i]==frequenza && frase[i]!=carattere && frase[i]!=' '){
                printf("\nfrase = %s",frase);
                printf("\nsol = %s",sol);
                trapianta(sol, size, carattere, frase[i]);
                elimina(frase,arr,size,carattere,frase[i]);
                printf("\n--diventano--");
                printf("\nfrase = %s",frase);
                printf("\nsol = %s",sol);
                contatore++;
                i = 0; //or break ?
            }
        }
    }
}

/* frase, ada , grandezza, char 1 e char 2 da togliere*/
void elimina(char*,int*, int, char,char);
void elimina(char* stringa,int* arr, int size, char tc, char sost){
    printf("\nelimina - tc = %c\te\tsost = %c",tc,sost);
    //scorro la stringa e ogni volta che trovo il carattere, in quella posizione 
    //metto ' ' e frequenza 0
    int i = 0;
    for(i = 0; i < size; i++){
        if(stringa[i] == tc || stringa[i] == sost){
            stringa[i] = ' ';
            arr[i] = 0;
        }
    }
}

/* soluzione, grandezza, char 1, char 2*/
void trapianta(char*,int, char,char);
void trapianta(char* stringa,int n, char tc, char sost){
    printf("\ntransplant - tc = %c\tsost = %c",tc,sost);
    //per tutta la lunghezza della stringa
    for(int i = 0; i < n; i++){
        //se trovo il primo carattere lo cambio col secondo
        if(stringa[i] == tc){
            stringa[i] = sost;
        }else
        {   //e se trovo il secondo lo cambio con il primo
            if(stringa[i] == sost){
            stringa[i] = tc;
            }
        }
        
    }
}


int main(void){
    //creo le variabili
    int size;
    char *frase;
    int *ada = NULL;
    char *soluzione;
    printf("\nsize = %d",size);
    printf("\ninserire la frase da criptare: ");
    scanf ("%[^\n]%*c", frase); //prova se funziona sennò quello sotto
    //scanf("%s",frase); 
    printf("\nla frase da criptare: %s",frase);
    //alloco gli array di char
    size = strlen(frase);
    printf("\nsize = %d",size);

    ada = malloc(size * sizeof(int));
    soluzione = malloc(size * sizeof(char));

    strcpy(soluzione,frase);
    creaArr(frase,size,ada);

    //vedo se è corretto 
    for(int i = 0; i < size; i++){
        printf("\nada[%d] = %d",i,ada[i]);
    };
    
    crypt(frase,ada,size,soluzione);

    printf("\necco la frase criptata: %s\n",soluzione);
    free(soluzione);
    free(ada);
    return 0;
}