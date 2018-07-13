//Programa: Detector de Voltagem Para Um Detector
//Descrição: Detecção semi-manual de voltagem (Solução Simplificada)
//Autor: Diogo L.C. Felipe
//Email: Diogomem@outlook.com

/*
Para usar o programa:
1. Conecte a placa ao computador
2. Carregue o programa
3. Com a IDE aberta, pressione as telcas Ctrl + Shift + M
4. Aperte o botão para cada medida que deseja fazer
---Apos finalização da medida---
5. Copie as informações da tela para um arquivo .txt
*/

/*
------------------------AVISO IMPORTATE------------------------
Como estamos trabalhado com o monitor de dados da própria IDE,
NÃO HÁ FORMAS DE APAGAR UM DADO OU VOLTAR UMA MEDIDA. Atente-se
para não errar o momento de apertar o botão em uma medida longa
com o intuito de evitar erros indesejados
---------------------------------------------------------------
*/

int detector = A0; //Definição da porta de detecção

int botao = 8; //Definição da porta do botão

int medida = 0; //Variável para contagem do numero de medidas (corresponde ao id)

int passo = 1; //Variável indicativa do quanto o 'eixo x' cresce a cada medida

void setup(){
    Serial.begin(9600); //Iniciaçização do monitor de dados
    Serial.println("Medida Voltagem"); //Primeira linha do programa
}

void loop(){
    float voltagem;

    //Verificação do estado do botão para poder realizar a medida
    if(digitalRead(botao) == HIGH){
      
        delay(300); //Delay que impede contaminação na medida devido as caracteristicas do aparato (Consulte o texto de apoio) (IMPORTANTE)
        
        voltagem = medeVoltagem(detector);//Função que efetivamente realiza a medida
        
        //Impressão dos valores na tela separados por alguns espaços
        Serial.print(medida); //'Eixo x' ou 'id' da medida
        Serial.print("        ");
        Serial.println(voltagem); //Valor da medida ('eixo y')
    
        medida = medida + passo; //Incremento da variável de contagem da medida ('eixo x' ou 'id')   
    }
    delay(300); //Delay para melhorar a experiência do usuário (IMPORTANTE)
}
