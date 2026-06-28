Feature: Construcción de portafolio personalizable  
 Como fotógrafo profesional  
 quiero armar un portafolio digital con galerías y diseño propio  
 para presentar mi trabajo de manera visualmente atractiva a clientes potenciales.  
 
 Scenario: Creación de portafolio con plantilla visual  
   Given que el usuario accede al constructor de portafolio  
   And tiene fotografías cargadas en su cuenta  
   When selecciona fotografías y una plantilla visual  
   Then el sistema genera un portafolio personalizado  
   And muestra una vista previa del resultado final  
   
 Scenario: Modificación del orden de fotografías  
   Given que el fotógrafo tiene un portafolio creado  
   And desea cambiar el orden de sus fotografías  
   When reorganiza las imágenes y guarda los cambios  
   Then el sistema actualiza el portafolio And muestra las fotografías en el 	orden seleccionado 
