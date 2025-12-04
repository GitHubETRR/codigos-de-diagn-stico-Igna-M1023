from tkinter import *
from tkinter import filedialog as fd
root = Tk()
root.arch_act = None
root.geometry("500x300")
root.title(" Notepad ")

def guardarf():
    if getattr(root, 'arch_act', None): 
        with open(root.arch_act, "w", encoding="utf-8") as file:
            file.write(texto_i.get(1.0, END))
    else:
        archivo_g = fd.asksaveasfilename(defaultextension=".txt", filetypes=[("Archivos de texto", "*.txt")])
        with open(archivo_g, "w", encoding="utf-8") as file:
            file.write(texto_i.get(1.0, END))
        
def abrirf():
    archivo = fd.askopenfilename(filetypes=[("Archivos de texto", "*.txt")])
    with open(archivo, "r", encoding="utf-8") as archivor:
        contenido = archivor.read()
    texto_i.delete(1.0, END)
    texto_i.insert(END, contenido)
    root.arch_act = archivo
    return root.arch_act

barra_t = Frame(root)
barra_t.pack(side=TOP, fill=X)

abrir_b = Button(barra_t, text="Abrir", command=guardarf)
abrir_b.pack(side=LEFT, padx=5, pady=5)
guardar_b = Button(barra_t, text="Guardar", command=guardarf)
guardar_b.pack(side=LEFT, padx=5, pady=5)

texto_i = Text(root, height=15, width=60, bg="light yellow")
texto_i.pack(fill=BOTH, expand=True, padx=5, pady=(0,5))

mainloop()