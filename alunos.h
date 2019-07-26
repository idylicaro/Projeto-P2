#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void realizar_matricula(int usuario_ID);
void exibir_materias();

void home_aluno(int usuario_ID){
    int opcao;

    while(opcao !=0 ){
        cout << "===========================" << endl;
        cout << "===========ALUNO===========" << endl;
        cout << "===========================" << endl;

        cout << "1-Realizar Matricula" << endl;
        cout << "2-" << endl;
        cout << "3-" << endl;
        cout << "0-Deslogar" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                realizar_matricula(usuario_ID);
                break;
            case 2:
                exibir_materias();
                break;
            case 3:

                break;
        }
    }
        limpar_tela;
        if(opcao == 0) cout << "Saindo..." << endl;
        Sleep(2000);

}
void realizar_matricula(int usuario_ID){


}
void exibir_materias(){
    int cont=1;
    struct materias m;
    ifstream leitura(".\\Materias\\MATERIAS.txt", ios::in);
    if(leitura.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    cout << "=================================================" << endl;
    cout << "================Lista De Materias================" << endl;
    cout << "=================================================" << endl;

    while(leitura &&! leitura.eof()){
        cout << setiosflags(ios::left)
            << setw(3) << cont << setw(2) << "|"
            << setw(15) << m.nome_materia << endl;
            leitura.read((char*)(&m),sizeof(materias));
            cont++;
    }
}