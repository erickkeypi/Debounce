# Debounce
Librería para eliminar el rebote de los botones, además de detectar los flancos de subida, bajada y si el botón se deja presionado por un tiempo.


## Cómo usar
Se crea una instancia de la clase para cada botón con el pin donde se conecta este. El tiempo por defecto para eliminar el rebote es de 20 milisegundos y puede ser cambiado.
```
Debounce boton1(pin);//20 ms por defecto
Debounce boton2 = Debounce(pin); //20 ms por defecto
...
...
```
En `setup` se debe llamar la función `begin()` o `beginPullUp()`.
```
void setup() {
  boton1.begin();
  boton2.beginPullUp();
}
```
En `loop` se debe llamar la función `actualizar`.
```
void loop() {
  boton1.actualizar();
  boton2.actualizar();
}
```
## Variables

```boolean estado```
Representa el estado del botón sin rebote.

```boolean subida```
Es verdadera cuando ocurre un flanco de subida.

```boolean bajada```
Es verdadera cuando ocurre un flanco de bajada.

```boolean presionado```
Es verdadera cuando el botón ha quedado en un estado específico luego de un tiempo específico. Este estado y tiempo específicos pueden cambiarse utilizando las funciones: `cambiarTiempoPresionado()` y `cambiarTriggerPresionado()`.

```boolean repeticion```
Cuando `presionado` es verdadero, esta variable cambia su valor a verdadero y luego inmediatamente a falso siguiendo intervalo de tiempos específicos. Estos intervalos de tiempo pueden cambiarse usando la función `cambiarTiempoRepeticion()`

## Funciones

```Debounce(pin, tiempo)```
Constructor de la clase.

```void actualizar()```
Actualiza el estado del botón.




## License
Copyright (c) 2019 Erick R Garcia Martinez.
Licensed under [Apache license, version2.0](LICENSE).
