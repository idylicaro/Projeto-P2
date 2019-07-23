#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>

#define limpar_tela system("CLS");
using namespace std;
char* nameArchive ="Bd.txt";

struct User
{
    int id;
    char login[15];
    char senha[15];
    char nome[15];
    char token;
};
struct aluno // arquivos das TURMAS
{
    int id_disciplina;
    int id_usuario;
    int nota_alunos1;//distribui as 3 notas pra ficar mais facil o acesso para media, e para exibi��o das notas, e para o cadastro na materia
    int nota_alunos2;
    int nota_alunos3;
} ;

void visualizaTeste();
void inicializar();
void cadastrar();

void home_adm(){
    int opcao;

    while(opcao !=0 ){
        cout << "===========================" << endl;
        cout << "============ADM============" << endl;
        cout << "===========================" << endl;

        cout << "1-Apagar Todos Os Usuarios" << endl;
        cout << "2-Cadastrar" << endl;
        cout << "3-Lista de Cadastrados" << endl;
        cout << "0-Deslogar" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                inicializar();
                limpar_tela;
                cout << "Zerando...";
                Sleep(2000);
                break;
            case 2:
                limpar_tela;
                cadastrar();
                limpar_tela;
                cout << "Usuario Cadastrado!!!";
                Sleep(2000);
                break;
            case 3:
                visualizaTeste();
                getch();
                break;
            case 4:
                break;
        }
        limpar_tela;
        if(opcao == 0) cout << "Saindo..." << endl;
        Sleep(2000);
    }
}

void inicializar(){
    struct User adm = {1, "admin", "admin", "Admin", 'M'};
    struct User vazio = {0,"","","",' '};
    ofstream archive;
    archive.open(nameArchive,ios::out);

    if(archive.fail())
    {
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    archive.write((const char*)(&adm),sizeof(User));
    for(int i=0; i<100; i++)
    {
        archive.write((const char*)(&vazio),sizeof(User));
    }
    archive.close();
}

void verificaCadastrados(int &QuantUsuariosIn) // id automatico verica�ao de quanto usuarios ja estao cadastrados
{
    struct User usu;
    fstream archive;
    archive.open(nameArchive,ios::in);

    if(archive.fail())
    {
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    archive.read((char*)(&usu),sizeof(User));
    while(archive &&!archive.eof())
    {
        if(usu.id!=0)
            QuantUsuariosIn++;
        archive.read((char*)(&usu),sizeof(User));

    }
    archive.close();
}

void cadastrar()
{
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

    cout << "==================================================" << endl;
    cout << "===============Lista De Cadastrados===============" << endl;
    cout << "==================================================" << endl;

    cout << setiosflags(ios::left)
        << setw(16) << "Nome" << setw(2) << "|"
        <<setw(16) << "Login" << setw(2) << "|"
        << setw(7) << "Senha" << setw(2) << "|"
        <<setw(3) << "Tipo" << endl;

    archive.read((char*)(&usu),sizeof(User));
    while(archive &&! archive.eof()){
        if(usu.id != 0){
                cout << setiosflags(ios::left)
                << setw(16) << usu.nome << setw(2) << "|"
                << setw(16) << usu.login << setw(2) << "|"
                <<setw(7) << "*****" << setw(2) << "|"
                << setw(4) << setiosflags(ios::right) << usu.token << endl;

        }
        archive.read((char*)(&usu),sizeof(User));
    }
    cout << "==================================================" << endl;
    archive.close();
}