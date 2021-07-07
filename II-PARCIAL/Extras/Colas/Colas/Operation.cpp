#include  <iostream>
#include <stdlib.h>
#include "Operation.h"
#include "Utils.h"
#include "TextTable.h"
#include <string>
using namespace std;

Client Operation::first() {
    Client client;
    Utils utils;
    int arrival_time=utils.random_int(1,25);
    int waiting_time = 0;
    int service_time=utils.random_int(1,16);
    int time_off = 0;
    int time_between_arrival = arrival_time;
    int exit_time= arrival_time+ waiting_time+ service_time+ time_off;
    client = Client(arrival_time, waiting_time, service_time, time_off, exit_time, time_between_arrival);        
    return client;
}
Queue<Client> Operation::generate_table(int index)
{
    Queue<Client> queue;
    queue.encolar(first());
    queue = calculate_arrival_time(queue, index);
    queue = calculate_service_time(queue, index);
    queue = calculate_waiting_time(queue, index);
    return queue;
}
Queue<Client> Operation::calculate_arrival_time(Queue<Client> &clients,int index)
{
    int arrival;
    int arrival2;
    Utils utils;
    Node<Client>* temp;
    Client client;
    client = Client(0, 0, 0, 0, 0, 0);
    for (int i = 0; i < index - 1; i++)
    {
        temp = clients.get_head();
        arrival = utils.random_int(1, 25);
        while (temp != nullptr)
        {
            arrival2 = temp->get_dato().get_arrival_time();
            client.set_arrival_time(utils.sum(arrival, arrival2));
            client.set_time_between_arrival(arrival);
            temp = temp->get_siguiente();
        }
        clients.encolar(client);
    }
    return clients;
}

Queue<Client> Operation::calculate_service_time(Queue<Client> &clients,int index)
{
    int arrival;
    int arrival2;
    int cont = 0;
    Utils utils;
    Queue<Client>clients1 = clients;
    Client client;
    for (int i = 1; i < clients1.get_size(); i++)
    {       
        arrival = utils.random_int(1, 16);
        client = clients1.search(i);
        client.set_service_time(arrival);
        clients.modify_for_index(client, i);
    }
    return clients;
}

Queue<Client> Operation::calculate_waiting_time(Queue<Client> &clients,int index)
{
    int arrival;
    int arrival2;
    int time_off;
    int cont = 0;
    Utils utils;
    Client client;
    Client client2;
    Client client3;
    Node<Client>* temp = clients.get_head();
    Node<Client>* temp2 ;
    Queue<Client> clients1 = clients;
    Queue<Client> clients2;  
    client = clients.get_head()->get_dato();
    client3 = client;
    clients2.encolar(clients.get_head()->get_dato());
    int c1=0;
    int c2 = 0;
    while (temp != nullptr)
    {
        temp2 = temp->get_siguiente();
        if (c1 != index-1) {
            client = client3;
            client2 = temp2->get_dato();
            arrival2 = utils.max(client.get_exit_time(), client2.get_arrival_time());
            time_off = arrival2 - client.get_exit_time();
            arrival =arrival2  - client2.get_arrival_time();
            client2.set_waiting_time(arrival);
            client2.set_time_off(time_off);
            client2.set_exit_time(calculate_exit_time(client2));
            client3 = client2;
            clients2.encolar(client2);
            c1++;
        }
        temp = temp->get_siguiente();
        c2++;
    }
    return clients2;
}

int Operation::calculate_exit_time(Client client)
{
    int exit = client.get_arrival_time() + client.get_service_time()  + client.get_time_off() + client.get_waiting_time();
    return exit;
}
void Operation::calculate_summary(Queue<Client>& clients)
{
    float waiting=0;
    float time_off=0;
    float service=0;
    float arrival=0;
    int summary_waiting = 0;
    Node<Client>* temp = clients.get_head();
    while (temp!=nullptr)
    {
        waiting += temp->get_dato().get_waiting_time();
        time_off += temp->get_dato().get_time_off();
        service += temp->get_dato().get_service_time();
        arrival += temp->get_dato().get_time_between_arrival();
        if (temp->get_dato().get_waiting_time() > 0) {
            summary_waiting++;
        }
        temp = temp->get_siguiente();
    }
    waiting /= clients.get_size();
    time_off /= clients.get_size();
    service /= clients.get_size();
    arrival /= clients.get_size();
    cout << "Tiempo promedio de espera: " << waiting << endl;
    cout << "Tiempo promedo de descanso del trabajador: " << time_off << endl;
    cout << "Tiempo promedio de servicio: " << service << endl;
    cout << "Tiempo promedio de entre llegadas: " << arrival << endl;
    cout << "Numero de personas en cola: " << summary_waiting << endl;
}
void Operation::mostrar(Queue<Client> clients)
{
    TextTable table_text('-', '|', '+');
    Node<Client>* temp;
    int cont = 1;
    table_text.add("NO");
    table_text.add("TIEMPO LLEGADA");
    table_text.add("TIEMPO ESPERA");
    table_text.add("TIEMPO NO TRABAJA");
    table_text.add("TIEMPO DE SERVICIO");
    table_text.add("TIEMPO DE SALIDA");
    table_text.add("TIEMPO ENTRE LLEGADA");
    table_text.endOfRow();
    table_text.setAlignment(2, TextTable::Alignment::RIGHT);
    temp = clients.get_head();
    while (temp != nullptr)
    {
        table_text.add(to_string(cont++));
        table_text.add(to_string(temp->get_dato().get_arrival_time()));
        table_text.add(to_string(temp->get_dato().get_waiting_time()));
        table_text.add(to_string(temp->get_dato().get_time_off()));
        table_text.add(to_string(temp->get_dato().get_service_time()));
        table_text.add(to_string(temp->get_dato().get_exit_time()));
        table_text.add(to_string(temp->get_dato().get_time_between_arrival()));
        temp = temp->get_siguiente();
        table_text.endOfRow();
    }
    table_text.setAlignment(2, TextTable::Alignment::RIGHT);
    std::cout << table_text << std::endl;
}

