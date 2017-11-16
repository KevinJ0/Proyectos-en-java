package aplicacion_cambio_nombre;

import java.io.File;
import javax.swing.JFileChooser;

public class CambioNombre {
	private JFileChooser chooser = new JFileChooser();
	private File directory;
	private File[] groupFiles;

	public static void main(String[] args) {
		CambioNombre cambioNombre = new CambioNombre();

		cambioNombre.setDirectory();
		cambioNombre.setAllFile();
		cambioNombre.BeginTheFun();
	}

	void setDirectory() {
		chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		if (chooser.showDialog(null, "Seleccionar") == JFileChooser.APPROVE_OPTION)
			directory = chooser.getSelectedFile();
	}

	void setAllFile() {
		if (directory == null)
			directory = new File(""); // Aqui coloco el directorio manual

		groupFiles = directory.listFiles();
	}

	void BeginTheFun() {
		String newNameFile;
		String nameFile;
		String prefijo;

		for (int i = 0; i < groupFiles.length; i++) {

			nameFile = groupFiles[i].getName().trim();
			prefijo = getNumberToString(nameFile);
			newNameFile = prefijo + " -- " + nameFile;

			File FileRenamed = new File(groupFiles[i].getParent() + "\\" + newNameFile);
			System.out.println("Este es el nuevo nombre>>" + newNameFile);

			RenameFile(FileRenamed, i);
		}
	}

	String getNumberToString(String name) {
		String prefijo;
		int cantLetras = name.length() - 4; // 4 es la extencion, incluye el . 
		int nBegin;

		nBegin = cantLetras - 2;
		prefijo = name.substring(nBegin, cantLetras);
		System.out.println("Este es el numero>>" + prefijo);

		return prefijo;
	}

	void RenameFile(File f, int i) {
		groupFiles[i].renameTo(f);
	}
}
