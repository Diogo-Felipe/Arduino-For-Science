//Programa: Detector de Voltagem Para Dois Detectores
//Descrição: Detecção Automatizada de Voltagem Para Quantidade Razoavel de Dados(Solução Simplificada)
//Autor: Diogo L.C. Felipe
//Email: Diogomem@outlook.com

/*
 * Este programa é uma generalização do programa usado para um único
 * detecror. Dito isso, sinta-se livre para verificar o funcionamento e 
 * expanidir para a quantidade de dectores que operam em seu projeto.
 */

/*
 * Para usar o programa:
 * 1. Conecte a placa ao computador
 * 2. Carregue o programa na placa
 * 3. Com a IDE aberta, pressione as telcas Ctrl + Shift + M
 * ---Apos finalização da medida---
 * 4. Copie as informações da tela para um arquivo .txt
 */

//Definição das Portas de Aquisição
int primeiroDetector = A0;
int segundoDetector = A1;

int dados = 18000; //Variável para controle da quantidade de dados

int intervaloEntreMedidas = 1; //Atraso atraso entre duas medidas consecutivas (em milisegundo)

void setup(){

    Serial.begin(9600); //Inicição do monitor onde os dados aparecem
    Serial.println("Segundo Voltagem1 Voltagem2"); //Primeira linha do monitor

    //Variáveis que recebem a voltagem
    float voltagem1;
    float voltagem2;

    //Loop que conta o numero de medidas
    for(int medida = 0; medida < dados; medida++){

        voltagem1 = medeVoltagem(primeiroDetector);
        voltagem2 = medeVoltagem(segundoDetector);

        //Impressão na tela dos valores separados por alguns espaços
        Serial.print(medida); //'Eixo x' ou 'id' da medida
        Serial.print("        ");
        Serial.print(voltagem1); //Valor da medida do primeiro detectot ('eixo yA')
        Serial.print("        ");
        Serial.println(voltagem2); //Valor da medida do primeiro detectot ('eixo yA')

        delay(intervaloEntreMedidas); //Implementação do atraso entre duas medidas consecutivas
    }
}

void loop(){}
