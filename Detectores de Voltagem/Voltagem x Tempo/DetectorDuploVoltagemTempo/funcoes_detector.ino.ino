//Função que realiza medida de voltagem instantânea
float medeVoltagem(int porta){
    
    float detectorValor = 0; //Variável para aquisição do valor
    float voltagemCorrigida = 0; //Valor corrigido e fornecido ao usuário (em milivolt)

    detectorValor = analogRead(porta); //Aquisição do sinal
    voltagemCorrigida = (detectorValor)*(5000.00/1024.00); //Correção para a escala real de voltagem (milivolt)

    return voltagemCorrigida; //Retorno da voltagem corrigida
}
