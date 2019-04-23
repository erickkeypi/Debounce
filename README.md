# Debounce
Libreria de arduino para eliminar el rebote de los botones


## Cómo usar
Se crea una instancia de la clase para cada botón con el pin donde se conecta este y el tiempo en milisegundos utillizado para eliminar el rebote. Si no se especifica un tiempo se toma 20 milisegundos como valor por defecto. 
```
Debounce boton1 = Debounce(pin,tiempo);
Debounce boton2 = Debounce(pin);
...
...
```

En `loop` se debe llamar la función `actualizar`.
```
void loop() {
  boton1.actualizar();
  boton2.actualizar();
}
```

la variable `estado` es la que presenta el estado del boton sin el rebote.

las variables `subida` y `bajada` son verdaderas cuando se presenta un flanco de subida o de bajada respectivamente.

#### Nota: Esta libreria activa la resistencia de pullup del pin usado


## Funciones
```Debounce(pin, tiempo)```
Constructor de la clase.

```void actualizar()```
Actualiza el estado del botón.

## Variables

```boolean estado```
Representa el estado del botón sin rebote.

```boolean subida```
Es verdadera cuando ocurre un flanco de subida.

```boolean bajada```
Es verdadera cuando ocurre un flanco de bajada.


## License
Copyright (c) 2019 Erick R Garcia Martinez.
Licensed under [Apache license, version2.0](LICENSE).
