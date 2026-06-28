Feature: Compatibilidad multidispositivo  
  Como usuario  
  quiero visualizar mis fotografías correctamente desde computadora, tablet 		o celular  
  para acceder a mi portafolio desde cualquier dispositivo.  
  Scenario Outline: Visualización correcta según dispositivo  
    Given que el usuario accede a FotoNativa desde un dispositivo 
    And abre una fotografía almacenada en alta resolución  
    When visualiza la imagen desde la galería  
    Then el sistema muestra la fotografía correctamente  
    And la imagen no presenta distorsiones visuales 
