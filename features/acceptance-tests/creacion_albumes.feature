Feature: Creación de álbumes fotográficos
  Como fotógrafo  
  quiero organizar mis fotografías en álbumes por categoría o proyecto  
  para que mi portafolio luzca ordenado y sea fácil de navegar.  
  
  Scenario: Creación de un nuevo álbum  
    Given que el usuario inició sesión en FotoNativa  
    And se encuentra en la sección de álbumes  
    When crea un nuevo álbum con nombre y descripción  
    Then el sistema registra el álbum correctamente  
    And el álbum queda disponible en su portafolio  
  
  Scenario: Agrupación de fotografías dentro de un álbum  
    Given que el usuario tiene fotografías cargadas  
    And tiene un álbum creado  
    When selecciona fotografías para agregarlas al álbum  
    Then el sistema agrupa las fotografías correctamente  
    And las muestra dentro del álbum seleccionado 
