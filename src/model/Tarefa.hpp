#include <string>
using std::string;

class Tarefa{
  private: 
    string descricao;
    bool estado;
    int dataCriacao;
    string dataPrazo;

    friend class ListaTarefas;
  
  public:
    Tarefa();

    Tarefa(string descricao, bool estado, int dataCriacao,  string dataPrazo);

    bool getEstado();
    void setEstado(bool estado);

    string getDescricao();
    void setDescricao(string descricao);

    int getDataCriacao();
    void setDataCriacao(int dataCriacao);

    string getDataPrazo();
    void setDataPrazo(string dataPrazo);
};

