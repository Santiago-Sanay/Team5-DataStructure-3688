#ifdef VALIDACION_EXPORTS
#define VALIDACION_API __declspec(dllexport)
#else
#define VALIDACION_API __declspec(dllimport)
#endif

/**
 * @brief Permite solo el ingreso de numeros, discriminando letras e inclusive teclas adicionales
 * 
 * @param msj 
 * @return int  El numero Ingresado
 */
extern "C" {
	VALIDACION_API int ingresar(const char* msj);
}
