Feature: Carga de fotografías sin compresión
  Como fotógrafo
  quiero subir mis fotografías usando el motor Zero-Loss
  para conservar su calidad visual original.

  Scenario: Carga exitosa de fotografía en formato permitido
    Given que el fotógrafo se encuentra en la pantalla de carga de imágenes
    And selecciona una fotografía en formato permitido
    When presiona el botón "Subir fotografía"
    Then el sistema carga la imagen correctamente
    And conserva la resolución original sin aplicar compresión
    
  Scenario: Carga de archivo no permitido
    Given que el fotógrafo se encuentra en la pantalla de carga de imágenes 
    And selecciona un archivo con formato no permitido  
    When intenta subir el archivo a la plataforma  
    Then el sistema rechaza la carga  
    And muestra un mensaje indicando los formatos aceptados 
