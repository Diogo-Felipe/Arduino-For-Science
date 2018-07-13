//Programa: Detector de Voltagem Para Dois Detectores
//Descrição: Detecção semi-manual de voltagem para dois detectores (Solução Simplificada)
//Autor: Diogo L.C. Felipe
//Email: Diogomem@outlook.com

/*
Este programa é uma generalização do programa usado para um único
detecror. Dito isso, sinta-se livre para verificar o funcionamento e 
expanidir para a quantidade de dectores que operam em seu projeto.
*/

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

//Definição das Portas de Aquisição
int detector1 = A0;
int detector2 = A1;

float medida = 0; //Variável para contagem do numero de medidas (corresponde ao id)

float passo = 1; //Variável indicativa do quanto o 'eixo x' cresce a cada medida

int botao = 8; //Definição da porta do botão

void setup() {
  Serial.begin(9600); //Iniciaçização do monitor de dados
  Serial.println("Medida Voltagem_1 Voltagem_2"); //Primeira linha do programa
}

void loop() {

  float voltagem1;
  float voltagem2;

  //Verificação do estado do botão para poder realizar a medida
  if(digitalRead(botao) == HIGH){

    delay(300); //Delay que impede contaminação na medida devido as caracteristicas do aparato (Consulte o texto de apoio) (IMPORTANTE)

    //Funções que efetivamente realizam a medida
    voltagem1 = medeVoltagem(detector1);
    voltagem2 = medeVoltagem(detector2);
    
    //Impressão na tela dos valores separados por alguns espaços
    Serial.print(medida); //'Eixo x' ou 'id' da medida
    Serial.print("        ");
    Serial.print(voltagem1); //Valor da medida do primeiro detectot ('eixo yA')
    Serial.print("        ");
    Serial.println(voltagem2); //Valor da medida do primeiro detectot ('eixo yB')
     
    medida = medida + passo; //Incremento da variável de contagem da medida ('eixo x' ou 'id')  
  }
  delay(300); //Delay para melhorar a experiência do usuário (IMPORTANTE)
}
