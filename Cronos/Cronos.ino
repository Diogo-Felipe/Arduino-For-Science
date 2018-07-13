//Programa: Cronos
//Descrição: Contador de tempo entre a passagem de dois feixes de luz
//Autor: Diogo L.C. Felipe
//Email: Diogomem@outlook.com

/*
Para usar o programa:
1. Conecte a placa ao computador
2. Carregue o programa para a placa
3. Com a IDE aberta, pressione as telcas Ctrl + Shift + M
*/

//Pinos de Detecção
int laserInicio = A0; //Pino de detecção do laser 1
int laserFim = A1; //Pino de detecção do laser 2

//valores Aquisicionados Pelos Pinos
int valorInicio; //Definição do valor aquisicionado do laser 1 (responsável pelo incio da contagem)
int valorFim; //Definição do valor aquisicionado do laser 2 (responsável pelo fim da contagem)

//Variáveis de Calibração
int calibracaoInicio; //Variáveis de calibração do laser 1
int calibracaoFim; //Variáveis de calibração do laser 2
boolean aparatoCalibrado = false; //Variável de verificação da calibação

int botao = 8; //Definição da porta do botão

float tempo;//Variável que conta o tempo (a menos do clock do arduino. Veja o texto de apoio)

void setup() {
    abertura();
}

void loop(){
    calibraAparato();//Função que calibra o aparato
  
    //Verificação da calibração do aparato (Sem verificar o estado do botão)
    if(aparatoCalibrado){
        medeTempo();//Função que mede efetivamente o tempo

        saidaDeDados(); //Impressão do tempo para o usuário

        Serial.println("Aperte o botao para calibrar o sistema");
        aparatoCalibrado = false;
    }
}
