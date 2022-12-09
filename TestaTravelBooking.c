#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils/Utils.h"
#include "ListaPassageiros/Passageiro.h"
#include "ListaPassageiros/ListaPassageiros.h"
#include "ListaVoos/ListaVoos.h"
#include "ReservaViagem/Data.h"
#include "ReservaViagem/Reserva.h"
#include "ReservaViagem/Agenda.h"
#include "TabelaViagens/TabelaViagens.h"

void testa_crud_agenda(void) {
    printf("- Testando crud_agenda()...\n");
    Passageiro *p_passageiro1 = passageiro_cria("Leon", "Belo Horizonte");
    Passageiro *p_passageiro2 = passageiro_cria("Alan", "Ceará");
    Passageiro *p_passageiro3 = passageiro_cria("Vitor", "Acre");
    Voo *p_voo1 = cria_voo("Fortaleza", "SP");
    Voo *p_voo2 = cria_voo("Natal", "RJ");
    Voo *p_voo3 = cria_voo("Alagoas", "BH");
    Data *p_dataPartida1 = cria_data(10, 12, 2022);
    Data *p_dataChegada1 = cria_data(11, 12, 2022);
    Data *p_dataPartida2 = cria_data(20, 11, 2022);
    Data *p_dataChegada2 = cria_data(21, 11, 2022);
    Data *p_dataPartida3 = cria_data(9, 10, 2022);
    Data *p_dataChegada3 = cria_data(10, 10, 2022);
    Reserva *p_reserva1 = cria_reserva(p_dataPartida1, p_dataChegada1, p_passageiro1, p_voo1, A0);
    Reserva *p_reserva2 = cria_reserva(p_dataPartida2, p_dataChegada2, p_passageiro2, p_voo2, A0);
    Reserva *p_reserva3 = cria_reserva(p_dataPartida3, p_dataChegada3, p_passageiro3, p_voo3, A0);
    Agenda *p_agenda1 = cria_agenda(p_reserva1);
    Agenda *p_agenda2 = cria_agenda(p_reserva2);
    Agenda *p_agenda3 = cria_agenda(p_reserva3);
    Reserva *p_acessaReserva = NULL;
    Agenda *p_acessaEsq = NULL;
    Agenda *p_acessaDir = NULL;
    insere_agenda(p_agenda1, p_agenda2);
    insere_agenda(p_agenda1, p_agenda3);
    acessa_agenda(p_agenda1, &p_acessaReserva, &p_acessaEsq, &p_acessaDir);

    int id;
    Passageiro *p_acessaPassageiro = (Passageiro *) malloc(passageiro_tamanho());
    Voo *p_acessaVoo = cria_voo("A", "O");
    Data *p_acessaDataPartida = cria_data(1, 2, 2002);
    Data *p_acessaDataChegada = cria_data(2, 2, 2002);
    CodigoAssento codigoAssento;

    acessa_reserva(p_reserva1, &id, &p_acessaDataPartida, &p_acessaDataChegada, &p_acessaPassageiro, &p_acessaVoo,
                   &codigoAssento);
    char *p_nomePassageiro = (char *) malloc(sizeof(char) * 300);
    char *p_enderecoPassageiro = (char *) malloc(sizeof(char) * 300);
    char *p_origemVoo = (char *) malloc(sizeof(char) * 300);
    char *p_destinoVoo = (char *) malloc(sizeof(char) * 300);
    //Leitura passageiro e voo 1
    passageiro_acessa(p_acessaPassageiro, &id, p_nomePassageiro, p_enderecoPassageiro);
    print_teste(strcmp(p_nomePassageiro, "Leon") == 0 && strcmp(p_enderecoPassageiro, "Belo Horizonte") == 0,
                "leitura - passageiro1");
    leitura_voo(p_acessaVoo, &id, p_origemVoo, p_destinoVoo);
    print_teste(strcmp(p_origemVoo, "Fortaleza") == 0 && strcmp(p_destinoVoo, "SP") == 0, "leitura - voo1");
    //Edita passageiro e voo 1
    passageiro_atribui(p_passageiro1, "Lima", "Londres");
    edita_voo(p_voo1, "Santos", "Campinas");
    acessa_reserva(p_reserva1, &id, &p_acessaDataPartida, &p_acessaDataChegada, &p_acessaPassageiro, &p_acessaVoo,
                   &codigoAssento);
    passageiro_acessa(p_acessaPassageiro, &id, p_nomePassageiro, p_enderecoPassageiro);
    leitura_voo(p_acessaVoo, &id, p_origemVoo, p_destinoVoo);
    print_teste(strcmp(p_nomePassageiro, "Lima") == 0 && strcmp(p_enderecoPassageiro, "Londres") == 0,
                "edita - passageiro1");
    print_teste(strcmp(p_origemVoo, "Santos") == 0 && strcmp(p_destinoVoo, "Campinas") == 0, "edita - voo1");
    //Leitura passageiro e voo 2
    acessa_reserva(p_reserva2, &id, &p_acessaDataPartida, &p_acessaDataChegada, &p_acessaPassageiro, &p_acessaVoo,
                   &codigoAssento);
    passageiro_acessa(p_acessaPassageiro, &id, p_nomePassageiro, p_enderecoPassageiro);
    print_teste(strcmp(p_nomePassageiro, "Alan") == 0 && strcmp(p_enderecoPassageiro, "Ceará") == 0,
                "leitura - passageiro2");
    leitura_voo(p_acessaVoo, &id, p_origemVoo, p_destinoVoo);
    print_teste(strcmp(p_origemVoo, "Natal") == 0 && strcmp(p_destinoVoo, "RJ") == 0, "leitura - voo2");
    //Edita passageiro e voo 2
    passageiro_atribui(p_passageiro2, "Angelo", "Bahamas");
    edita_voo(p_voo2, "Manaus", "Roraima");
    acessa_reserva(p_reserva2, &id, &p_acessaDataPartida, &p_acessaDataChegada, &p_acessaPassageiro, &p_acessaVoo,
                   &codigoAssento);
    passageiro_acessa(p_acessaPassageiro, &id, p_nomePassageiro, p_enderecoPassageiro);
    leitura_voo(p_acessaVoo, &id, p_origemVoo, p_destinoVoo);
    print_teste(strcmp(p_nomePassageiro, "Angelo") == 0 && strcmp(p_enderecoPassageiro, "Bahamas") == 0,
                "edita - passageiro2");
    print_teste(strcmp(p_origemVoo, "Manaus") == 0 && strcmp(p_destinoVoo, "Roraima") == 0, "edita - voo2");
    //Leitura passageiro e voo 3
    acessa_reserva(p_reserva3, &id, &p_acessaDataPartida, &p_acessaDataChegada, &p_acessaPassageiro, &p_acessaVoo,
                   &codigoAssento);
    passageiro_acessa(p_acessaPassageiro, &id, p_nomePassageiro, p_enderecoPassageiro);
    print_teste(strcmp(p_nomePassageiro, "Vitor") == 0 && strcmp(p_enderecoPassageiro, "Acre") == 0,
                "leitura - passageiro3");
    leitura_voo(p_acessaVoo, &id, p_origemVoo, p_destinoVoo);
    print_teste(strcmp(p_origemVoo, "Alagoas") == 0 && strcmp(p_destinoVoo, "BH") == 0, "leitura - voo3");
    //Edita passageiro e voo 3
    passageiro_atribui(p_passageiro3, "Berge", "UFC");
    edita_voo(p_voo3, "A", "B");
    acessa_reserva(p_reserva3, &id, &p_acessaDataPartida, &p_acessaDataChegada, &p_acessaPassageiro, &p_acessaVoo,
                   &codigoAssento);
    passageiro_acessa(p_acessaPassageiro, &id, p_nomePassageiro, p_enderecoPassageiro);
    leitura_voo(p_acessaVoo, &id, p_origemVoo, p_destinoVoo);
    print_teste(strcmp(p_nomePassageiro, "Berge") == 0 && strcmp(p_enderecoPassageiro, "UFC") == 0,
                "edita - passageiro3");
    print_teste(strcmp(p_origemVoo, "A") == 0 && strcmp(p_destinoVoo, "B") == 0, "edita - voo3");

    print_teste(libera_agenda(&p_agenda1), "libera_agenda");
}

void testa_tabela(void) {
    printf("- Testando TabelaViagens()...\n");
    Passageiro *p_passageiro1 = passageiro_cria("Leon", "Belo Horizonte");
    TabelaPassageiros *p_tabelaPassageiros = cria_tabela_passageiros();
    insere_tabela_passageiros(p_tabelaPassageiros, p_passageiro1);
    Voo *p_voo1 = cria_voo("Fortaleza", "Natal");
    Voo *p_voo2 = cria_voo("Natal", "Ouro Preto");
    Voo *p_voo3 = cria_voo("Ouro Preto", "Campinas");
    Data *p_dataPartida1 = cria_data(10, 12, 2022);
    Data *p_dataChegada1 = cria_data(11, 12, 2022);
    Data *p_dataPartida2 = cria_data(12, 12, 2022);
    Data *p_dataChegada2 = cria_data(13, 12, 2022);
    Data *p_dataPartida3 = cria_data(14, 12, 2022);
    Data *p_dataChegada3 = cria_data(15, 12, 2022);

    Reserva **pp_vetorReserva = malloc(sizeof(Reserva *) * 3);
    pp_vetorReserva[0] = cria_reserva(p_dataPartida1, p_dataChegada1, p_passageiro1, p_voo1, A0);
    pp_vetorReserva[1] = cria_reserva(p_dataPartida2, p_dataChegada2, p_passageiro1, p_voo2, B3);
    pp_vetorReserva[2] = cria_reserva(p_dataPartida3, p_dataChegada3, p_passageiro1, p_voo3, B2);
    Viagem *p_viagem = viagem_cria(pp_vetorReserva, 3);
    TabelaViagens *p_tabela = tabela_cria();
    print_teste(tabela_insere_viagem(p_tabela, p_tabelaPassageiros, p_viagem), "inserção da viagem");

    int codigoPassageiro = get_viagem_codigo_passageiro(p_viagem);
    CodigosReservas *p_codigosReservas = viagem_cria_lista_codigos_reservas(p_viagem);
    int codigoReserva0 = get_reserva_codigo(pp_vetorReserva[0]);
    int vetorCodigos[3] = {codigoReserva0, codigoReserva0 + 1, codigoReserva0 + 2};
    CodigosReservas *p_codigosReservas2 = vetor_cria_lista_codigos_reservas(vetorCodigos, 3);

    print_teste(tabela_pesquisa_viagem(p_tabela, codigoPassageiro, p_codigosReservas) != NULL, "Pesquisa viagem");
    print_teste(tabela_pesquisa_viagem(p_tabela, codigoPassageiro, p_codigosReservas2) != NULL,
                "Pesquisa viagem - usando CodigosReservas criados a partir de uma lista de inteiros.");
    print_teste(tabela_remove_viagem(p_tabela, p_tabelaPassageiros, p_viagem), "Remoção de viagem existente");
    print_teste(tabela_pesquisa_viagem(p_tabela, codigoPassageiro, p_codigosReservas) == NULL,
                "Pesquisa viagem inexistente");
    print_teste(tabela_libera(p_tabela, p_tabelaPassageiros), "liberação tabela");
    free(pp_vetorReserva);
}


int main(void) {
    testa_crud_agenda();
    testa_tabela();
    return 0;
}