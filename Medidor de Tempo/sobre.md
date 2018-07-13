Medidor de Tempo entre Lasers
========================================================

Esse programa foi criado para medir o tempo que uma esfera metálica demorava para 
cruzar a distância entre dois lasers.

Aqui foi optado por extrair as funções para um arquivo separado no intuito de facilitar
a visualização e indetificação do objetivo de cada parte do codigo.

Foram feitas considerações a respeito da precisão do arduino uno para essa medida e chegou-se
a conclusão que para tempos de ordem maior que 10ms, não há nenhuma perda de precisão. Para tempos
menores que isso, o máximo supertado pelo programa é 1ms e não foi possível determinar se é viável
fazer medidas com intervalos tão curtos.
