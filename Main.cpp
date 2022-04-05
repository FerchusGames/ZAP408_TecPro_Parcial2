#include <iostream>
#include <string>

	class Texto // Clase base para cualquiera de los textos
	{
	public:
		Texto(std::string _texto);
		virtual void MostrarTexto();
	private:
		std::string texto;
	};

	Texto::Texto(std::string _texto)
	{
		texto = _texto;
	}

	void Texto::MostrarTexto()
	{
		std::cout << texto << std::endl << std::endl;
	}

	class Decision
	{
	public:
		Decision();

	private:
		std::string texto;
		std::string opcion1;
		std::string opcion2;
	};

	class Consecuencia
	{
	public:
		Consecuencia();

	private:

	};

	Consecuencia::Consecuencia()
	{
	}


	Decision::Decision()
	{

	}

int main()
{
	bool enProgreso;	// La historia no se ha acabado
	bool estaVivo;		// El personaje del jugador sigue con vida 

	Texto test("Hola");
	test.MostrarTexto();
}