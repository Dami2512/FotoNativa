Feature: Rendimiento en carga y visualización  
 Como fotógrafo  
 quiero que la plataforma cargue y muestre fotografías en alta resolución sin tiempos de espera excesivos  
 para trabajar de forma fluida.  

Scenario: Carga de fotografía en alta resolución dentro de un tiempo aceptable 
 Given que el fotógrafo se encuentra en la pantalla de carga de imágenes  
 And selecciona una fotografía en alta resolución  
 When presiona el botón "Subir fotografía"  
 Then el sistema completa la carga sin tiempos de espera excesivos  
 And muestra un mensaje de confirmación al finalizar el proceso  

Scenario: Visualización fluida de fotografía en alta resolución  
 Given que una fotografía en alta resolución se encuentra almacenada 
 When el usuario la abre desde su galería  
 Then el sistema muestra la imagen sin demoras excesivas  
 And permite navegar sin interrupciones visibles 
