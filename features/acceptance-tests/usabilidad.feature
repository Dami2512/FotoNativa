Feature: Usabilidad del flujo principal
  Como fotógrafo
  quiero que el flujo de carga, organización y publicación sea claro e intuitivo 
  para gestionar mi portafolio sin dificultad.  
  
  Scenario: Uso claro del flujo de carga y organización  
    Given que el fotógrafo ingresa a la plataforma  
    And desea cargar y organizar sus fotografías  
    When utiliza las opciones de carga, álbumes y portafolio  
    Then el sistema presenta un flujo claro e intuitivo  
    And el usuario puede completar la tarea sin requerir ayuda externa 
    
  Scenario: Identificación clara de acciones principales  
    Given que el usuario se encuentra en el panel principal de FotoNativa  
    When desea cargar, organizar o publicar fotografías  
    Then el sistema muestra opciones visibles y comprensibles  
    And permite continuar el proceso sin confusión 
