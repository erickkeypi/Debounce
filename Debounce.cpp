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
}

void Debounce::begin(){
	// espera = _tiempo;
	espera = 20;
	pinMode(pin,INPUT);
	anterior = actual =	estado = subida = bajada = repeticionActivada =  false;
	tiempoInicioRepeticion = 1000;
	tiempoRepeticion = 100;
	triggerRepeticion = true;
}

void Debounce::beginPullUp(){
	begin();
	pinMode(pin,INPUT_PULLUP);
}

void Debounce::cambiarTiempo(unsigned long _tiempo){
	espera = _tiempo;
}

void Debounce::cambiarTiempoPresionado(unsigned long _tiempo){
	tiempoInicioRepeticion = _tiempo;
}

void Debounce::cambiarTiempoRepeticion(unsigned long _tiempo){
	tiempoRepeticion = _tiempo;
}

void Debounce::cambiarTriggerPresionado(bool _trigger){
	triggerRepeticion = _trigger;
}
bool Debounce::actualizar(){

	static unsigned long tiempo = millis();

	actual = digitalRead(pin);

	if(anterior != actual){
		tiempo = millis();
	}

	if(millis()-tiempo > espera){
		subida = !estado && actual;
		bajada = estado && !actual;
		estado = actual;
	}

	if((estado == triggerRepeticion) && (millis() - tiempo > tiempoInicioRepeticion)){
		presionado = true;
		repeticionActivada = true;
	}else{
		presionado = false;
	}

	if(presionado){
		static unsigned long t = 0;
		if(millis() - t>tiempoRepeticion){
			repeticion = true;
			t=millis();
		}
		else{
			repeticion = false;
		}

	}

	anterior = actual;


	return estado;
}
