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

double tempo;//Variável que conta o tempo (a menos do clock do arduino. Veja o texto de apoio)

void setup() {
    Serial.begin(9600); //Iniciaçização do monitor de dados
    Serial.println("**************************");
    Serial.println("**        CRONOS        **");
    Serial.println("**   Laser Time Meter   **");
    Serial.println("**************************");
    Serial.println("");
    Serial.println("Aperte o botao para calibrar o sistema");
    Serial.println("");
}

void loop(){

    //Verificação do estado de calibração do aparato
    if(digitalRead(botao) == HIGH){
    
        //Calibração efetivamente (Modelo simplificado)
        calibracaoInicio = analogRead(laserInicio);
        calibracaoFim = analogRead(laserFim);
        
        delay(300); //Delay para melhorar a experiência do usuario
    
        aparatoCalibrado = true; //Identifica o aparato como calibrado
        
        tempo = 0; //Zera a variável que conta o tempo
        
        Serial.println("Aparato Devidadamente Calibrado.");
        Serial.println("");
    }
  
    //Verificação da calibração do aparato (Sem verificar o estado do botão)
    if(aparatoCalibrado){
      
    valorInicio = analogRead(laserInicio); //Lê o valor do laser 1
    
        //Condição para inicio da contagem (Se o valor lido no laser 1 for menor que a calibração dimiduida de um valor de '16', faça:)
        if(valorInicio < calibracaoInicio - 16){
    
            //Loop de contagem (Enquanto o valor lido no laser 2 for menor que a calibração dimiduida de um valor de '16', faça:)
            while(analogRead(laserFim) >= calibracaoFim - 16){
                tempo = tempo + 0.01; //Contagem do tempo a cada centicegundo
                    
                delay(10); //Delay de 1 centisegundo
            }

            Serial.println("**************************************");
            Serial.print("    Seu tempo foi de: ");
            Serial.print(tempo);
            Serial.println(" segundos        "); 
            Serial.println("**************************************");
            Serial.println("");

            Serial.println("Aperte o botao para calibrar o sistema");
            Serial.println("");
            aparatoCalibrado = false;
        }
    }
}
