/*
Copyright 2019 Erick Rafael Garcia Martinez

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef _DEBOUNCE
#define _DEBOUNCE

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class Debounce{

	public:
		bool estado, subida, bajada, presionado, repeticion;

    Debounce(int _pin);

    void begin();
    void beginPullUp();

    void cambiarTiempo(unsigned long _tiempo);
    void cambiarTiempoPresionado(unsigned long _tiempo);
    void cambiarTiempoRepeticion(unsigned long _tiempo);
    void cambiarTriggerPresionado(bool _trigger);

		bool actualizar();

	private:
		unsigned long espera, tiempoRepeticion, tiempoInicioRepeticion;
		bool actual, anterior, repeticionActivada, triggerRepeticion;
		int pin;

};
#endif
