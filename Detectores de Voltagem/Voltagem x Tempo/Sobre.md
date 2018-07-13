Detecção Controlada De Voltagem Vinda da Porta Analógica
========================================================

Os códigos aqui presentes tiveram como objetivo a aquisição controlada da intensidade de um laser ao passar por uma amostra
por meio de um fotodetector através de um botão.

Uma vez que a intensidade registrada pelo arduino é apenas a intensidade de um instante experimentalmente, para a medida aplicada,
infinitesimal, foi necessário avaliar o comportamento médio da intensidade do laser para cada mudança na amostra. Então é possível ver
no aquivo de funções (.ino) que temos tanto uma medida instantânea quanto a média das medidas retiradas.

Para evitar que o usuário precise procurar no código o local onde os vários parâmentros relevantes para a medida se encontram,
os parâmetros mais relevantes foram extraídos como variáveis globais do programa.

Optou-se pela utilização de variáveis globais ao invés de constantes apenas por uma questão didática para os usuários mais leigos.
