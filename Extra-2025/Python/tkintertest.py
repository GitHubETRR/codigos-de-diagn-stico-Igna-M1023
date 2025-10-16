from tkinter import *
from tkinter import filedialog as fd
root = Tk()
root.current_file = None
root.geometry("500x300")
root.title(" Notepad ")

def savef():
    if getattr(root, 'current_file', None):  # check if it exists
        with open(root.current_file, "w", encoding="utf-8") as file:
            file.write(inputtxt.get(1.0, END))
    else:
        savefile = fd.asksaveasfilename(defaultextension=".txt", filetypes=[("Archivos de texto", "*.txt")])
        with open(savefile, "w", encoding="utf-8") as file:
            file.write(inputtxt.get(1.0, END))
        
def openf():
    filename = fd.askopenfilename(filetypes=[("Archivos de texto", "*.txt")])
    with open(filename, "r", encoding="utf-8") as file:
        contenido = file.read()
    inputtxt.delete(1.0, END)
    inputtxt.insert(END, contenido)
    root.current_file = filename 
    return root.current_file

topbar = Frame(root)
topbar.pack(side=TOP, fill=X)

btn = Button(topbar, text="Abrir", command=openf)
btn.pack(side=LEFT, padx=5, pady=5)
btn = Button(topbar, text="Guardar", command=savef)
btn.pack(side=LEFT, padx=5, pady=5)

inputtxt = Text(root, height=15, width=60, bg="light yellow")
inputtxt.pack(fill=BOTH, expand=True, padx=5, pady=(0,5))

mainloop()