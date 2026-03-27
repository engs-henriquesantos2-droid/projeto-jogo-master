#include <iostream>
#include <string>

using namespace std;

int main() {
    // --- VARIÁVEIS DE ESTADO ---
    string nome;
    int escolha;
    int vida = 100;
    bool temCavalo = false;

    // --- APRESENTAÇÃO ---
    cout << "       MISSAO: O AVISO AO REI            \n";

    cout << "Qual e o seu nome, mensageiro? ";
    cin >> nome;

    cout << "\nOla, " << nome << ". Voce precisa sair do castelo para avisar o Rei sobre a invasao!\n";
    cout << "Escolha sua vantagem inicial:\n";
    cout << "1. Armadura de Ferro (Mais vida)\n";
    cout << "2. Botas de Silencio (Mais furtividade)\n";
    cout << "> ";
    cin >> escolha;

    //  IF/ELSE 
    if (escolha == 1) {
        vida = 130;
        cout << "Voce equipou a armadura. Vida aumentada para 130.\n";
    } else {
        cout << "Voce escolheu as botas. Voce se move sem fazer barulho.\n";
    }

    // --- FASE 1: O PATIO DOS GUARDAS ---
   
    cout << "       FASE 1 - O PATIO INTERNO          \n";
   
    cout << "O portao principal esta guardado. O que voce faz?\n";
    cout << "1. Tentar correr entre os guardas\n";
    cout << "2. Subornar o cavalariço para pegar um cavalo\n";
    cout << "3. Tentar escalar o muro alto\n";
    cout << "> ";
    cin >> escolha;

    // Uso de SWITCH-CASE obrigatório
    switch(escolha) {
        case 1:
            cout << "Os guardas te viram! Voce foi atingido por flechas e perdeu 60 de vida.\n";
            vida = vida - 60;
            break;
        case 2:
            cout << "O cavalariço aceitou suas moedas. Voce agora tem um cavalo!\n";
            temCavalo = true;
            break;
        case 3:
            cout << "Voce escalou o muro, mas caiu do outro lado e se machucou. Perdeu 20 de vida.\n";
            vida = vida - 20;
            break;
        default:
            cout << "Opçao invalida! Voce ficou confuso e os guardas te bateram. Perdeu 30 de vida.\n";
            vida = vida - 30;
    }

    // Verificação de vida após fase 1
    if (vida <= 0) {
        cout << "\nGAME OVER: " << nome << " morreu no patio do castelo.\n";
        return 0;
    }

    // --- FASE 2: A PONTE LEVADIÇA ---
    cout << "       FASE 2 - A PONTE LEVADICA         \n";
   
    cout << "Vida atual: " << vida << "\n";
    cout << "A ponte esta subindo! Como voce vai atravessar?\n";
    cout << "1. Pular no fosso de agua gelada\n";
    cout << "2. Tentar saltar a fenda com tudo\n";
    cout << "> ";
    cin >> escolha;

    if (escolha == 1) {
        cout << "A agua esta congelante e cheia de piranhas! Voce perde 50 de vida.\n";
        vida = vida - 50;
    } else {
        // A consequência aqui muda se você pegou o cavalo na Fase 1
        if (temCavalo) {
            cout << "Com o cavalo, voce salta a fenda com facilidade e sai do castelo ileso!\n";
        } else {
            cout << "A pe, voce nao tem velocidade. Voce cai de mau jeito. Perde 70 de vida.\n";
            vida = vida - 70;
        }
    }

    // Verificação de vida após fase 2
    if (vida <= 0) {
        cout << "\nGAME OVER: Voce nao sobreviveu a travessia da ponte.\n";
        return 0;
    }

    // --- FASE 3: A ESTRADA FINAL (DESFECHO) ---
   
    cout << "       FASE 3 - O CAMINHO PARA O REI     \n";

   
    if (temCavalo && vida > 40) {
        cout << "FINAL EPICO: Voce chegou ao palacio do Rei a galope! O aviso foi dado e o reino salvo!\n";
    } else if (vida > 0) {
        cout << "FINAL Fudido : Voce chegou ao palacio arrastando-se e ferido. O Rei recebeu o aviso, mas a batalha sera dificil.\n";
    }

    cout << "           vlw por jogar galera !           \n";
   
   

    return 0;
}

