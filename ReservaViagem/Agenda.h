#include "../Utils/Headers.h"

/**
 * Cria uma agenda vazia (caso nao tenha nenhuma reserva) ou com uma reserva cadastrada (caso receba uma reserva como parametro).
 * Retorna a agenda criada ou NULL caso nao seja possivel alocar memoria para a agenda.
 * @param p_reserva
 * @return NULL
 * @return p_agenda
 */
Agenda *cria_agenda(Reserva *p_reserva);

/**
 * Insere uma agenda de forma que caso nao exista nenhuma agenda ainda cadastrada sera inserido a primeira e
 * dai pra frente serao inseridas novas agendas baseando-se sempre na data da reserva contida nesta agenda.
 * Retorna NULL caso nao seja possivel inserir a genda ou entao a raiz.
 * @param p_agenda
 * @param p_novaAgenda
 * @return NULL
 * @return p_agendaAnterior
 */
Agenda *insere_agenda(Agenda *p_agenda, Agenda *p_novaAgenda);

/**
 * Acessa valores dos atributos da agenda.
 * @param p_agenda
 * @param p_reserva
 * @param p_agendaEsquerda
 * @param p_agendaDireita
 */
void acessa_agenda(
        Agenda *p_agenda,
        Reserva **p_reserva,
        Agenda **p_agendaEsquerda,
        Agenda **p_agendaDireita);

/**
 * Libera espaço da memoria que uma dada agenda ocupava e assim suas agendas subsequentes.
 * Retorna 0 caso haja erro em fazer a liberaçao e 1 caso tenha sucesso.
 * @param pp_agenda
 * @return 0
 * @return 1
 */
int libera_agenda(Agenda **pp_agenda);

Agenda *remove_agenda(Agenda *p_raizAgenda, Reserva *p_reserva);