


void abertura(){
    Serial.begin(9600); //Iniciaçização do monitor de dados
    Serial.println("**************************");
    Serial.println("**        CRONOS        **");
    Serial.println("**   Laser Time Meter   **");
    Serial.println("**************************");
    Serial.println("");
    Serial.println("Aperte o botao para calibrar o sistema");
}

float saidaDeDados(){
    Serial.println("**************************************");
    Serial.print("    Seu tempo foi de: ");
    Serial.print(tempo);
    Serial.println(" segundos        "); 
    Serial.println("**************************************");
}

float medeTempo(){
     
     valorInicio = analogRead(laserInicio); //Lê o valor do laser 1
     
    //Condição para inicio da contagem (Se o valor lido no laser 1 for menor que a calibração dimiduida de um valor de '16', faça:)
    if(valorInicio < calibracaoInicio - 16){
      
        //Loop de contagem (Enquanto o valor lido no laser 2 for menor que a calibração dimiduida de um valor de '16', faça:)
        while(valorFim >= calibracaoFim - 16){
            tempo = tempo + 0.01; //Contagem do tempo a cada centicegundo
          
            valorFim = analogRead(laserFim); //Deteção continua do valor do laser 2
            
            delay(10); //Delay de 1 centisegundo
        }
    }
}

void calibraAparato(){
    //Verificação do estado de calibração do aparato
    if(digitalRead(botao) == HIGH){
    
        //Calibração efetivamente (Modelo simplificado)
        calibracaoInicio = analogRead(laserInicio);
        calibracaoFim = analogRead(laserFim);
        
        delay(300); //Delay para melhorar a experiência do usuario
    
        aparatoCalibrado = true; //Identifica o aparato como calibrado
        
        tempo = 0; //Zera a variável que conta o tempo
        
        Serial.println("Aparato Devidadamente Calibrado.");
    } 
}



