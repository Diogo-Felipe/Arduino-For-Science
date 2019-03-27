//Programa: Espalimetro
//Autor: Diogo L.C. Felipe
//Email: diogomem@outlook.com

/*
 *  O programa objetiva fazer uma médida simplificada do
 * espalhamento de uma substância qualquer. Para isso, é
 * necessário um laser ou lâmpada colimada da cor que se
 * deseja medir o espalhamento e dois dedectores, um a na
 * mesma linha do laser, depois do laser ter passado pela
 * amostra, e outro a noventa graus do laser em relação à
 * amostra.
 * 
 *  Pelo fenômeno que é estudado, a medida precisa ser fei-
 * ta de forma a conciderar a estatística da medida, portanto
 * durante o programa são feitas várias somas e médias para
 * determinar com melhor precisão estatística o valor real da
 * medida.
 */


//Numero total de medidas para o cálculo de uma média
int numero_de_medidas_total = 5000; //ESTÁ VARIAVEL DEVE SER ALTERADA PARA ATENDER A NECESSIDADE DO ÚSUARIO



//Definição dos Pinos
float detector_90 = A0;
float detector_0 = A1;

//Definição do Valor aquisicionado
float detector_90_valor = 0;
float detector_0_valor = 0;

//Valor corrigido do pino de aquisição
int voltagem_detector_90 = 0;
int voltagem_detector_0 = 0;

//Variaveis do Botão
int bot = 8;
boolean val = 0;

//Variável de calibração (por padrão dever ser falso)
boolean calibrado = false;

//Contagem de medidas para retirada da média
int numero_medidas = 0;

//Variaveis relacionadas a média de cada medida para o calibração do laser
long int soma_calibracao = 0;
float media_calibracao = 0;

//Variaveis relacionadas a média de cada medida para o feixe na direção do laser
long int soma_0 = 0;
float media_0 = 0;

//Variaveis relacionadas a média de cada medida para o feixe perpendicular ao laser
long int soma_90 = 0;
float media_90 = 0;

void setup() {
  //Inicialização do monitor para dados
  Serial.begin(9600);
}

void loop() {
  //Caso o aparato não esteja calibrado
  if(calibrado == false){
    
    //Imprime na tela que o usuario deve espera
    Serial.println("ESPERE, CALIBRACAO EM ANDAMENTO");

    //Loop que soma todas as medidas tiradas para obtenção da media
    while(numero_medidas <= numero_de_medidas_total){

      //Feedback visual do processo de calibração do aparato
      if(numero_medidas == 0){
        Serial.print("Calibracao (%) [");
      } else if (numero_medidas  == numero_de_medidas_total*0.1){
        Serial.print("#");
      } else if (numero_medidas  == numero_de_medidas_total*0.2){
        Serial.print("#");
      } else if (numero_medidas  == numero_de_medidas_total*0.3){
        Serial.print("#");
      } else if (numero_medidas  == numero_de_medidas_total*0.4){
        Serial.print("#");
      } else if (numero_medidas  == numero_de_medidas_total*0.5){
        Serial.print("#");
      } else if (numero_medidas  == numero_de_medidas_total*0.6){
        Serial.print("#");
      } else if (numero_medidas  == numero_de_medidas_total*0.7){
        Serial.print("#");
      } else if (numero_medidas  == numero_de_medidas_total*0.8){
        Serial.print("#");
      } else if (numero_medidas  == numero_de_medidas_total*0.9){
        Serial.print("#");        
      } else if (numero_medidas  == numero_de_medidas_total){
        Serial.print("#");
        Serial.println("]");
      }
      
      //A soma sera o valor acumulado da leitura analogica e corrigida do lazer
      soma_calibracao = soma_calibracao + (analogRead(detector_0))*(5000/1024);
      
      //Delay de 1 milisegundo
      delay(1);
      
      //Incremento da contagem para o loop
      numero_medidas = numero_medidas + 1;
    }

    //Retira a média
    media_calibracao = soma_calibracao / numero_de_medidas_total;

    //Reseta a contagem do número de medidas tiradas
    numero_medidas = 0;
    Serial.println("---------------------------------------");
    Serial.println("APARATO CALIBRADO");
    Serial.print("Valor de cablibracao: ");
    Serial.println(media_calibracao);
    Serial.println("---------------------------------------");
    calibrado = true;
    Serial.println("I-90          I-0            E-90           Ext");

  //Caso o aparato estreja calibrado
  }else{  

    //Após aprertar o botão
    if(digitalRead(bot) == HIGH){

      //Delay de segurança para usuário não interferir na medida
      delay(1000);

      //Loop feito para gerar um número de medidas que o usuário concidere o
      //suficiente para cálculo da média
      while(numero_medidas <= numero_de_medidas_total){

        //Leitura dos valores que chegam aos detectores
        voltagem_detector_90 = analogRead(detector_90);
        voltagem_detector_0 = analogRead(detector_0);

        //Soma aquisicionada e com voltagem corrigida para futuramente adquirir a média
        soma_90 = soma_90 + (voltagem_detector_90)*(5000/1024);
        soma_0 = soma_0 + (voltagem_detector_0)*(5000/1024);

        //Delay usado para fins físicos relacionados a resposta do laser para a flutuação da rede
        delay(1);

        //Necessário para gerar a saída do loop
        numero_medidas = numero_medidas + 1;
      }

      //Cálculo efetivo das médias
      media_0 = soma_0 / numero_de_medidas_total;
      media_90 = soma_90 / numero_de_medidas_total;
      
      Serial.print(media_90);
      Serial.print("        ");
      Serial.print(media_0);
      Serial.print("        ");
      Serial.print(media_90);
      Serial.print("        ");
      Serial.println(media_calibracao - media_0);    

      //Reset de todos os valores de váriaveis de controle
      numero_medidas = 0;
      media_90 = 0;
      media_0 = 0;
      soma_90 = 0;
      soma_0 = 0;
    }

    //Delay para aprimoramento da experiência do usuário
    delay(300);
  }
}
