#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;
#define limpar_tela system("CLS");

#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

using namespace std;
char* nameArchive ="Bd.txt";
struct User{
    int id;
    char login[15];
    char senha[15];
    char nome[15];
    char token;
};

int login(){
    int verifica=0;
    char login[15], senha[15];
    char professor='p';

    User usuario;
    ifstream leitura;
    leitura.open("Bd.txt", ios::in);

    limpar_tela;
    cout << "=====================" << endl << "========LOGIN========" << endl << "=====================" << endl << endl;
    cout << "LOGIN: ";
    cin >> login;
    cout << "SENHA: ";
    cin >> senha;

    while(leitura && !leitura.eof()){
        if(usuario.id != 0){
            if(strcmp(usuario.login,login)==0 && strcmp(usuario.senha,senha)==0){
                    if(usuario.token == 'P' || usuario.token == 'p'){
                        leitura.close();
                        return 1;
                        // para facilitar, podem chamar a fun��o para os professores aqui e remover o return;
                    }
                    else{
                        leitura.close();
                        return 0;
                        // para facilitar, podem chamar a fun��o para os alunos aqui
                    }
                    cout << "achou senha";
                    verifica=1;
                    getch();
                    break;
            }
        }
        leitura.read((char*)(&usuario),sizeof(User));

    }
    leitura.close();
    if(verifica==0) cout <<"Usuario Ou Senha Incorreto";
    Sleep(2000);
}

void inicializar(){
    struct User vazio ={0,"","","",' '};
    ofstream archive;
    archive.open(nameArchive,ios::out);

    if(archive.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    for(int i=0;i<100;i++){
        archive.write((const char*)(&vazio),sizeof(User));
    }
    archive.close();
}

void verificaCadastrados(int &QuantUsuariosIn){
    struct User usu;
    fstream archive;
    archive.open(nameArchive,ios::in);

    if(archive.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    archive.read((char*)(&usu),sizeof(User));
    while(archive &&!archive.eof()){
            if(usu.id!=0)
            QuantUsuariosIn++;
        archive.read((char*)(&usu),sizeof(User));

    }

    //cout <<"quant in "<<QuantUsuariosIn<<"quanttota"<<QuantUsuariosTotal<<endl;  //<- so para teste msm
    archive.close();
}

void cadastrar(){
    struct User newUser;
    int QuantTotal=0,quantIn=0;
    verificaCadastrados(quantIn);
    fstream archive;
    archive.open(nameArchive,ios::out|ios::in|ios::ate);

    if(archive.fail())
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;

        cout <<"Digite o login: ";
        cin  >>newUser.login;
        cout << "Digite a Senha: ";
        cin  >>newUser.senha;
        cout << "Digite Seu Nome: ";
        cin  >>newUser.nome;
        cin.ignore();
        cout <<"Digite que tipo de conta o usuario esta criando P(professor) <-> A(Aluno)"<<endl;
        cin  >> newUser.token;
        newUser.id = (quantIn)+1; //logica para por o proximo id ...



        archive.seekp((newUser.id-1)*sizeof(User));
        archive.write((const char*)(&newUser),sizeof(User));

        archive.close();
    system("CLS");
}

void visualizaTeste(){
    struct User usu;
    fstream archive;
    archive.open(nameArchive,ios::in);

    if(archive.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    archive.read((char*)(&usu),sizeof(User));
    while(archive &&!archive.eof()){
            if(usu.id != 0)
            cout <<"\n"<<usu.id <<"\n"<<usu.login<<"\n"<<usu.senha<<endl;

        archive.read((char*)(&usu),sizeof(User));

    }
    archive.close();
}

char criar_materia(){
    fflush(stdin);
    char nome[20];
    char nome_forReturn[20];

    cout << "Nome Da Materia: ";
    gets(nome);
    nome_forReturn[20]=nome[20];
    strcat(nome,".txt");
    fopen(nome, "w");
}

#endif // BIBLIOTECA_H_INCLUDED
