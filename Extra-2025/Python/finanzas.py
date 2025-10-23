import customtkinter

def button_callback():
    print("button pressed")

app = customtkinter.CTk()
app.title("my app")
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

button = customtkinter.CTkButton(frame, text="Ingresar", command=button_callback)
button.grid(row=2, column=0, columnspan=2, padx=10, pady=20, sticky="ew")


app.mainloop()