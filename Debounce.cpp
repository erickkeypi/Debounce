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

#include "Debounce.h"

Debounce::Debounce(int _pin){
	pin = _pin;
	espera = 20;
	tiempo = 0;
	pinMode(pin,INPUT_PULLUP);
	anterior = true;
	actual = true;
	estado = true;
	subida = false;
	bajada = false;
}

Debounce::Debounce(int _pin, unsigned long _tiempo){
	pin = _pin;
	espera = _tiempo;
	tiempo = 0;
	pinMode(pin,INPUT_PULLUP);
	anterior = true;
	actual = true;
	estado = true;
	subida = false;
	bajada = false;
}

bool Debounce::actualizar(){

	actual = digitalRead(pin);

	if(anterior != actual){
		tiempo = millis();
	}

	if(millis()>espera + tiempo){
		subida = !estado && actual;
		bajada = estado && !actual;
		estado = actual;
	}

	anterior = actual;
	return estado;
}
