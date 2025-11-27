import customtkinter
import json
from tkinter import messagebox
file_path = r'C:/6Tel/codigos-de-diagn-stico-Igna-M1023/dbsuperseguro.json'

class Movimiento(customtkinter.CTkFrame):
    def __init__(self, master, atras):
        super().__init__(master)

        self.master.title("Añadir Movimiento")
        
        self.grid_columnconfigure(0, weight=0) 
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)
        self.nombreop = customtkinter.CTkLabel(self, text="Nombre", fg_color="transparent")
        self.nombreop.grid(row=0, column=0, padx=10, pady=10, sticky="w")
        self.nombreopi = customtkinter.CTkEntry(self, placeholder_text="Nombre para la operacion")
        self.nombreopi.grid(row=0, column=1, padx=10, pady=10, sticky="ew")
        self.desc = customtkinter.CTkLabel(self, text="Descripcion", fg_color="transparent")
        self.desc.grid(row=1, column=0, padx=10, pady=10, sticky="w")
        self.desci = customtkinter.CTkEntry(self, placeholder_text="Descripcion de la transaccion")
        self.desci.grid(row=1, column=1, padx=10, pady=10, sticky="ew")
        self.monto = customtkinter.CTkLabel(self, text="Monto", fg_color="transparent")
        self.monto.grid(row=2, column=0, padx=10, pady=10, sticky="w")
        self.montoi = customtkinter.CTkEntry(self, placeholder_text="Monto de la transaccion")
        self.montoi.grid(row=2, column=1, padx=10, pady=10, sticky="ew")
        self.origen = customtkinter.CTkLabel(self, text="Origen", fg_color="transparent")
        self.origen.grid(row=3, column=0, padx=10, pady=10, sticky="w")
        self.origeni = customtkinter.CTkEntry(self, placeholder_text="Origen de la transaccion")
        self.origeni.grid(row=3, column=1, padx=10, pady=10, sticky="ew")
        self.add_button = customtkinter.CTkButton(self, text="Añadir", corner_radius=0)
        self.add_button.grid(row=4, column=0, columnspan=2, pady=10, padx=10)
        self.atras_button = customtkinter.CTkButton(self, text="Atrás", command=atras, corner_radius=0)
        self.atras_button.grid(row=5, column=0, columnspan=2, pady=10, padx=10)

class MenuPrincipal(customtkinter.CTkFrame):
    def __init__(self, master, addmovimiento):
        super().__init__(master)

        self.master.title("Menu Principal")
        self.master.geometry("700x450") 

        self.grid_columnconfigure(0, weight=0) 
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)

        left_panel = customtkinter.CTkFrame(self, fg_color="transparent")
        left_panel.grid(row=0, column=0, padx=10, pady=10, sticky="nsew")

        left_panel.grid_columnconfigure(0, weight=1)  
        left_panel.grid_rowconfigure(1, weight=1)     

        movimientos_label = customtkinter.CTkLabel(left_panel, text="Movimientos", font=customtkinter.CTkFont(size=16, weight="bold"))
        movimientos_label.grid(row=0, column=0, padx=10, pady=(0, 5), sticky="w")

        add_movimiento_button = customtkinter.CTkButton(left_panel, text="+",  width=30, height=30, corner_radius=0, command=addmovimiento)
        add_movimiento_button.grid(row=0, column=1, padx=(0, 10), pady=(0, 5), sticky="e")

        left_scrollable_frame = customtkinter.CTkScrollableFrame(left_panel)
        left_scrollable_frame.grid(row=1, column=0, columnspan=2, sticky="nsew")

        right_content_frame = customtkinter.CTkFrame(self)
        right_content_frame.grid(row=0, column=1, padx=10, pady=10, sticky="nsew")
        
        right_content_frame.grid_columnconfigure(0, weight=1)
        right_content_frame.grid_rowconfigure(0, weight=1) 
        right_content_frame.grid_rowconfigure(2, weight=1) 

        welcome_label = customtkinter.CTkLabel(right_content_frame, 
                                            text="¡Bienvenido!",
                                            font=customtkinter.CTkFont(size=24, weight="bold"))
        welcome_label.grid(row=1, column=0, pady=10, padx=20)

        info_label = customtkinter.CTkLabel(right_content_frame, 
                                            text="Selecciona un movimiento del panel izquierdo para ver los detalles.",
                                            font=customtkinter.CTkFont(size=14))
        info_label.grid(row=2, column=0, pady=10, padx=20, sticky="n")


class App(customtkinter.CTk):

    frames = {}
    current = None
    bg = ""

    def button_callback(self):
        with open(file_path, 'r') as f:
            credentials = json.load(f)
            userst = credentials.get('username')
            passwordst = credentials.get('password')

        userip = self.useri.get()
        passwordip = self.passwordi.get()

        if userip == userst and passwordip == passwordst:
            self.mostrarmenuprincipal()

        else:
            messagebox.showerror("Login Failed", "Invalid username or password")

    def __init__(self):
        super().__init__()
        self.bg = self.cget("fg_color")
        self.num_of_frames = 0
        # self.state('withdraw')
        self.title("Finanzas")

        # screen size
        self.geometry("400x250")
        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure(0, weight=1)
        self._current_frame = None 
        self.crearlogin()
    
    def crearlogin(self):
        if self._current_frame is not None:
            self._current_frame.destroy()
        self.login = customtkinter.CTkFrame(self)

        self.login.grid(row=0, column=0, padx=10, pady=10)

        self.login.grid_columnconfigure(0, weight=0) 
        self.login.grid_columnconfigure(1, weight=1) 

        self.user = customtkinter.CTkLabel(self.login, text="Usuario", fg_color="transparent")
        self.user.grid(row=0, column=0, padx=10, pady=10, sticky="w")
        self.useri = customtkinter.CTkEntry(self.login, placeholder_text="Miguel123")
        self.useri.grid(row=0, column=1, padx=10, pady=10, sticky="ew")

        self.password = customtkinter.CTkLabel(self.login, text="Contraseña", fg_color="transparent")
        self.password.grid(row=1, column=0, padx=10, pady=10, sticky="w")
        self.passwordi = customtkinter.CTkEntry(self.login, placeholder_text="Contraseña123", show="*")
        self.passwordi.grid(row=1, column=1, padx=10, pady=10, sticky="ew")

        self.enter = customtkinter.CTkButton(self.login, text="Ingresar", corner_radius=0, command=self.button_callback)
        self.enter.grid(row=2, column=0, columnspan=2, padx=10, pady=20, sticky="ew")
    
    def mostrarmenuprincipal(self):
        if self._current_frame is not None:
            self._current_frame.destroy()
        
        self._current_frame = MenuPrincipal(self, addmovimiento=self.mostrarañadirmovimientos)
        self._current_frame.grid(row=0, column=0, sticky="nsew")

    def mostrarañadirmovimientos(self):
        if self._current_frame is not None:
            self._current_frame.destroy()

        self._current_frame = Movimiento(self, atras=self.mostrarmenuprincipal)
        self._current_frame.grid(row=0, column=0, sticky="nsew")

a = App()
a.mainloop()