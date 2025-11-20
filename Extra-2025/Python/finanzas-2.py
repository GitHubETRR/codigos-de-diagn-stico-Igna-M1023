import customtkinter
import json
from tkinter import messagebox
file_path = r'C:/6Tel/codigos-de-diagn-stico-Igna-M1023/dbsuperseguro.json'

class MyCheckboxFrame(customtkinter.CTkFrame):
    def __init__(self, master):
        super().__init__(master)

        self.master.title("Menu Principal")
        self.master.geometry("700x450") 

        self.grid_columnconfigure(0, weight=0) 
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)

        left_scrollable_frame = customtkinter.CTkScrollableFrame(self, 
                                                                label_text="Movimientos",
                                                                label_font=customtkinter.CTkFont(size=16, weight="bold"))
        left_scrollable_frame.grid(row=0, column=0, padx=10, pady=10, sticky="nsew")

        for i in range(50):
            item = customtkinter.CTkLabel(left_scrollable_frame, text=f"Movimiento de ejemplo #{i+1}")
            item.pack(pady=5, padx=10, fill="x")

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

        addm = customtkinter.CTkButton(right_content_frame, text="+")
        addm.grid(row=0, column=1, columnspan=1, padx=5, pady=5, sticky="ew")

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
            print("HOLA ESTA BIEN PERO NO SE COMO PONERLO")
            self.login.destroy()
            main_menu = MyCheckboxFrame(master=self)
            main_menu.grid(row=0, column=0, sticky="nsew")

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
        self.crearlogin()
    
    def crearlogin(self):
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

        self.enter = customtkinter.CTkButton(self.login, text="Ingresar", command=self.button_callback)
        self.enter.grid(row=2, column=0, columnspan=2, padx=10, pady=20, sticky="ew")

a = App()
a.mainloop()