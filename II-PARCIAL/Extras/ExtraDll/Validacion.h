#ifdef VALIDACION_EXPORTS
#define VALIDACION_API __declspec(dllexport)
#else
#define VALIDACION_API __declspec(dllimport)
#endif

/**
 * @brief  En C ++, cuando se usa con una cadena, externespecifica que las convenciones de enlace de otro 
 idioma se están usando para los declaradores.
 Se puede acceder a las funciones y datos de C solo si se declararon previamente que tienen un enlace de C
 * 
 * @param msj 
 * @return Retorna el numero a guardar
 */
extern "C" {
	VALIDACION_API int ingresar(const char* msj);
}
