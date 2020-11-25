#include "Tarefa.hpp"
#include <string>
using std::string;
#include <iostream>

Tarefa::Tarefa(){} 

Tarefa::Tarefa(string descricao, bool estado, int dataCriacao,  string dataPrazo){
	this->descricao = descricao;
	this->estado = estado;
	this->dataCriacao = dataCriacao;
	this->dataPrazo = dataPrazo;
}

bool Tarefa::getEstado(){
	return this->estado;
}

void Tarefa::setEstado(bool estado){
	this->estado = estado;
}

string Tarefa::getDescricao(){
	return this->descricao;
}

void Tarefa::setDescricao(string descricao){
	this->descricao = descricao;
}

int Tarefa::getDataCriacao(){
	return this->dataCriacao;
}

void Tarefa::setDataCriacao(int dataCriacao){
	this->dataCriacao = dataCriacao;
}

string Tarefa::getDataPrazo(){
	return this->dataPrazo;
}

void Tarefa::setDataPrazo(string dataPrazo){
	this->dataPrazo = dataPrazo;
}