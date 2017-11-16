package introspeccion;

import java.lang.reflect.Constructor;
import java.lang.reflect.Modifier;
import java.util.Scanner;

public class PruebaIntrospeccion {
	public static void main(String... args) {

		Scanner entrada = new Scanner(System.in);
		System.out.println("Introduce el nombre de la clase");
		String nombreClase = entrada.next();
		// imprimir clase y super clase

		try {
			Class cl = Class.forName(nombreClase);
			Class superCl = cl.getSuperclass();
			System.out.println("Clase" + nombreClase);

			if (superCl != null && superCl != Object.class) {
				System.out.println("extends " + superCl.getName());
			}

			System.out.println();
			imprimirConstructores(cl);
			System.out.println();
			// imprimirMetodos(cl);
			System.out.println();
			// imprimirCampos(cl);
			System.out.println();

		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.exit(0);
		}

	}

	public static void imprimirConstructores(Class cl) {

		Constructor[] construtores = cl.getDeclaredConstructors();
		for (Constructor c : construtores) {

			String nombre = c.getName();
			System.out.print("    " + Modifier.toString(c.getModifiers()));
			System.out.print("    " + nombre + " (");
			// imprimi parametro
			Class[] tipoParams = c.getParameterTypes();
			for (int i = 0; i < tipoParams.length; i++) {
				if (i > 0)
					System.out.println(",   ");
				System.out.print(tipoParams[i].getName());
				System.out.println(");");

			}
		}

	}

}
