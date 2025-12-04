import customtkinter
import json
import os
from tkinter import messagebox

## AÑADIRLE FUNCIONES, INGRESAR TRANSACCION, GENERAR GRAFICO, GUARDAR EN ARCHIVO, METER VECTORES LISTAS
## https://stackoverflow.com/questions/78237438/python-customtkinter-and-matplotlib

db_arch = r'dbsuperseguro.json'
movimientos_arch = r'movimientos.json'

class Movimiento(customtkinter.CTkFrame):
    def __init__(self, master, atras, app):
        super().__init__(master)
        self.app = app

        self.master.title("Añadir Movimiento")
        
        self.grid_columnconfigure(0, weight=0) 
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)
        self.nombreop = customtkinter.CTkLabel(self, text="Nombre", fg_color="transparent")
        self.nombreop.grid(row=0, column=0, padx=10, pady=10, sticky="w")
        self.nombreop_i = customtkinter.CTkEntry(self, placeholder_text="Nombre para la operacion")
        self.nombreop_i.grid(row=0, column=1, padx=10, pady=10, sticky="ew")
        self.desc = customtkinter.CTkLabel(self, text="Descripcion", fg_color="transparent")
        self.desc.grid(row=1, column=0, padx=10, pady=10, sticky="w")
        self.desc_i = customtkinter.CTkEntry(self, placeholder_text="Descripcion de la transaccion")
        self.desc_i.grid(row=1, column=1, padx=10, pady=10, sticky="ew")
        self.monto = customtkinter.CTkLabel(self, text="Monto", fg_color="transparent")
        self.monto.grid(row=2, column=0, padx=10, pady=10, sticky="w")
        self.monto_i = customtkinter.CTkEntry(self, placeholder_text="Monto de la transaccion")
        self.monto_i.grid(row=2, column=1, padx=10, pady=10, sticky="ew")
        self.origen = customtkinter.CTkLabel(self, text="Origen\Destino", fg_color="transparent")
        self.origen.grid(row=3, column=0, padx=10, pady=10, sticky="w")
        self.origen_i = customtkinter.CTkEntry(self, placeholder_text="Origen de la transaccion")
        self.origen_i.grid(row=3, column=1, padx=10, pady=10, sticky="ew")
        self.anadir_b = customtkinter.CTkButton(self, text="Añadir", corner_radius=0, command=self.guardar)
        self.anadir_b.grid(row=4, column=0, columnspan=2, pady=10, padx=10)
        self.atras_b = customtkinter.CTkButton(self, text="Atrás", command=atras, corner_radius=0)
        self.atras_b.grid(row=5, column=0, columnspan=2, pady=10, padx=10)
    
    def guardar(self):
        nombre = self.nombreop_i.get()
        desc = self.desc_i.get()
        monto = self.monto_i.get()
        origen = self.origen_i.get()
        
        if nombre and desc and monto and origen:
            self.app.movimientos.append({"nombre": nombre, "desc": desc, "monto": monto, "origen": origen})
            try:
                self.app.guardar_movimientos()
            except Exception:
                pass
            messagebox.showinfo("OK", "movimiento guardado")
            self.nombreop_i.delete(0, "end")
            self.desc_i.delete(0, "end")
            self.monto_i.delete(0, "end")
            self.origen_i.delete(0, "end")
            self.app.mostrarmenuprincipal()
        else:
            messagebox.showerror("Error", "Completa todo")

class MenuPrincipal(customtkinter.CTkFrame):
    def __init__(self, master, anadirmovimiento, app):
        super().__init__(master)
        self.app = app

        self.master.title("Menu Principal")
        self.master.geometry("700x450") 

        self.grid_columnconfigure(0, weight=0) 
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)

        panel_i = customtkinter.CTkFrame(self, fg_color="transparent")
        panel_i.grid(row=0, column=0, padx=10, pady=10, sticky="nsew")

        panel_i.grid_columnconfigure(0, weight=1)  
        panel_i.grid_rowconfigure(1, weight=1)     

        movimientos_et = customtkinter.CTkLabel(panel_i, text="Movimientos", font=customtkinter.CTkFont(size=16, weight="bold"))
        movimientos_et.grid(row=0, column=0, padx=10, pady=(0, 5), sticky="w")

        movimientos_b = customtkinter.CTkButton(panel_i, text="+",  width=30, height=30, corner_radius=0, command=anadirmovimiento)
        movimientos_b.grid(row=0, column=1, padx=(0, 10), pady=(0, 5), sticky="e")

        self.panels_i = customtkinter.CTkScrollableFrame(panel_i)
        self.panels_i.grid(row=1, column=0, columnspan=2, sticky="nsew")
        
        for mov in self.app.movimientos:
            trans_b = customtkinter.CTkButton(self.panels_i, text=mov["nombre"], corner_radius=0, command=lambda m=mov: self.mostrar(m))
            trans_b.pack(fill="x", padx=5, pady=5)

        panel_d = customtkinter.CTkFrame(self)
        panel_d.grid(row=0, column=1, padx=10, pady=10, sticky="nsew")
        
        panel_d.grid_columnconfigure(0, weight=1)
        panel_d.grid_rowconfigure(0, weight=1) 
        panel_d.grid_rowconfigure(2, weight=1) 

        self.bien_et = customtkinter.CTkLabel(panel_d, text="¡Bienvenido!", font=customtkinter.CTkFont(size=24, weight="bold"))
        self.bien_et.grid(row=1, column=0, pady=10, padx=20)

        self.info_et = customtkinter.CTkLabel(panel_d, text="Selecciona un movimiento.", font=customtkinter.CTkFont(size=14), wraplength=250)
        self.info_et.grid(row=2, column=0, pady=10, padx=20, sticky="n")
        
        self.panel_d = panel_d
    
    def mostrar(self, movimiento):
        for widget in self.panel_d.winfo_children():
            widget.destroy()
        
        customtkinter.CTkLabel(self.panel_d, text="Nombre: " + movimiento["nombre"], font=("Arial", 14)).pack(pady=10)
        customtkinter.CTkLabel(self.panel_d, text="Descripcion: " + movimiento["desc"], font=("Arial", 12)).pack(pady=5)
        customtkinter.CTkLabel(self.panel_d, text="Monto: " + movimiento["monto"], font=("Arial", 12)).pack(pady=5)
        customtkinter.CTkLabel(self.panel_d, text="Origen: " + movimiento["origen"], font=("Arial", 12)).pack(pady=5)

class App(customtkinter.CTk):
    def confirmar_datos(self):
        with open(db_arch, 'r') as f:
            login = json.load(f)
            usuario_st = login.get('usuario')
            contrasena_st = login.get('contrasena')

        if self.usuario_i.get() == usuario_st and self.contrasena_i.get() == contrasena_st:
            self.mostrarmenuprincipal()

        else:
            messagebox.showerror("Atencion", "Usuario o contrasseña incorrecto/a")

    def __init__(self):
        super().__init__()
        self.bg = self.cget("fg_color")
        self.title("Finanzas")
        self.movimientos = []  

        self.geometry("400x250")
        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure(0, weight=1)
        self.ventana_actual = None 

        self.crearlogin()

    def guardar_movimientos(self):
        try:
            with open(movimientos_arch, 'w', encoding='utf-8') as f:
                json.dump(self.movimientos, f, indent=2)
        except Exception:
            pass

    def cargar_movimientos(self):
        if os.path.exists(movimientos_arch):
            try:
                with open(movimientos_arch, 'r', encoding='utf-8') as f:
                    datos = json.load(f)
                    if isinstance(datos, list):
                        self.movimientos = datos
                    else:
                        self.movimientos = []
            except Exception:
                self.movimientos = []
    
    def crearlogin(self):
        if self.ventana_actual is not None:
            self.ventana_actual.destroy()
        self.login = customtkinter.CTkFrame(self)

        self.login.grid(row=0, column=0, padx=10, pady=10)

        self.login.grid_columnconfigure(0, weight=0) 
        self.login.grid_columnconfigure(1, weight=1) 

        self.usuario_et = customtkinter.CTkLabel(self.login, text="Usuario", fg_color="transparent")
        self.usuario_et.grid(row=0, column=0, padx=10, pady=10, sticky="w")
        self.usuario_i = customtkinter.CTkEntry(self.login, placeholder_text="Miguel123")
        self.usuario_i.grid(row=0, column=1, padx=10, pady=10, sticky="ew")

        self.contrasena_et = customtkinter.CTkLabel(self.login, text="Contraseña", fg_color="transparent")
        self.contrasena_et.grid(row=1, column=0, padx=10, pady=10, sticky="w")
        self.contrasena_i = customtkinter.CTkEntry(self.login, placeholder_text="Contraseña123", show="*")
        self.contrasena_i.grid(row=1, column=1, padx=10, pady=10, sticky="ew")

        self.confir_b = customtkinter.CTkButton(self.login, text="Ingresar", corner_radius=0, command=self.confirmar_datos)
        self.confir_b.grid(row=2, column=0, columnspan=2, padx=10, pady=20, sticky="ew")
    
    def mostrarmenuprincipal(self):
        if self.ventana_actual is not None:
            self.ventana_actual.destroy()
        
        try:
            self.cargar_movimientos()
        except Exception:
            self.movimientos = []

        self.ventana_actual = MenuPrincipal(self, anadirmovimiento=self.mostraranadirmovimientos, app=self)
        self.ventana_actual.grid(row=0, column=0, sticky="nsew")

    def mostraranadirmovimientos(self):
        if self.ventana_actual is not None:
            self.ventana_actual.destroy()

        self.ventana_actual = Movimiento(self, atras=self.mostrarmenuprincipal, app=self)
        self.ventana_actual.grid(row=0, column=0, sticky="nsew")

a = App()
a.mainloop()