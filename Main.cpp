#include <iostream>
#include <string>
#include <locale> // Para cambiar el idioma
#include "Text.h" // Aquí tengo todos los texos que necesito para la historia
#include <queue> // Voy a usar un queue para guardar las decisiones que va tomando el jugador
#include <Windows.h>
#include <conio.h>

	// Clase base para cualquiera de los textos

	class Texto 
	{
	public:
		Texto(std::string _texto);
		virtual int MostrarTexto();
	private:
		std::string texto;
	};

	Texto::Texto(std::string _texto)
	{
		texto = _texto;
	}

	int Texto::MostrarTexto()
	{
		std::system("CLS");
		std::cout << texto << std::endl << std::endl;
		return 0;
	}

	// Clase para los textos de interacción

	class Interaccion : public Texto
	{
	public:
		Interaccion(std::string _texto);
		int MostrarTexto();

	private:
	};

	Interaccion::Interaccion(std::string _texto) : Texto(_texto){}

	int Interaccion::MostrarTexto()
	{
		Texto::MostrarTexto();

		int respuesta;

		std::cin >> respuesta;

		return respuesta;
	}

	int CrearMostrarQueueInteraccion(Interaccion* &interaccionActual, std::string texto, std::queue<int> &respuestas)
	{
		int respuestaActual;
		interaccionActual = new Interaccion(texto);
		respuestaActual = interaccionActual->MostrarTexto(); 
		respuestas.push(respuestaActual); // Agrega la respuesta actual al queue

		return respuestaActual;

	}

	
	// Clase para los textos de consecuencias

	class Consecuencia : public Texto
	{
	public:
		Consecuencia(std::string _texto);
		int MostrarTexto();

	private:
	};

	Consecuencia::Consecuencia(std::string _texto) : Texto(_texto){}

	int Consecuencia::MostrarTexto()
	{
		Texto::MostrarTexto();

		_getch();

		return 0;
	}

	void CrearMostrarConsecuencia(Consecuencia* &consecuenciaActual, std::string texto) 
	{
		consecuenciaActual = new Consecuencia(texto);
		consecuenciaActual->MostrarTexto();
	}

int main()
{
	setlocale(LC_ALL, "spanish");

	std::queue<int> respuestas; // Aquí guardaré todas las respuestas numéricas de las interacciones (Las decisiones en la historia)

	Interaccion* interaccionActual = NULL; // Para crear instancias de Interaccion
	Consecuencia* consecuenciaActual = NULL; // Para crear instancias de Consecuencia

	int vida = 100; 

	
	// Interacción 1
	std::string nombreJugador;
	std::cout << interaccion1 << std::endl << std::endl;
	std::getline(std::cin, nombreJugador);

	std::system("CLS");
	std::cout << "Muy bien.¡Suerte en tu aventura, " << nombreJugador;
	std::cin.get();

	// Interacción 2
	int respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion2, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_2);
			goto end; // Aquí el usuario llegó a un final
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_2);
	}
	
	if (vida <= 0) goto end;

	// Interacción 3
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion3, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_3);
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_3);
		goto end; // Aquí el usuario llegó a un final
	}
	
	if (vida <= 0) goto end;

	// Interacción 4
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion4, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_4);
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_4);
		vida = vida - 20;
	}

	if (vida <= 0) goto end;

	// Interacción 5
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion5, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_5);
		vida = vida - 30;
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_5);
	}

	if (vida <= 0) goto end;

	// Interacción 6
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion6, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_6);
		vida = vida - 30;
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_6);
	}

	if (vida <= 0) goto end;

	// Interacción 7
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion7, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_7);
		vida = vida - 10;
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_7);
	}

	if (vida <= 0) goto end;

	// Interacción 8
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion8, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_8);
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_8);
		goto end;
	}

	if (vida <= 0) goto end;

	// Interacción 9
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion9, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_9);
		vida = vida - 40;
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_9);
	}

	if (vida <= 0) goto end;

	// Interacción 10
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion10, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_10);
	}

	if (respuestaActual == 2)
	{
		goto torito;
	}

	if (vida <= 0) goto end;

	// Interacción 12
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion12, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_12);
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_12);
		goto end;
	}

	if (vida <= 0) goto end;

	// Interacción 13
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion13, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_13);
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_13);
		vida = vida - 20;
	}

	if (vida <= 0) goto end;

	// Interacción 14
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion14, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_14);
		goto end;
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_14);
	}

	if (vida <= 0) goto end;

	// Interacción 15
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion15, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_15);
		goto end;
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_15);
	}

	if (vida <= 0) goto end;

	// Interacción 16
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion16, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_16);
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_16);
		vida = vida - 30;
	}

	if (vida <= 0) goto end;

	// Interacción 17
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion17, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_17);
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_17);
		vida = vida - 20;
	}

	if (vida <= 0) goto end;

	// Interacción 18
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion18, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_18);
		goto end;
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_18);
	}

	if (vida <= 0) goto end;

	// Interacción 19
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion19, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_19);
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_19);
		goto end;
	}

	if (vida <= 0) goto end;

	// Interacción 20
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion20, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_20);
		goto win;
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_20);
		goto win;
	}

	if (vida <= 0) goto end;

torito:

	// Interacción 11
	respuestaActual = CrearMostrarQueueInteraccion(interaccionActual, interaccion11, respuestas);

	if (respuestaActual == 1)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia1_11);
	}

	if (respuestaActual == 2)
	{
		CrearMostrarConsecuencia(consecuenciaActual, consecuencia2_11);
	}


end:

	std::cout << "Perdiste ¡Gracias por jugar!";

win:

	std::cout << "Ganaste ¡Felicidades!";

	delete interaccionActual;
	delete consecuenciaActual;
}