//Função que realiza medida de voltagem instantânea
float voltagemInstantanea(int porta){
    
    float detectorValor = 0; //Variável para aquisição do valor
    float voltagemCorrigida = 0; //Valor corrigido e fornecido ao usuário (em milivolt)

    detectorValor = analogRead(porta); //Aquisição do sinal
    voltagemCorrigida = (detectorValor)*(5000.00/1024.00); //Correção para a escala real de voltagem (milivolt)

    return voltagemCorrigida; //Retorno da voltagem corrigida
}

//Função que calcula a média no tempo para fornecer um valor médio da medida
float medeVoltagem(int porta){
  
    int qtd = 10; //Quantidade de medidas instantâneas para se caulcular a média

    int intervalo = 10; //Atraso atraso entre duas medidas instantâneas consecutivas(em milisegundo)
    
    float voltagemAcumulada = 0; //Variavél logica que acumula as voltagens instantâneas
    
    float media = 0; //Variável da média

    //Acumulação das voltagens
    for (int medida = 0; medida < qtd; medida++){
         voltagemAcumulada = voltagemAcumulada + voltagemInstantanea(porta); 
         delay(intervalo); //Implementação do intervalo
    }
    
    media = voltagemAcumulada / qtd; //Calculo da média

    return media; //Retono da média
}

