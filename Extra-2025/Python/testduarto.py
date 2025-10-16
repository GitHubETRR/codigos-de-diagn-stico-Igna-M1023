import random
import string

def Generar_contraseña(longitud = 12):
    caracteres = string.ascii_letters + string.digits + string.punctuation
    contrasena = "".join(random.choice(caracteres) for _ in range(longitud))
    return contrasena

print("tu contraseña aleatoria es: ")
print(Generar_contraseña(16))