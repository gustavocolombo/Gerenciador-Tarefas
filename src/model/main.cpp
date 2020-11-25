#include <iostream>
#include "../ListaTarefas/ListaTarefas.hpp"

using namespace std;
using std::cout;

/*
    Nome: Gustavo Clemente Colombo da Rocha
    Matrícula: 470168
    Curso: Engenharia de Software - Semestre 3
*/

void menu(){ 
    cout << "---------------------------------------------------" << endl;
    cout << "Bem vindo ao gerenciador de tarefas!" << endl;
    cout << "Você poderá digitar um número de 1 a 7 para realizar as funções disponĩveis" << endl;
    cout << "---------------------------------------------------" << endl;

        cout << "1- Adicionar Tarefa" << endl;
        cout << "2- Remover Tarefa" << endl;
        cout << "3- Marcar uma tarefa como concluída" << endl;
        cout << "4- Reabrir uma tarefa já concluída" << endl;
        cout << "5- Visualizar tarefas" << endl;
        cout << "6- Filtrar tarefas" << endl;
        cout << "7- Ordenar Tarefas subindo tarefas" << endl;
        cout << "8- Ordenar Tarefas descendo tarefas" << endl;
        cout << "9- Ordenar tarefas trocando tarefas de posição" << endl;
        cout << "10- Sair do gerenciador do tarefas" << endl;

        cout << "---------------------------------------------------" << endl;

}

int main() {
	
    bool parar = false;
    unsigned int decisao;
    unsigned int indice;
    unsigned int indiceReordenado;
    unsigned int decisaoFiltragem;
    unsigned int dataCriacao;
    string dataPrazo;
    string novoPrazo;
    string descricao;
    ListaTarefas lista ;


    while(parar != true){ 
         menu();

            cin >> decisao; 
            while(decisao > 10){ 
                cout << "---------------------------------------------------" << endl;
                cout << "Por favor insira um correspondente para ação válida" << endl;
                cout << "---------------------------------------------------" << endl;
                menu();
                cin >> decisao;
            }
            
            switch (decisao){
            case 1:  
                if(decisao == 1){
                    cout << "---------------------------------------------------" << endl;
                    cout << "Por favor, informe a descrição/título da tarefa" << endl;
                    cout << "---------------------------------------------------" << endl;
                        cin.ignore();
                        getline(cin, descricao);
                    cout << "---------------------------------------------------" << endl;
                    cout << "Por favor, informe qual é o número da tarefa" << endl;
                    cout << "---------------------------------------------------" << endl;
                        cin >> dataCriacao;
                        cin.ignore();
                    cout << "---------------------------------------------------" << endl;
                    cout << "Por favor informe a data de prazo da tarefa no formato DD/MM/AAAA" << endl;
                        cout << "---------------------------------------------------" << endl;
                        getline(cin, dataPrazo);
                        

                    Tarefa *task = new Tarefa(descricao, false, dataCriacao, dataPrazo); //aqui posteriormente serão os dados que o usuário irá passar
                    
                    lista.adicionarTarefa(task);

                }
                break;
            case 2:
                if(decisao == 2){
                   cout << "Por favor informe o método de filtragem: 1 para concluídas e 2 para abertas" << endl;
                   cin >> decisaoFiltragem;
                   cout << "Por favor informe o índice para a remoção" << endl;
                   cin >> indice;
                   lista.filtrarTarefas(decisaoFiltragem, indice);
                    bool removido = lista.removerTarefa(indice);
                        
                        if(removido){
                            cout << "A tarefa foi removida:" << removido << endl;
                        }else{
                            cout << "A tarefa não foi removida:" << removido << endl;
                        }

                }
                break;
            case 3:
                if(decisao == 3){
                    cout << "--------------------------------------------------" << endl;
                    cout << "Informe o índice que deseja buscar na lista de tarefas:" << endl;
                    cin >> indice;
                    cout << "Por favor informe agora o estado da filtragem para mostrarmos as tarefas em tela: 1 para fechadas e 2 para abertas" << endl;
                    cin >> decisaoFiltragem;

                    lista.filtrarTarefas(decisaoFiltragem, indice);
                    bool concluido = lista.marcarConcluida(indice);

                        cout << "A tarefa foi:" << concluido << endl;
                
                }
                break;
            case 4:
                if(decisao == 4){
                    cout << "Por favor, informe o índice da tarefa que deseja reabrir:" << endl;
                    cout << "---------------------------------------------------" << endl;
                    cin >> indice;

                    cout << "Por favor informe o estado para a filtragem da tarefa, 1: concluída,2 para abertas e qualquer outro para todas" << endl;
                    cin >> decisaoFiltragem;
                        lista.filtrarTarefas(decisaoFiltragem, indice);

                    cout << "Por favor informe qual o novo prazo de entrega da tarefa" << endl;
                    cout << "---------------------------------------------------" << endl;
                    cin >> novoPrazo;

                        bool tarefaReaberta = lista.reabrirTarefa(indice, novoPrazo);

                        if(tarefaReaberta){
                            cout << "A tarefa foi reaberta com sucesso" << endl;
                        }else{
                            cout << "A tarefa ainda está em aberto" << endl;
                        }
                }
                break;
            case 5: 
                if(decisao == 5){
                   
                    lista.visualizarTarefas();
                }
                break;
            case 6:
                if(decisao == 6){
                    cout << "---------------------------------------------------" << endl;
                    cout << "Por favor informe qual a forma de filtragem" << endl;
                    cout << "Digite 1 para tarefas concluídas, 2 para tarefas abertas e outro para todas" << endl;
                        cin >> decisaoFiltragem;
                        
                        switch (decisaoFiltragem){
                        case 1:
                            if(decisaoFiltragem == 1 || 2){
                                lista.filtrarTarefas(decisaoFiltragem, indice);
                            }
                            break;
                        
                        default:
                            lista.visualizarTarefas();
                            break;
                        }
                }
                break;
            case 7:
                if(decisao == 7){
                    cout << "---------------------------------------------------" << endl; //Após reoordenar as tarefas neste método, aperte o comando 5 no menu
                    cout << "Por favor informe qual a forma de filtragem" << endl;
                    cout << "Digite 1 para tarefas concluídas, 2 para tarefas abertas e outro para todas" << endl;
                        cin >> decisaoFiltragem;
                              while(decisaoFiltragem > 2) {
                                cout << "Essa opção não corresponde a tarefas abertas ou fechadas, tecle 1 para fechadas e 2 para abertas" << endl;
                                cin >> decisaoFiltragem;  
                            }
                    cout << "Por favor informe o índice da tarefa que deseja mover" << endl;
                        cin >> indice;
                    cout << "Por favor informe para onde a tarefa deve ser reordenada" << endl;

                        cin >> indiceReordenado;
                        
                        lista.subirTarefa(decisaoFiltragem, indice, indiceReordenado);

                        
                }
                break;
            case 8:
              if(decisao == 8){ 
                    cout << "---------------------------------------------------" << endl; //Após reoordenar as tarefas neste método, aperte o comando 5 no menu
                    cout << "Por favor informe qual a forma de filtragem" << endl; 
                    cout << "Digite 1 para tarefas concluídas, 2 para tarefas abertas e outro para todas" << endl;
                        cin >> decisaoFiltragem;
                              while(decisaoFiltragem > 2) {
                                cout << "Essa opção não corresponde a tarefas abertas ou fechadas, tecle 1 para fechadas e 2 para abertas" << endl;
                                cin >> decisaoFiltragem;  
                            }
                    cout << "Por favor informe o índice da tarefa que deseja mover" << endl;
                        cin >> indice;
                    cout << "Por favor informe para onde a tarefa deve ser reordenada" << endl;
                        cin >> indiceReordenado;
                        
                        lista.descerTarefa(decisaoFiltragem, indice, indiceReordenado);    

                }
                break;
            case 9:
                if(decisao == 9){ //Após reoordenar as tarefas neste método, aperte o comando 5 no menu
                    cout << "---------------------------------------------------" << endl; 
                    cout << "Por favor informe qual a forma de filtragem" << endl;
                    cout << "Digite 1 para tarefas concluídas, 2 para tarefas abertas e outro para todas" << endl;
                        cin >> decisaoFiltragem;
                            while(decisaoFiltragem > 2) {
                              cout << "Essa opção não corresponde a tarefas abertas ou fechadas, tecle 1 para fechadas e 2 para abertas" << endl;
                              cin >> decisaoFiltragem;  
                            }
                    cout << "Por favor informe o índice da tarefa que deseja mover de posição" << endl;
                        cin >> indice;
                    cout << "Por favor informe para onde a tarefa deve ser reordenada" << endl;
                        cin >> indiceReordenado;

                        lista.trocarPosicaoTarefa( indice, indiceReordenado);
                }
                break;
            case 10:
                parar = true;
                break;
            default:
                parar = true;
                break;
            }   
        
        
    }
}