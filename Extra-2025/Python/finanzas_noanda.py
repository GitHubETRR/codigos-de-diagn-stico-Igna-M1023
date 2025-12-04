import customtkinter
import json
from tkinter import messagebox


##https://customtkinter.tomschimansky.com/documentation/


file_path = r'C:/6Tel/codigos-de-diagn-stico-Igna-M1023/dbsuperseguro.json'

def button_callback():
    with open(file_path, 'r') as f:
        credentials = json.load(f)
        userst = credentials.get('username')
        passwordst = credentials.get('password')

    userip = useri.get()
    passwordip = passwordi.get()

    if userip == userst and passwordip == passwordst:
        show_main_view()
    else:
        messagebox.showerror("Login Failed", "Invalid username or password")


def show_main_view():
    ## frame.destroy()

    app.title("Menu Principal")
    app.geometry("700x450") 

    app.grid_columnconfigure(0, weight=0) 
    app.grid_columnconfigure(1, weight=1)
    app.grid_rowconfigure(0, weight=1)

    left_scrollable_frame = customtkinter.CTkScrollableFrame(app, 
                                                             label_text="Movimientos",
                                                             label_font=customtkinter.CTkFont(size=16, weight="bold"))
    left_scrollable_frame.grid(row=0, column=0, padx=10, pady=10, sticky="nsew")

    for i in range(50):
        item = customtkinter.CTkLabel(left_scrollable_frame, text=f"Movimiento de ejemplo #{i+1}")
        item.pack(pady=5, padx=10, fill="x")

    right_content_frame = customtkinter.CTkFrame(app)
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

    addm = customtkinter.CTkButton(right_content_frame, text="+", command=button_callback)
    addm.grid(row=0, column=1, columnspan=1, padx=5, pady=5, sticky="ew")

app = customtkinter.CTk()
show_main_view()
'''

app.title("Finanzas")
app.geometry("400x250")

app.grid_columnconfigure(0, weight=1)
app.grid_rowconfigure(0, weight=1)

frame = customtkinter.CTkFrame(app)

frame.grid(row=0, column=0, padx=10, pady=10)

frame.grid_columnconfigure(0, weight=0) 
frame.grid_columnconfigure(1, weight=1) 

user = customtkinter.CTkLabel(frame, text="Usuario", fg_color="transparent")
user.grid(row=0, column=0, padx=10, pady=10, sticky="w")
useri = customtkinter.CTkEntry(frame, placeholder_text="Miguel123")
useri.grid(row=0, column=1, padx=10, pady=10, sticky="ew")

password = customtkinter.CTkLabel(frame, text="Contraseña", fg_color="transparent")
password.grid(row=1, column=0, padx=10, pady=10, sticky="w")
passwordi = customtkinter.CTkEntry(frame, placeholder_text="Contraseña123", show="*")
passwordi.grid(row=1, column=1, padx=10, pady=10, sticky="ew")

enter = customtkinter.CTkButton(frame, text="Ingresar", command=button_callback)
enter.grid(row=2, column=0, columnspan=2, padx=10, pady=20, sticky="ew")
'''

app.mainloop()