#include <iostream>
#include <cstdlib>
#include "ListaTarefas.hpp"

using namespace std;

ListaTarefas::ListaTarefas(){
  this->tamanho = 0; 
  this->capacidade = 50;
  this->vetor = new Tarefa*[tamanho];   
}

void ListaTarefas::adicionarTarefa(Tarefa *tarefa){
  if (this -> tamanho < this -> capacidade) {
    this->vetor[tamanho] = tarefa;
    this->tamanho++;
  } else {
    this -> vetor = (Tarefa**) realloc (this -> vetor, sizeof(Tarefa) * (this -> capacidade * 2));

    this -> capacidade *= 2;
    this->vetor[tamanho] = tarefa;
    this->tamanho++;

  }
}

bool ListaTarefas::removerTarefa(unsigned int indice){
  if(this->tamanho == 0){
    cout << "Desculpe, não temos tarefas para remover na lista" << endl;
    return false;
  }

  bool elementoPertence = buscar(indice);
    if(!elementoPertence){
      cout << "Desculpe, o índice informado não corresponde a nenhuma tarefa" << endl;
      return false;
    }else{
      for(unsigned int i = 0; i < this->tamanho; i++){
        if(i == indice){
          for(unsigned int i = indice; i < this->tamanho; i++){
            this->vetor[i] = this->vetor[i+1];
          }
          this->tamanho--;
          return true;
        }
      }
    }
  return false;

}

bool ListaTarefas::buscar(unsigned int indice){
  if(this->tamanho == 0) return false;

    for(unsigned int i = 0; i < this->tamanho; i++){
      if(i == indice){
        return true;
      }
    }
  return false;
}

bool ListaTarefas::marcarConcluida(unsigned int indice){

  if(this->tamanho == 0){
    cout << "Não há como marcar como concluída nenhuma tarefa, a lista está vazia" << endl;
    return false;
  }

  bool elementoPertence = buscar(indice);
    if(elementoPertence){
      for(unsigned int i = 0; i < this->tamanho; i++){
        if(i == indice){
          vetor[i]->getEstado();
          if(vetor[i]->getEstado() == false){
             vetor[i]->setEstado(true); //mudar seu estado para concluído - true;
             return true;
          }
        }
      }
    }else{
      cout << "Desculpe, esse elemento não pertence a lista, não foi concluída" << endl;
      return false;
    }

  return false;
}

bool ListaTarefas::reabrirTarefa(unsigned int indice, string novoPrazo){
  if(this->tamanho == 0){
    cout << "Não há como reabrir tarefas, a lista está zerada" << endl;
    return false;
  }

  bool elementoPertence = buscar(indice);
    if(!elementoPertence){
      cout << "Desculpe, esse índice não pertence a lista de tarefas" << endl;
      return false;
    }else{
      for(unsigned int i = 0; i < this->tamanho; i++){
        if(i == indice){
          vetor[i]->getEstado();          
            if(vetor[i]->getEstado() == true){
              vetor[i]->setEstado(false); //marcar o estado da tarefa para false, ainda em aberto
              vetor[i]->setDataPrazo(novoPrazo);
              return true;
            }else{
              cout << "Esta tarefa ainda está aberta" << endl;
            }
        }
      }
    }
    return false;
}

void ListaTarefas::visualizarTarefas(){
  if(this->tamanho == 0){
    cout << "Não há como visualizar tarefas, a lista de tarefas está vazia" << endl;
    return;
  }

  for(unsigned int i = 0; i< this->tamanho; i++){
    cout << "-----------------------------------------" << endl;
      cout << "Índice:" << i << endl;
      cout << "Estado da tarefa:" << vetor[i]->getEstado() << endl;
      cout << "Data de prazo da tarefa:" << vetor[i]->getDataPrazo() << endl;

  }
}


void ListaTarefas::verificaConcluida(unsigned int indice){
  if(this->tamanho == 0){
    return;
  }

  for(unsigned int i = 0; i < this->tamanho; i++){
    if(i == indice){
      if(vetor[i]->getEstado() == true){
        for(unsigned int i = 0; i < this->tamanho; i++){
          cout << "Índice" << i << endl;
          cout << "Esta tarefa foi concluída" << endl;
        }
      }

    }else{
      cout << "Esta tarefa ainda não foi concluída" << endl;
    }
  }
}

void ListaTarefas::verificaAberta(unsigned int indice){
  if(this->tamanho == 0){
    return;
  }

  for(unsigned int i = 0; i < this->tamanho; i++){
    if(i == indice){
      if(vetor[i]->getEstado() == false){
        for(unsigned int i = 0; i < this->tamanho; i++){
          cout << "Índice:" << i << endl;
          cout << "Esta tarefa não foi concluída" << endl;
        }
      }else{
        cout << "Esta tarefa ainda já foi concluída" << endl;
      }
    }
  }
}

void ListaTarefas::filtrarTarefas(int decisaoFiltragem, unsigned int indice){
  if(this->tamanho == 0){
    cout << "Não há como visualizar tarefas, a lista de tarefas está vazia" << endl;
    return;
  }

  switch(decisaoFiltragem){
    case 1: 
        if(decisaoFiltragem == 1){
            verificaConcluida(indice);
        }
      break;
    case 2: 
      if(decisaoFiltragem == 2){
          verificaAberta(indice);
      }
    default:
      visualizarTarefas();
      break;
  }
}

Tarefa* ListaTarefas::subirTarefa(unsigned int decisaoFiltragem, unsigned int indice, unsigned int indiceReordenado){
  if(this->tamanho == 0){
     cout << "Não há como visualizar tarefas, a lista de tarefas está vazia" << endl;
     return 0;
  }
  
  /*
    ele primeiro lê os índices do usuário, mesmo que os índices não estejam na lista, os erros só acontecem depois que
    os valores de índice estão dentro desse método pra verificação
  */

  filtrarTarefas(decisaoFiltragem, indice);

  if(indiceReordenado > this->tamanho){
    cout << "Não existe tarefa correspondente dentro da lista" << endl;
    return 0;
  }

    bool elementoPertence = buscar(indice);
    if(!elementoPertence){
      cout << "Desculpe, o índice informado não corresponde a nenhuma tarefa" << endl;
      return 0;
    }else{
      for(unsigned int i = 0; i < this->tamanho; i++){
        if(i == indice){
            trocarPosicaoTarefa(indice, indiceReordenado); //após reordenar, aperte no menu a opção 5 para poder ver as tarefas reordenadas
        }
      }
    }
  return 0;
  
}

Tarefa* ListaTarefas::descerTarefa(unsigned int decisaoFiltragem, unsigned int indice, unsigned int indiceReordenado){
  if(this->tamanho == 0){
     cout << "Não há como visualizar tarefas, a lista de tarefas está vazia" << endl;
     return 0;
  }
  
  /*
    ele primeiro lê os índices do usuário, mesmo que os índices não estejam na lista, os erros só acontecem depois que
    os valores de índice estão dentro desse método pra verificação
  */

  filtrarTarefas(decisaoFiltragem, indice);

  if(indiceReordenado > this->tamanho){
    cout << "Não existe tarefa correspondente dentro da lista" << endl;
    return 0;
  }

    bool elementoPertence = buscar(indice);
    if(!elementoPertence){
      cout << "Desculpe, o índice informado não corresponde a nenhuma tarefa" << endl;
      return 0;
    }else{
      for(unsigned int i = tamanho; i > 0; i--){
        if(i == indice){
            trocarPosicaoTarefa(indice, indiceReordenado); //após reordenar, aperte no menu a opção 5 para poder ver as tarefas reordenadas
        }
      }
    }
  return 0;
  
}

void ListaTarefas::trocarPosicaoTarefa( unsigned int indice, unsigned int indiceReordenado){
  if(this->tamanho == 0){
   cout << "Não existe tarefa correspondente dentro da lista" << endl;
    return;
  }

  Tarefa *copia = vetor[indice];
  vetor[indice] = vetor[indiceReordenado];
  vetor[indiceReordenado] = copia;

}
