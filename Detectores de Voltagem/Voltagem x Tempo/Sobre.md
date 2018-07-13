Detecção Controlada De Voltagem Vinda da Porta Analógica
========================================================

Os códigos aqui presentes tiveram como objetivo a aquisição de muitos dados durante um periodo controlado de tempo.

Para evitar que o usuário precise procurar no código o local onde os vários parâmentros relevantes para a medida se encontram,
os parâmetros mais relevantes foram extraídos como variáveis globais do programa.

Optou-se pela utilização de variáveis globais ao invés de constantes apenas por uma questão didática para os usuários mais leigos.

### Os diretórios

Os diretórios contém os arquivos do projeto para utilização de um ou dois detectores.

De fato, para um leitor mais atentoé possível notar que cada projeto é apenas uma extenção do
projeto para apenas um detector. Por esse motivo, foi optado por extrair a função que realiza 
a medida para um arquivo separado que é utilizado em todos os códigos.
