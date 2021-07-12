package ec.edu.espe.Dll;
import com.sun.jna.Library;
import com.sun.jna.Native;
import java.util.Scanner;
/**
 *
 * @author TEAM5-3688
 */
public class Main {
   // Char * = String en Java
public interface DLLLibrary extends Library {
    DLLLibrary INSTANCE = (DLLLibrary)
            Native.load("ExtraDll",
                    DLLLibrary.class);
    int ingresar(String str);
}

public static void main(String[] args) {
    Scanner scanner= new Scanner(System.in);
    try {
        char opt=0;
        do{
            int value = DLLLibrary.INSTANCE.ingresar("Ingrese un numero: ");
            System.out.println("\nValor ingresado: " + value + "\n\n");
            System.out.print("Desea continuar validando S/N ??:");
            opt=scanner.next().charAt(0);   
        }
        while(opt=='S'||opt=='s');
    } catch (Exception e) {
        e.printStackTrace();
    }
}

}