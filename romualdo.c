/*Romualdo � o chefe da equipe de estagi�rios � qual voc� pertence.
Hoje, o Romualdo chegou todo apressado dizendo que precisava de ajuda, r�pido!
Ele descobriu que usu�rios tiveram suas contas hackeadas no servidor SSH da empresa e precisava tomar provid�ncias.
Disse ele: "Aqui est� uma lista de logins. Preciso descartar os logins com mais de 8 caracteres, pois estes n�o foram hackeados.
Nos demais logins, preciso adicionar o sufixo "@mycompany.com" e orden�-los em ordem alfab�tica.
Vou ter que usar essa lista depois para mandar e-mails e fazer outras opera��es no sistema.".
*/


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct user user;
struct user{
    char* login;
    user* prox;
};

void lista_insere_inicio(user **l, char* login){
        user* novo=(user*)malloc(sizeof(user));
        novo->login=malloc(sizeof(char)*(strlen(login)+1));
        strcpy(novo->login, login);
        novo->prox=*l;
        *l=novo;
}


void le_arquivo(user** lista){
    char temp[100];
    FILE* logins;
    logins=fopen("listadelogins.txt", "r");
    while (fscanf(logins, "%s[^\n]", temp) == 1){
        lista_insere_inicio(lista, temp);
    }
    fclose(logins);
}

void escreve_arquivo(user** lista){
    FILE* logins=fopen("logins hackeados.txt", "w");
    user* aux=*lista;
    while(aux!=NULL){
        fprintf(logins, "%s\n", aux->login);
        aux=aux->prox;
    }
    fclose(logins);

}

void oito_chars(user** lista, user** lista8){
    user* aux=*lista;
    while(aux!=NULL){
        if(strlen(aux->login)<=8){
            lista_insere_inicio(lista8, aux->login);
        }
        aux=aux->prox;
    }
}

void insere_sufixo(user** lista){
    user* aux=*lista;
    while(aux!=NULL){
        aux->login=realloc(aux->login, sizeof(char)*(strlen(aux->login)+15));
        strcat(aux->login, "@mycompany.com");
        aux=aux->prox;
    }
}

void ordena_lista(user** lista){
    user* aux=*lista;
    user* aux2;
    char* auxlogin;
    while(aux!=NULL){
        aux2=aux;
        while(aux2!=NULL){
            if(strcmp(aux2->login, aux->login)<0){
                auxlogin=aux->login;
                aux->login=aux2->login;
                aux2->login=auxlogin;
            }
            aux2=aux2->prox;
        }
        aux=aux->prox;
    }
}

int main(){
    user* lista=NULL;
    user* lista8=NULL;
    le_arquivo(&lista);
    oito_chars(&lista, &lista8);
    ordena_lista(&lista8);
    insere_sufixo(&lista8);
    escreve_arquivo(&lista8);
    return 0;
}



