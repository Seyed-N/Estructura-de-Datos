#seyed nick seyed falah parra
#Clase base: manejo general de archivos
class Archivo:
    def __init__(self, nombre):
        self.nombre = nombre

    def escribir(self, contenido):
        with open(self.nombre, 'a') as f:
            f.write(contenido + '\n')

    def leer(self):
        with open(self.nombre, 'r') as f:
            return f.read()

# Herencia: ArchivoLog hereda de Archivo
class ArchivoLog(Archivo):
    def escribir_log(self, mensaje):
        from datetime import datetime
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        log = f"[{timestamp}] {mensaje}"
        self.escribir(log)

# Agregación: usa objetos Archivo/ArchivoLog
class GestorArchivos:
    def __init__(self):
        self.archivos = []

    def agregar_archivo(self, archivo):
        self.archivos.append(archivo)

    def mostrar_contenidos(self):
        for archivo in self.archivos:
            print(f"Contenido de {archivo.nombre}:")
            print(archivo.leer())

# -----------------------------
# DEMO del funcionamiento

# Creamos un archivo de texto común
archivo1 = Archivo("notas.txt")
archivo1.escribir("Esto es una nota.")
archivo1.escribir("Otra línea de texto.")

# Creamos un archivo de log
log = ArchivoLog("registro.log")
log.escribir_log("Inicio del programa.")
log.escribir_log("Se produjo un error de conexión.")

# Usamos agregación para gestionar varios archivos
gestor = GestorArchivos()
gestor.agregar_archivo(archivo1)
gestor.agregar_archivo(log)

# Mostramos los contenidos
gestor.mostrar_contenidos()