Feature: Visualización de fotografías en alta resolución  
  Como fotógrafo  
  quiero que mis fotos se muestren en alta resolución  
  para que clientes y seguidores aprecien el detalle y calidad real de mi 	trabajo.  
  
  Scenario: Visualización correcta de una fotografía almacenada  
    Given que una fotografía fue cargada correctamente en FotoNativa  
    And se encuentra almacenada en la galería del usuario  
    When el usuario abre la fotografía desde su portafolio  
    Then el sistema muestra la imagen en alta resolución  
    And la fotografía se visualiza sin distorsiones ni pérdida visible de nitidez  
  
  Scenario: Comparación entre imagen original e imagen visualizada  
    Given que el fotógrafo cargó una imagen en calidad original  
    And la imagen se encuentra disponible en su galería  
    When el usuario compara la imagen visualizada con el archivo original  
    Then no debe evidenciarse pérdida de nitidez  
    And no debe observarse reducción visible de calidad 
