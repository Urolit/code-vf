#include <stdio.h>

struct Lettera{
    char carattere;
    int frequenza;
    struct Lettera* next;
};

//metodo per aggiungere un nuovo nodo o creare la lista
//TODO mancano tutti i malloc eheheh
void add(struct Lettera*, char);
void add(struct Lettera *f, char c){
    //se la lista è vuota creo un nuovo nodo
    if(isEmpty(f)){
        struct Lettera nuovo;
        nuovo.carattere = c;
        nuovo.frequenza = 1;
        nuovo.next = NULL;
        *f = nuovo;
    }else
    {
        struct Lettera toadd = *cerca(f,c);
        //se esiste la lettera mi faccio passare il puntatore da cerca
        //e incremento la frequenza.
        if (toadd.carattere != NULL)
        {
            toadd.frequenza++;
            return;
        }else 
        {
            //quindi se non è presente il carattere scorro la lista e lo aggiungo
            //scorro la lista fino in fondo
            
            while(toadd.next != NULL){
                toadd = *toadd.next;
            }
            //creo una struttura e l'indirizzo lo metto nel puntatore next dell'ultima struct
            struct Lettera nuovo;
            nuovo.carattere = c;
            nuovo.frequenza = 1;
            nuovo.next = NULL;
            toadd.next = &nuovo;
        }
        
    }
    
}
//controllo che la lista di lettera non sia vuota
int isEmpty (struct Lettera*) ;
int isEmpty (struct Lettera* list) {
    return list == NULL ;
}

//metodo che cerca nella lista se è presente il carattere
struct Lettera* cerca(struct Lettera*,char );
struct Lettera* cerca(struct Lettera *f,char c){
    //struct Lettera tc = *f; //to check
    if(f->carattere == c){
        return &f;}
    if(f->next == NULL){
        return NULL;}
    else{
        return cerca(f->next,c);
    }     
}

//ordina la lista in base alla frequenza così da scorrerla in maniera ottimale
//quando vado a scambiare i caratteri
void ordinaLista(struct Lettera *,struct Lettera*);
void ordinaLista(struct Lettera *disordinata, struct Lettera *ordinata){
    struct Lettera* pnav = disordinata;
    int navigatore = 1;
    int maxfreq= 0;
    while (pnav->next != NULL && navigatore != maxfreq)
    {
        //per evita di uscire troppo presto
        if (pnav->frequenza > maxfreq){
            maxfreq = pnav->frequenza; 
        }

        if (pnav->frequenza == navigatore)
        {
            add(ordinata,pnav->carattere);
            pnav = pnav->next;
        }else
        {
            pnav = pnav->next;
        }
        
        if (pnav->next == NULL && navigatore < maxfreq )
        {
            navigatore++;
            pnav = disordinata;
        }   
    }
    return;
}
//f = frase && gs = given string;
//il metodo che scambia le lettere e ritorna la stringa risolta
char crypt(struct Lettera,char*);
char crypt(struct Lettera f, char *gs){
    //ricordati il malloc per creare una stringa lunga come quella data.
    /* per ogni carattere nella stringa gs chiamo f.add,
     una volta completato ordino la lista
     poi scorro la lista ordinata sostituendo il primo carattere che trovo
     con l'ultimo carattere con la stessa frequenza
     A B C D E
     1 1 1 2 2
     per esempio scambio la A con la C e viceversa nella stringa gs, poi le rimuovo
     la B da sola viene ignorata, poi viene sostituita la D con la E e viceversa.
     quando la lista non ha altri valori ritorno la stringa trasformata.
    */
    for(int i = 0; i < strlen(gs); i++){
        add(&f,gs[i]);
    }
    struct Lettera ordinata;
    ordinaLista(&f, &ordinata);
    
    /*
    se il primo nodo che prendo non ha next con frequenza uguale allora lo rimuovo
    ovvero *f = *f->next;
    prendo il primo elemento di ordinata
    inizializzo carattere e frequenza.
    scorro ordinata finche navig->next->frequenza != dalla frequenza iniziale
    e lo inizializzo per andare poi a sostituirlo.
    e al puntatore di Lettera gli assegno la memoria del primo->next,
    al puntatore navigatore precedente faccio navprec->next = navprec->next->next;
    cosi tolgo i 2 elementi dalla lista e continuo
    allora nella stringa GS cambio ogni lettera del carattere iniziale
    con il carattere del nodo finale.
    successivamente riapro *f e ripeto quello sopra
    */
}

main(){
    struct Lettera frase;
    char toChange = {"casa"};
    char criptedString;
    printf("frase da criptare : %s",toChange);
    printf("la frase criptata e' : %s",criptedString);
}