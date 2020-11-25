#include "../model/Tarefa.hpp"

class ListaTarefas{ 
  private:
    unsigned int capacidade;
    unsigned int tamanho;
    Tarefa** vetor;

  public:
    ListaTarefas(); 

    void adicionarTarefa(Tarefa *tarefa);
  
    bool removerTarefa(unsigned int indice);

    bool buscar(unsigned int indice); 

    bool marcarConcluida(unsigned int indice); 

    bool reabrirTarefa(unsigned int indice, string novoPrazo); 

    void visualizarTarefas(); 

    void verificaConcluida(unsigned int indice);

    void verificaAberta(unsigned int indice);
    
    void filtrarTarefas(int decisaoFiltragem, unsigned int indice);

    Tarefa* subirTarefa (unsigned int decisaoFiltragem, unsigned int indice, unsigned int indiceReordenado);
     
    Tarefa* descerTarefa (unsigned int decisaoFiltragem, unsigned int indice, unsigned int indiceReordenado);  

    void trocarPosicaoTarefa( unsigned int indice, unsigned int indiceReordenado);
};
