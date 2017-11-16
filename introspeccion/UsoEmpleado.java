package introspeccion;

public class UsoEmpleado {
	public static void main(String... args) {
		Persona Antonio = new Persona("Antonio");
		System.out.println(Antonio.getNombre());
		Empleado Ana = new Empleado("Ana", 2000);
		System.out.println(Ana.getNombre());
		System.out.println(Ana.getSalario());
		// System.out.println(Antonio.getClass());
		// Class cll = Antonio.getClass();
		// System.out.println(cll.getName());
		
		String nombreClase="introspeccion.Empleado";
		try {
			Class cll1=Class.forName(nombreClase);
			
			System.out.println(cll1.getName());
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	
	
	}
}

class Persona {

	private String nombre;

	public Persona(String nombre) {

		this.nombre = nombre;

	}

	public String getNombre() {
		return nombre;
	}

}

class Empleado extends Persona {

	public Empleado(String nombre, double salario) {
		super(nombre);
		// TODO Auto-generated constructor stub
		this.salario = salario;
	}

	private double salario;

	public void setIncentivo(double incentivo) {
		salario = salario + incentivo;

	}

	public String getSalario() {
		return "El salario es: $" + salario;
	}
}