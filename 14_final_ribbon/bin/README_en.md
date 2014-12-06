# Ferramentas

## MODES

These options change the mouse function and the shape visualization. The app starts in **DRAW** mode by default. All modes but **DRAW** change the visualization to 3D.

* **DRAW**: Free drawing tool. Shapes are displayed as vector, without any 3D rendering.

* **CAMERA**: Set the visualization mode to 3D. The mouse functions enabled in this mode are:

	* mouse drag: rotate camera
	* ALT + mouse drag: pan
	* CTRL + mouse mouse drag: zoom

* **REPULSION**: Repels the shapes with the mouse. The area and strength of the repulsion are set by the options **FORCE RADIUS** and **FORCE STRENGTH**.

* **ATTRACTION**: Attracts the shapes with the mouse. The area and strength of the repulsion are set by the options **FORCE RADIUS** and **FORCE STRENGTH**.

* **WIND**: Faz o mouse atrair as formas desenhadas. A área e força de repulsão podem ser controladas com as opções **FORCE RADIUS** e **FORCE STRENGTH**.


## SHAPES

* **APPLY SMOOTHING**: Suaviza as curvas do desenho. Você pode desfazer essa ação usando o botão **RESET SHAPES**.

* **RESET SHAPES**: Retorna as formas para o desenho original, desde que elas não tenham sido apagadas com a **ERASE SHAPES**. Desfaz tanto ações de transformação (**APPLY SMOOTHING**), quanto efeitos 3D.
 
* **ERASE SHAPES**: Apaga todas as formas desenhadas. Essa ação não pode ser desfeita.


## 3D

As alterações desse menu só são visíveis quando as formas estão sendo visualizadas em 3D — ou seja, quando

* **THICKNESS**: Altera a largura da fita.

* **DEPTH**: Altera a profundidade (z) dos pontos da fita, na sequência em que foram desenhados. Pontos desenhados no fim de uma forma parecerão mais próximos que pontos desenhados no começo.

* **COLOR**: Altera a mistura de **RED**, **GREEN** e **BLUE** das formas.


## REPULSION/ATTRACTION

Essas opções são habilitadas apenas nos modos **REPULSION** e **ATRACTION**.

* **FORCE RADIUS**: Altera a área de influência da força aplicada.

* **FORCE STRENGTH**: Altera a intensidade da força aplicada.


## OSCILLATION

Essas opções não são visíveis no modo **DRAW**.

* **OSCILLATE**: Aciona a animação de oscilação das formas. 

* **AMPLITUDE**: Altera a amplitude da onda de oscilação.

* **FREQUENCY**: Altera a frequência de oscilação.

* **LENGTH**: Altera o comprimento de onda da oscilação.


## VIDEO

* **PLAYBACK**: Controla o quanto do desenho é exibido Desenha a forma linha a linha. Só funciona quando fora do modo **DRAW**.

* **TAKE SNAPSHOT**: Salva a visualização atual como uma imagem, com fundo transparente e em formato tif.

* **RECORD SEQUENCE**: Salva a visualização atual como uma sequência de imagens, com fundo transparente e em formato tif. Essa opção pode ser utilizada em conjunto com os modos 3D ou **PLAYBACK** para criar uma animação, por exemplo.