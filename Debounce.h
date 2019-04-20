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
		bool estado;
		bool subida;
		bool bajada;

		Debounce(int _pin);
		Debounce(int _pin, unsigned long _tiempo);
		bool actualizar();

	private:
		float tiempo;
		int espera;
		bool actual;
		bool anterior;
		int pin;

};
#endif
