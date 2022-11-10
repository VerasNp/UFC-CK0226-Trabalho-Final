## **Universidade Federal do Ceará** | **Departamento de Computação**
### **Disciplina: Programação – CK226** | **Professor: Lincoln Souza Rocha**

**Trabalho Final | Equipes de 5 Membros (max) | Data de Entrega: 08/12/2022**

**Tírulo: Reserva de Viagens Aéreas**

O trabalho consiste no desenvolvimento de um sistema de reserva de viagens (`TravelBooking`) aéreas, onde, usando estrutura de listas encadeadas, perfis de passageiros e voos podem ser gerenciados (criação, remoção, edição, leitura e busca). Além disso, o sistema deve gerenciar reservas de viagens, permitindo a criação, remoção, edição, leitura e busca de reservas. Uma reserva deve guardar informações sobre a data da viagem, o passageiro que fará a viagem, o voo e o assento desejado. O sistema deve organizar as reservas por meio de uma estrutura de árvore binária de busca ordenada pelas datas das viagens reservadas. Além das operações ordinárias de gerenciamento (criação, remoção, edição e busca por código da reserva), o sistema deve permitir a busca de reservas de um determinado passageiro por meio das combinações (i) identificador do passageiro e código do voo e (ii) identificador do passageiro e data da viagem. Por fim, o sistema deve permitir criar um roteiro de viagem, que consiste em associar um conjunto de reservas de tal forma que a cidade destino de um reserva leve o passageiro à cidade origem da próxima reserva. Cada viagem deve ser armazenada em uma tabela de dispersão (hash). Quando houver conflitos, a viagem não poderá ser cadastrada. A tabela de viagens deve permitir imprimir na tela dados sobre todo o intinerário, além de dados do passageiro. (OBS. o código hash de cada viagem deve ser função do somatório do identificador do passageiro e dos códigos das reservas associadas).

Algumas restrições:
- Passageiros não podem ter o mesmo código 
- Voos não podem ter o mesmo código
- Reservas não podem ter o mesmo código
- Passageiros não podem fazer reservas com a mesma na mesma data de viagem
- As viagens só podem ser compostas por reservas do mesmo passageiro
- As viagens só podem ser compostas por reservas cujas datas sejam cronologicamente compatíveis (isto é, a data da viagem do próximo trecho deve ser maior que a data da do trecho anterior)
- Passageiros não podem criar viagens com interseção temporal (isto é, períodos de tempo conicidentes entre inicio e fim de cada viagem)

Os arquivos `TravelBooking.c` e `TravelBooking.h` traz algums trechos de código úteis para a implementação do trabalho. No arquivo `TravelBooking.c`, cada equipe deverá escrever casos de teste que evidenciem as funcionalidades do sistema e que ele está respeitando todas as restrições estabelecidas. 
