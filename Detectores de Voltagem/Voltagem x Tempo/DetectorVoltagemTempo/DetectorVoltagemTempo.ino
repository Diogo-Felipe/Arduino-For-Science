//Programa: Detector de Voltagem Para Um Detector
//Descrição: Detecção Automatizada de Voltagem Para Quantidade Razoavel de Dados(Solução Simplificada)
//Autor: Diogo L.C. Felipe
//Email: Diogomem@outlook.com


/*
 * Para usar o programa:
 * 1. Conecte a placa ao computador
 * 2. Carregue o programa na placa
 * 3. Com a IDE aberta, pressione as telcas Ctrl + Shift + M
 * ---Apos finalização da medida---
 * 4. Copie as informações da tela para um arquivo .txt
 */

int detector = A0; //Definição da porta de detecção

int dados = 18000; //Variável para controle da quantidade de dados

int intervaloEntreMedidas = 400; //Atraso atraso entre duas medidas consecutivas (em milisegundo)

void setup() {
    Serial.begin(9600); //Inicição do monitor onde os dados aparecem
    Serial.println("Segundo Voltagem"); //Primeira linha do monitor

    //Variável que recebe a voltagem
    float voltagem;

    //Loop que conta o numero de medidas
    for(int medida = 0; medida < dados; medida++){
        voltagem = medeVoltagem(detector); //Função que efetivamete realiza a medida de voltagem
        
        //Impressão dos valores na tela separados por alguns espaços
        Serial.print(medida); //'Eixo x' ou 'id' da medida
        Serial.print("        ");
        Serial.println(voltagem); //Valor da medida ('eixo y')

        delay(intervaloEntreMedidas); //Implementação do atraso entre duas medidas consecutivas
    }
}

void loop(){}
