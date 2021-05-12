**Etapa 6 - Geração de código assembly a partir de código intermediário.**

Alterações em estruturas da etapa anterior consistiram em:
- Adicionar um novo atributo à estrutura Code, para sabermos que tipo de operação está sendo feita em cada instância de código.

O Grupo também optou por ignorar o uso dos infinitos registradores da etapa anterior. Utiliza-se uma pilha na geração do código assembly para guardar os valores das instruções, conforme são utilizados.

